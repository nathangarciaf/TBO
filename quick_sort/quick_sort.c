#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "item.h"

#define CUTOFF 10

void insert_sort(Item *a, int lo, int hi){
    for(int i = lo+1; i <= hi; i++){
        int pos_atual = i;
        int valor_atual = a[i];
        for(int j = i - 1; j >= lo; j--){
            if(less(valor_atual, a[j])){
                a[pos_atual] = a[j];
                pos_atual--;
            }
            else{
                a[pos_atual] = valor_atual;
                break;
            }
        }
        if(pos_atual == lo){
            a[pos_atual] = valor_atual;
        }
    }
}

void shuffle(Item *a, int N) {
    struct timeval tv; gettimeofday(&tv, NULL);
    srand48(tv.tv_usec);
    for (int i = N-1; i > 0; i--) {
        int j = (unsigned int) (drand48()*(i+1));
        exch(a[i], a[j]);   
    }
}

int partition(Item *a, int lo, int hi) {
    int i = lo, j = hi+1;
    Item v = a[lo];
    while(1) {
        while (less(a[++i], v)) 
            if (i == hi) break;
        while (less(v, a[--j])) 
            if (j == lo) break;
        if (i >= j) break;
        exch(a[i], a[j]);
    }
    exch(a[lo], a[j]); 
    return j; 
}

void quick_sort_classic(Item *a, int lo, int hi) {
    if (hi <= lo) {
        return;
    }
    int j = partition(a, lo, hi);
    quick_sort_classic(a, lo, j-1);
    quick_sort_classic(a, j+1, hi);
}

void quick_sort_cutoff(Item *a, int lo, int hi) {
    if (hi <= lo + CUTOFF - 1) {
        insert_sort(a, lo, hi);
        return;
    }
    int j = partition(a, lo, hi);
    quick_sort_cutoff(a, lo, j-1);
    quick_sort_cutoff(a, j+1, hi);
}

void sort(Item *a, int lo, int hi) {
    //shuffle(a, hi-lo+1); 
    quick_sort_classic(a, lo, hi);
}