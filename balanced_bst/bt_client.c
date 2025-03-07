#include "bt.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    BinaryTree *bt = bt_construct();

    int n=1000000;
    //scanf("%d",&n);

    srand(time(NULL)); 
    for(int i = 0; i < n; i++){
        int r = rand();

        bt_rotate_insert(bt,r);
    }

    /*bt_insert(bt,20);
    bt_insert(bt,11);
    bt_insert(bt,9);
    bt_insert(bt,24);
    bt_insert(bt,15);
    bt_insert(bt,23);
    bt_rotate_insert(bt,28);*/

    clock_t start = clock();
    printf("TAM: %d\n",bt_height(bt));

    clock_t end = clock ();
    double seconds = (( double ) end - start ) / CLOCKS_PER_SEC ;

    start = clock();
    end = clock();
    printf("SIZE: %d\n", bt_size(bt));
    //bt_print(bt);

    seconds = (( double ) end - start ) / CLOCKS_PER_SEC ;
    printf ("ITER: %lf\n" , seconds );

    bt_destroy(bt);
    return 0;
}