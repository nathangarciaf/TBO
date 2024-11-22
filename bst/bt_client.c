#include "bt.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    BinaryTree *bt = bt_construct();

    //int n=0;
    //scanf("%d",&n);

    srand(time(NULL)); 
    for(int i = 0; i < 1000000; i++){
        int r = rand();

        bst_insert(bt,r);
    }


    printf("TAM: %d\n",bt_height(bt));

    clock_t start = clock ();


    clock_t end = clock ();
    double seconds = (( double ) end - start ) / CLOCKS_PER_SEC ;
    printf ("%lf\n" , seconds );

    //bt_print(bt);
    bt_destroy(bt);
    return 0;
}