#include <stdio.h>
#include <stdlib.h>
#include "item.h"

extern void sort(Item *a, int lo, int hi){
    for(int i = lo; i < hi; i++){
        for(int j = i + 1; j <= hi; j++){
            compexch(a[i],a[j]);
        }
    }
}