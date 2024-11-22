#include <stdlib.h>
#include <stdio.h>
#include "bt.h"

typedef struct Node Node;
typedef struct Stack Stack;

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

void node_insert(Node *n, int key){
    if(n->key > key){
        if(!n->left)
            n->left = node_construct(key);
        else
            node_insert(n->left,key);  
    }
    else {
        if(!n->right)
            n->right = node_construct(key);
        else
            node_insert(n->right,key);  
    }
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
        return 0;
    else {
        int left_height = node_height(root->left);
        int right_height = node_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
    return -1;
}

void rec_bst_preorder(Node *root)
{
    if(root != NULL){
        printf("%d\n",root->key);
        rec_bst_preorder(root->left);
        rec_bst_preorder(root->right);
    }
}

void rec_bst_inorder(Node *root)
{
    if(root != NULL){
        rec_bst_inorder(root->left);
        printf("%d\n",root->key);
        rec_bst_inorder(root->right);
    }
}

void rec_bst_postorder(Node *root){
    if(root != NULL){
        rec_bst_postorder(root->left);
        rec_bst_postorder(root->right);
        printf("%d\n",root->key);
    }
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

void iter_preorder(){

}

void iter_postorder(){

}

void iter_inorder(Node *root, int size){
    /*Stack *s = stack_init(size);
    stack_push(s,root);
    Node *curr_node = root->left;
    while(!stack_empty(s)){

    }*/
}

int bt_height(BinaryTree *bt)
{
    int height = 0;
    if(bt->size == 0){
        return -1;
    }
    else if(bt->size == 1){
        return 0;
    }
    return node_height(bt->root) - 1; 
}

void bst_insert(BinaryTree *bst, int key){
    if(!bst->root){
        bst->root = node_construct(key);
    }
    else{
        //printf("NODE INSERT: %d\n", key);
        node_insert(bst->root,key);
    }
    bst->size++;
}

void bt_insert(BinaryTree *bt, int key)
{
    if(bt->root != NULL){
        Node *n = node_construct(key);
        Node *root = bt->root;
        Node *iter = root;

        while(iter != NULL){
            if(iter->key < n->key){
                if(iter->right != NULL){
                    iter = iter->right;
                }
                else{
                    iter->right = n;
                    iter = NULL;
                }
            }
            else if(iter->key > n->key){
                if(iter->left != NULL){
                    iter = iter->left;
                }
                else{
                    iter->left = n;
                    iter = NULL;
                }
            }
        }
    }
    else{
        bt->root = node_construct(key);
    }
    bt->size++;
}

void bt_destroy(BinaryTree *bt)
{
    node_destroy(bt->root);
    free(bt);
}

void bt_print(BinaryTree *bt)
{   
    rec_bst_preorder(bt->root);
}

struct Stack
{
    Node **vec_node;
    int first;
    int size;
};

Stack *stack_init(int size){
    Stack *s = (Stack*)calloc(1,sizeof(Stack));
    s->vec_node = (Node**)calloc(size,sizeof(Node*));
    for(int i = 0; i < s->size;i++){
        s->vec_node[i] = NULL;
    }
    s->size = 0;
    s->first = 0;
    return s;
}

void stack_push(Stack *s, Node *n){
    if(s->size != 0){
        s->vec_node[s->first] = n;
        s->first++;
    }
}

Node *stack_pop(Stack *s){
    s->first--;
    Node *removed = s->vec_node[s->first];
    s->vec_node[s->first] = NULL;
    return removed;
}

int stack_empty(Stack *s){
    if(s->size != 0)
        return 0;
    return 1;
}

void stack_free(Stack *s){
    free(s->vec_node);
    free(s);
}