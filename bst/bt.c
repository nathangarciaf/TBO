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

int node_height(Node *n, int height){
    int h = height;
    if(n != NULL){
        int h_left = h;
        if(n->left != NULL){
            h_left++;
            int h_left = node_height(n->left,h_left);
        }
        
        int h_right = h;
        if(n->right != NULL){
            h_right++;
            int h_right = node_height(n->right,h_right);
        }

        if(h_left > h_right){
            h = h_left;
        }
        else{
            h = h_right;
        }
    }
    return (h);
}

void node_preorder(Node *n)
{
    if(n != NULL){
        printf("%d\n",n->key);
        node_preorder(n->left);
        node_preorder(n->right);
    }
}

void node_inorder(Node *n)
{
    if(n != NULL){
        node_inorder(n->left);
        printf("%d\n",n->key);
        node_inorder(n->right);
    }
}

void node_postorder(Node *n){
    if(n != NULL){
        node_postorder(n->left);
        node_postorder(n->right);
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

int bt_height(BinaryTree *bt)
{
    int height = 0;
    if(bt->size == 0){
        return -1;
    }
    else if(bt->size == 1){
        return 0;
    }
    else{
        height = node_height(bt->root,0);
    }
    return height;
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
    node_preorder(bt->root);
}

struct Stack
{
    Node *vec_node[50];
    int first;
    int size;
};