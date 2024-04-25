#include <stdio.h>
#include <stdlib.h>
#include "item.h"

extern void sort(Item *a, int lo, int hi);

int main(){
    int n = 0;
    scanf("%d",&n);

    Item *array = (Item*)calloc(n,sizeof(Item));
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    sort(array, 0, n-1);

    printf("\nVETOR: ");
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}