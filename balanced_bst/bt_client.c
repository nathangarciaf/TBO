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

    clock_t start = clock ();
    printf("TAM: %d\n",bt_height(bt));

    clock_t end = clock ();
    double seconds = (( double ) end - start ) / CLOCKS_PER_SEC ;

    start = clock();
    rec_visit(bt,rec_bst_inorder);
    end = clock();

    seconds = (( double ) end - start ) / CLOCKS_PER_SEC ;
    printf ("ITER: %lf\n" , seconds );

    //bt_print(bt);
    bt_destroy(bt);
    return 0;
}