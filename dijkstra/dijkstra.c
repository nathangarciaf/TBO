#include <stdlib.h>
#include <stdio.h>
#include "dijkstra.h"

struct Node
{
    Node *next;
    void *value;
};

struct Stack
{
    Node *head;
    int size;
};

Node *init_node(Node* next, void *v){
    Node *n = (Node*)calloc(1, sizeof(Node));
    n->value = v;
    n->next = next;
}

Stack *init_stack(){
    Stack *s = (Stack*)calloc(1,sizeof(Stack));
    s->size = 0;
    s->head = NULL;
    return s;
}

void push_front(Stack *s, void *value){
    if(s->head != NULL){
        Node *n = s->head;
        Node *node = init_node(n,value);
        s->head = node;
    }
    else{
        Node *node = init_node(NULL,value);
        s->head = node;
    }
}

Node *pop_front(Stack *s){
    Node *head = s->head;
    Node *new_head = head->next;
    s->head = new_head;

    return head;
}