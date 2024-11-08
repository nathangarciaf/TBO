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
    return node_height(bt->root) - 1; 
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