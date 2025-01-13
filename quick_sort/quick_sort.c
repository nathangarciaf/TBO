#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "item.h"

#define CUTOFF 100

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
    if (hi <= lo) return;
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

int median_of_3(Item *a, int lo, int hi) {
    int mid = lo + (hi - lo) / 2;

    if (less(a[hi], a[lo])) exch(a[lo], a[hi]);
    if (less(a[mid], a[lo])) exch(a[mid], a[lo]);
    if (less(a[hi], a[mid])) exch(a[mid], a[hi]);
    
    exch(a[lo], a[mid]);
    return lo;
}

void quick_sort_median_of_3(Item *a, int lo, int hi) {
    if (hi <= lo) return;
    int median = median_of_3(a, lo, hi);
    exch(a[lo], a[median]);
    int j = partition(a, lo, hi);
    quick_sort_median_of_3(a, lo, j-1);
    quick_sort_median_of_3(a, j+1, hi);
}

void quick_sort_median_of_3_cutoff(Item *a, int lo, int hi) {
    if (hi <= lo + CUTOFF - 1) {
        insert_sort(a, lo, hi);
        return;
    }

    int median = median_of_3(a, lo, hi);
    exch(a[lo], a[median]);
    int j = partition(a, lo, hi);
    quick_sort_median_of_3(a, lo, j-1);
    quick_sort_median_of_3(a, j+1, hi);
}

struct stack {
    int *a;
    int size,alloc;
};

typedef struct stack Stack; 

Stack *stack_init(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->a = (int*)malloc(sizeof(int)*20);
    s->alloc = 20;
    s->size = 0;
    return s;
}

void push(Stack *s, int a){
    if(s->alloc == s->size){
        s->alloc *2;
        s->a = (int*)realloc(s->a,sizeof(int)*s->alloc);
    }
    s->a[s->size] = a;
    s->size++;
}

void push2(Stack *s, int A, int B){
    push(s,B);
    push(s,A);
}

int stack_empty(Stack *s){
    if(s->size != 0){
        return 0;
    }
    return 1;
}

int pop(Stack *s){
    if(s->size == 0){
        exit(1);
    }
    int v = s->a[s->size-1];
    s->size--;
    return v;
}

void quick_sort_bottom_up(Item *a, int lo, int hi) {
    Stack *s = stack_init();
    push2(s,lo, hi);
    while(!stack_empty(s)) {
        lo = pop(s); hi = pop(s);
        if (hi <= lo) continue; // Could add cutoff here.

        int i = partition(a, lo, hi);
        if (i-lo > hi-i) { // Test the size of sub-arrays.
            push2(s,lo, i-1); // Push the larger one.
            push2(s,i+1, hi); // Sort the smaller one first.
        } 
        else {
            push2(s,i+1, hi);
            push2(s,lo, i-1);
        }
    }
}

void quick_sort_bottom_up_cutoff_median_of_3(Item *a, int lo, int hi) {
    Stack *s = stack_init();
    push2(s,lo, hi);
    while(!stack_empty(s)) {
        lo = pop(s); hi = pop(s);
        if (hi <= lo) continue;
        if( hi <= lo + CUTOFF - 1){
            insert_sort(a, lo, hi);
            continue;
        }

        int median = median_of_3(a, lo, hi);
        exch(a[lo], a[median]);
        int i = partition(a, lo, hi);
        if (i-lo > hi-i) { 
            push2(s,lo, i-1); 
            push2(s,i+1, hi); 
        } 
        else {
            push2(s,i+1, hi);
            push2(s,lo, i-1);
        }
    }
}

void quick_sort_3_way(Item *a, int lo, int hi) {
    if (hi <= lo) return;
    Item v = a[lo];
    int lt = lo, gt = hi, i = lo;
    while (i <= gt) {
        if (a[i] < v) {
            exch(a[lt], a[i]);
            lt++; i++;
        } 
        else if (a[i] > v) {
            exch(a[i], a[gt]);
            gt--;
        } 
        else {
            i++;
        }
    }
    quick_sort_3_way(a, lo, lt-1);
    quick_sort_3_way(a, gt+1, hi);
}

void sort1(Item *a, int lo, int hi) {
    quick_sort_classic(a, lo, hi);
}

void sort2(Item *a, int lo, int hi){
    quick_sort_cutoff(a, lo, hi);
}
void sort3(Item *a, int lo, int hi){
    quick_sort_median_of_3(a, lo, hi);
}

void sort4(Item *a, int lo, int hi){
    quick_sort_median_of_3_cutoff(a, lo, hi);
}

void sort5(Item *a, int lo, int hi){
    quick_sort_bottom_up(a, lo, hi);
}

void sort6(Item *a, int lo, int hi){
    quick_sort_bottom_up_cutoff_median_of_3(a, lo, hi);
}

void sort7(Item *a, int lo, int hi){
    shuffle(a, hi-lo+1);
    quick_sort_bottom_up_cutoff_median_of_3(a, lo, hi);
}

void sort8(Item *a, int lo, int hi){
    quick_sort_3_way(a, lo, hi);
}