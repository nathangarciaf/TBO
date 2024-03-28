#include <stdio.h>
#include <stdlib.h>
#include "item.h"

extern void sort(Item *a, int lo, int hi){
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
            printf("POS ATUAL: %d\n",pos_atual);
        }
        if(pos_atual == lo){
            a[pos_atual] = valor_atual;
        }
    }
}