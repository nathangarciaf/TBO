#ifndef BT_H
#define BT_H

typedef struct BinaryTree BinaryTree;

BinaryTree *bt_construct();
void bt_insert(BinaryTree *bt, int key);
void bt_destroy(BinaryTree *bt);
void bt_print(BinaryTree *bt);

#endif