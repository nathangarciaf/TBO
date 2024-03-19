#include <stdlib.h>
#include <stdio.h>
#include "dijkstra.h"

struct Node
{
    Node *next;
    char value;
};

struct Stack
{
    Node *topo;
    int size;
};

Stack *init_stack(){
    Stack *s = (Stack*)calloc(1,sizeof(Stack));
    s->size = 0;
    s->topo = NULL;
    return s;
}

void push_front(Stack *s, char value){

}

void pop_front(Stack *s){

}