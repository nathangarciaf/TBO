#include <stdio.h>
#include <stdlib.h>
#include "josefo.h"
#include <time.h>

int main(){
    int n=0, m=0, check_items=0, idx_atual=0, iter = 0;
    scanf("%d %d", &n, &m);

    int *vec = (int*)calloc(n,sizeof(int));

    clock_t start, end;
    double cpu_time_used = 0;

    while(check_items < n-1){
        while(iter < m-1){
            if(vec[idx_atual] == 0){
                //printf("IDX ATUAL: %d\n",idx_atual+1);
                iter++;
                //printf("ADD ITER\n");
            }
            idx_atual++;
            //printf("IDX PÓS ADD: %d\n",idx_atual+1);
            
            if(vec[idx_atual] == 1){
                while(vec[idx_atual] == 1){
                    idx_atual++;
                    if(idx_atual > n-1){
                        idx_atual = idx_atual - n;
                        //printf("RESTART IDX %d\n",idx_atual+1);
                    }
                }
            }

            if(idx_atual > n-1){
                idx_atual = idx_atual - n;
                //printf("RESTART IDX %d\n",idx_atual+1);
            }
        }
        //printf("IDX FINAL: %d\n",idx_atual+1);
        vec[idx_atual] = 1;
        iter = 0;
        check_items++;
        //printf("\n");
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("TIME: %f\n", cpu_time_used);
    //print_leader(vec, n);
    free(vec);
    return 0;
}