#ifndef BT_H
#define BT_H

typedef struct BinaryTree BinaryTree;

BinaryTree *bt_construct();
int bt_height(BinaryTree *bt);
void bt_insert(BinaryTree *bt, int key);
void bst_insert(BinaryTree *bt, int key);
void bt_destroy(BinaryTree *bt);
void bt_print(BinaryTree *bt);

void rec_preorder(BinaryTree *t, void (*visit)(BinaryTree*));

#endif