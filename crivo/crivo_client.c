#include <stdio.h>
#include <stdlib.h>
#include "crivo.h"

// N = 10
// INT = 1068 BYTES
// CHAR = 1035 bytes
// BIT = 


int main(){
    int i = 2, n;
    scanf("%d", &n);
    char *v= (char*)calloc(1, (n+1)*sizeof(char));

    int iter = i;
    while(iter <= n){
        for(int j = iter+1; j <= n; j++){
            if(j % iter == 0){
                item_mark(v,j);
            }
        }
        iter = next_item_find(v, iter, n);
    }
    //vec_print(v, i, n);
    vec_free(v);
}