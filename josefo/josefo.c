#include <stdio.h>
#include <stdlib.h>
#include "josefo.h"

void print_leader(int *v, int size){
    for(int i = 0; i < size; i++){
        if(v[i] == 0){
            printf("LIDER: %d\n", i+1);
        }
    }
}