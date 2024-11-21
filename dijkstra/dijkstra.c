#include <stdlib.h>
#include <stdio.h>
#include "dijkstra.h"

#define TAM 5

struct double_stack {
    double *stack;
    int size, alloc;
};

struct char_stack {
    char *stack;
    int size, alloc;
};

DS *double_stack_init(){
    DS *s = (DS*)calloc(1,sizeof(DS));
    s->size = 0;
    s->alloc = TAM;
    s->stack = (double*)calloc(TAM, sizeof(double));
    return s;
}

CS *char_stack_init(){
    CS *s = (CS*)calloc(1,sizeof(CS));
    s->size = 0;
    s->alloc = TAM;
    s->stack = (char*)calloc(TAM, sizeof(char));
    return s;
}

void double_stack_push(DS *s, double d){
    if(s->size == s->alloc){
        s->alloc *= 2;
        s->stack = (double*)realloc(s->stack,s->alloc * sizeof(double));
    }
    s->stack[s->size] = d;
    s->size++;
}

double double_stack_pop(DS *s){
    s->size--;
    return s->stack[s->size];
}

void char_stack_push(CS *s, char c){
    if(s->size == s->alloc){
        s->alloc *= 2;
        s->stack = (char*)realloc(s->stack,s->alloc * sizeof(char));
    }
    s->stack[s->size] = c;
    s->size++;
}

char char_stack_pop(CS *s){
    s->size--;
    return s->stack[s->size];
}

void double_stack_free(DS *s){
    free(s->stack);
    free(s);
}

void char_stack_free(CS *s){
    free(s->stack);
    free(s);
}