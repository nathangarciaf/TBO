#include <stdio.h>
#include <stdlib.h>
#include "crivo.h"
#include <time.h>


int main(){
    int i = 2, n;
    scanf("%d", &n);
    char *v= (char*)calloc(1, (n+1)*sizeof(char));
    //int *v= (int*)calloc((n+1), sizeof(int));

    clock_t start, end;
    double cpu_time_used = 0;
     
    start = clock();

    int iter = i;
    while(iter <= n){
        for(int j = iter+1; j <= n; j++){
            if(j % iter == 0){
                item_mark_char(v,j);
                //item_mark_int(v,j);
            }
        }
        iter = next_item_find_char(v, iter, n);
        //iter = next_item_find_int(v, iter, n);
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    //vec_print(v, i, n);
    printf("TIME: %f\n", cpu_time_used);
    free(v);
}