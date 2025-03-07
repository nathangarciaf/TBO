#ifndef BT_H
#define BT_H

typedef struct BinaryTree BinaryTree;

BinaryTree *bt_construct();
int bt_height(BinaryTree *bt);
void bt_insert(BinaryTree *bt, int key);
void bt_rotate_insert(BinaryTree *bt, int key);
int bt_size(BinaryTree *bt);
void bt_destroy(BinaryTree *bt);
void bt_print(BinaryTree *bt);

void rec_visit(BinaryTree *t, void (*visit)(BinaryTree*));

void rec_bst_postorder(BinaryTree *bt);
void rec_bst_inorder(BinaryTree *bt);
void rec_bst_preorder(BinaryTree *bt);

void iter_bst_preorder(BinaryTree *bt);
void iter_bst_postorder(BinaryTree *bt);
void iter_bst_inorder(BinaryTree *bt);
void iter_bst_levelorder(BinaryTree *bt);

#endif