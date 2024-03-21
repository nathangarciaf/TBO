#include <stdlib.h>
#include <stdio.h>
#include "bt.h"

typedef struct Node Node;

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

void node_destroy(Node *n){
    if(n != NULL){
        node_destroy(n->left);
        node_destroy(n->right);
        free(n);
    }
}

void node_print(Node *n)
{
    if(n != NULL){
        node_print(n->left);
        node_print(n->right);
        printf("%d\n",n->key);
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
    node_print(bt->root);
}
