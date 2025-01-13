#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include <time.h>

extern void sort1(Item *a, int lo, int hi);
extern void sort2(Item *a, int lo, int hi);
extern void sort3(Item *a, int lo, int hi);
extern void sort4(Item *a, int lo, int hi);
extern void sort5(Item *a, int lo, int hi);
extern void sort6(Item *a, int lo, int hi);
extern void sort7(Item *a, int lo, int hi);
extern void sort8(Item *a, int lo, int hi);

int main(){
    int n = 0;
    scanf("%d",&n);

    Item *array = (Item*)malloc(n*sizeof(Item));
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    clock_t start = clock();
    sort8(array, 0, n-1);
    clock_t end = clock();
    double seconds = (( double ) end - start ) / CLOCKS_PER_SEC;
    printf("time: %lf\n", seconds);

    free(array);
    return 0;
}