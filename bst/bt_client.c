#include "bt.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    BinaryTree *bt = bt_construct();

    int n=10000000;
    //scanf("%d",&n);

    srand(time(NULL)); 
    for(int i = 0; i < n; i++){
        int r = rand();

        bst_insert(bt,r);
    }

    /*bst_insert(bt,20);
    bst_insert(bt,11);
    bst_insert(bt,9);
    bst_insert(bt,24);
    bst_insert(bt,15);*/

    clock_t start = clock ();
    printf("TAM: %d\n",bt_height(bt));

    clock_t end = clock ();
    double seconds = (( double ) end - start ) / CLOCKS_PER_SEC ;
    /*printf ("%lf\n" , seconds );

    start = clock();
    rec_visit(bt,rec_bst_postorder);
    end = clock();

    seconds = (( double ) end - start ) / CLOCKS_PER_SEC ;
    printf ("RECURSIVE: %lf\n" , seconds );*/

    start = clock();
    rec_visit(bt,iter_bst_levelorder);
    end = clock();

    seconds = (( double ) end - start ) / CLOCKS_PER_SEC ;
    printf ("ITER: %lf\n" , seconds );

    //bt_print(bt);
    bt_destroy(bt);
    return 0;
}