#include <stdio.h>

typedef struct Node Node;
typedef struct Stack Stack;

Stack *init_stack();
void push_front(Stack *s, char value);
void pop_front(Stack *s);