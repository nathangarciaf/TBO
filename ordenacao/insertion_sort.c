#include <stdio.h>
#include <stdlib.h>
#include "item.h"

extern void sort(Item *a, int lo, int hi){
    for(int i = lo; i < hi; i++){
        int valor = a[i+1];
        int pos_valor = a[i+1];
        for(int j = i; j > lo; j--){
            if(less(valor, a[j])){
                
            }
            else{
                break;
            }
        }
    }
}