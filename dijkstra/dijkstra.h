typedef struct Node Node;
typedef struct Stack Stack;

Stack *init_stack();
void push_front(Stack *s, void *value);
Node *pop_front(Stack *s);