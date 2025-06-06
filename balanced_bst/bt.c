#include <stdlib.h>
#include <stdio.h>
#include "bt.h"

typedef struct Node Node;
typedef struct queue Queue;

struct Node
{
    Node *left;
    Node *right;
    int key;
};

Node *node_construct(int key){
    Node *n = (Node*)calloc(1,sizeof(Node));
    n->left = n->right = NULL;
    n->key = key;
    return n;
}

Node* node_insert(Node *n, int key) {
    if (!n) 
        return node_construct(key);

    if (n->key > key) 
        n->left = node_insert(n->left, key);
    else 
        n->right = node_insert(n->right, key);
    
    return n; 
}

Node* rotate_right(Node *n) {
    Node *t = n->left;
    n->left = t->right;
    t->right = n;
    return t;
}

Node* rotate_left(Node *n) {
    Node *t = n->right;
    n->right = t->left;
    t->left = n;
    return t;
}

Node* node_rotate_insert(Node *n, int key) {
    if (!n) {
        return node_construct(key);
    }

    if(n->key > key) {
        n->left = node_rotate_insert(n->left, key);
        if (n->left) 
            n = rotate_right(n);
    } 
    else {
        n->right = node_rotate_insert(n->right, key);
        if (n->right) 
            n = rotate_left(n);
    }

    return n; 
}

void node_destroy(Node *n){
    if(n != NULL){
        node_destroy(n->left);
        node_destroy(n->right);
        free(n);
    }
}

int node_height(Node* root) {
    if (!root)
        return -1;

    int left_height = node_height(root->left);
    int right_height = node_height(root->right);

    if(left_height > right_height)
        return left_height + 1;
    return right_height + 1;
}

void rec_node_postorder(Node *root)
{
    if(!root)
        return;
    rec_node_postorder(root->left);
    rec_node_postorder(root->right);
    printf("%d\n",root->key);
    
}

void rec_node_preorder(Node *root)
{
    if(!root)
        return;
    printf("%d\n",root->key);
    rec_node_preorder(root->left);
    rec_node_preorder(root->right);
    
}

void rec_node_inorder(Node *root)
{
    if(!root)
        return;

    rec_node_inorder(root->left);
    printf("%d\n",root->key);
    rec_node_inorder(root->right);
}

struct BinaryTree
{
    Node *root;
    int size;
};

BinaryTree *bt_construct()
{
    BinaryTree *bt = (BinaryTree*)calloc(1,sizeof(BinaryTree));
    bt->root = NULL;
    bt->size = 0;
    return bt;
}

void rec_visit(BinaryTree *t, void (*visit)(BinaryTree*)){
    visit(t);
}

void rec_bst_preorder(BinaryTree *bt)
{
    rec_node_preorder(bt->root);
}

void rec_bst_inorder(BinaryTree *bt)
{
    rec_node_inorder(bt->root);
}

void rec_bst_postorder(BinaryTree *bt)
{
    rec_node_postorder(bt->root);
}

int bt_height(BinaryTree *bt) {
    if (!bt->root)
        return -1;
    return node_height(bt->root);
}

void bt_insert(BinaryTree *bst, int key) {
    bst->root = node_insert(bst->root, key);
    bst->size++;
}

void bt_rotate_insert(BinaryTree *bst, int key) {
    bst->root = node_rotate_insert(bst->root, key);
    bst->size++;
}

int bt_size(BinaryTree *bt){
    return bt->size;
}

void bt_destroy(BinaryTree *bt)
{
    node_destroy(bt->root);
    free(bt);
}

void bt_print(BinaryTree *bt)
{   
    rec_bst_preorder(bt);
}

typedef struct tad_node TAD_Node;

struct tad_node {
    TAD_Node *next;

    Node *bst_node;
};

TAD_Node *tad_node_create(Node *bst_node){
    TAD_Node *n = (TAD_Node*)malloc(sizeof(TAD_Node));
    n->bst_node = bst_node;
    n->next = NULL;
    return n;
}

void tad_node_free(TAD_Node *n, int size){
    while(size != 0){
        TAD_Node *next = n->next;
        free(n);
        size--;
    }
    return;
}

struct queue
{
    TAD_Node *first, *last;
    int size;
};

Queue *queue_init(){
    Queue *q = (Queue*)calloc(1,sizeof(Queue));
    q->first = NULL;
    q->last = NULL;
    q->size = 0;
    return q;
}

void queue_push(Queue *q, Node *n){
    TAD_Node *tn = tad_node_create(n);
    if(!q->first)
        q->first = tn;
    else{
        q->last->next = tn;
    }
    q->last = tn;
    q->size++;
}

Node *queue_pop(Queue *q){
    if(q->size == 1){
        TAD_Node *n = q->first;
        q->first = q->last = NULL;
        q->size--;
        Node *bst_node = n->bst_node;
        free(n);
        return bst_node;
    }

    TAD_Node *n = q->first;
    while(n->next != q->last && n->next){
        n = n->next;
    }
    q->size--;
    n->next = NULL;
    Node *bst_node = q->last->bst_node;
    free(q->last);
    q->last = n;
    return bst_node;
}

Node *queue_pop_front(Queue *q){
    TAD_Node *n = q->first;
    if(!n)
        return NULL;
    if(n == q->last){
        q->first = q->last = NULL;
    }
    else{
        q->first = n->next;
    }
    q->size--;
    Node *bst_node = n->bst_node;
    free(n);
    return bst_node;
}

int queue_empty(Queue *q){
    if(q->size != 0)
        return 0;
    return 1;
}

Node *queue_peek(Queue *q){
    return q->last->bst_node;
}

void queue_free(Queue *q){
    if(q->size != 0)
        tad_node_free(q->first, q->size);
    free(q);
}

void iter_bst_preorder(BinaryTree *bt){
    Node *root = bt->root;
    if(!root)
        return;
    Queue *q = queue_init();
    queue_push(q,root);
    while(!queue_empty(q)){
        Node *n = queue_pop(q);
        //printf("%d\n",n->key);
        if(n->right){
            queue_push(q,n->right);
        }
        if(n->left){
            queue_push(q,n->left);
        }
    }
    queue_free(q);
}

void iter_bst_postorder(BinaryTree *bt){
    Node *n = bt->root;
    if(!n)
        return;
    Queue *q = queue_init();
    Node *last_node = NULL;
    while(!queue_empty(q) || n != NULL){
        if(n != NULL){
            queue_push(q,n);
            n = n->left;
        }
        else{
            Node *peek_node = queue_peek(q);
            if(peek_node->right != NULL && last_node != peek_node->right){
                n = peek_node->right;
            }
            else{
                //printf("%d\n", peek_node->key);
                last_node = queue_pop(q);
            }
        }
    }
}

void iter_bst_inorder(BinaryTree *bt){
    Node *root = bt->root;
    if(!root)
        return;
    Queue *q = queue_init();
    Node *n = root;
    while(!queue_empty(q) || n != NULL){
        
        if(n){
            queue_push(q, n);
            n = n->left;
        }
        else{
            n = queue_pop(q);
            //printf("%d\n",n->key);
            n = n->right;
        }
    }
    queue_free(q);
}

void iter_bst_levelorder(BinaryTree *bt){
    Node *n = bt->root;
    Queue *q = queue_init();
    queue_push(q,n);
    while(!queue_empty(q)){
        n = queue_pop_front(q);
        printf("%d\n",n->key);
        if(n->left)
            queue_push(q,n->left);
        if(n->right)
            queue_push(q,n->right);
    }
    queue_free(q);
}