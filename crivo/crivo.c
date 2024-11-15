#include "crivo.h"

void vec_print(char *v, int start, int final){
    int iter = start;
    while(iter <= final){
        if(v[iter] == 0){
            printf("%d\n", iter);
        }
        iter++;
    }
}

void vec_free(char *v){
    free(v);
}

int next_item_find_char(char *v, int i, int size){
    for(int j = i+1; j <= size; j++){
        if(v[j] != 'x'){
            return j;
        }
    }
    return size+1;
}

int next_item_find_int(int *v, int i, int size){
    for(int j = i+1; j <= size; j++){
        if(v[j] != 1){
            return j;
        }
    }
    return size+1;
}

void item_mark_char(char *v, int i){
    v[i] = 'x';
}

void item_mark_int(int *v, int i){
    v[i] = 1;
}