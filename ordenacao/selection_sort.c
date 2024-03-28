#include <stdio.h>
#include <stdlib.h>
#include "item.h"

extern void sort(Item *a, int lo, int hi){
    for(int i = lo; i < hi; i++){
        int menor = a[i];
        int pos = i;
        for(int j = i + 1; j <= hi; j++){
            if(less(a[j], menor)){
                pos = j;
                menor = a[j];
            }
        }
        exch(a[i],a[pos]);
    }
}