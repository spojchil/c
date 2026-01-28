#ifndef AVLTREE_H_
#define AVLTREE_H_
#include <stdbool.h>

typedef int ElementType;
typedef struct AVLNode {
    ElementType data;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

typedef struct AVLTree {
    int size;
    int height;
    AVLNode *root;
} AVLTree;

AVLTree* create_avl_tree();
void destroy_avl_tree(AVLTree *tree);
bool insert_avl_tree(AVLTree *tree, ElementType value);
// bool delete_avl_tree(AVLTree *tree, ElementType value);
// bool search_avl_tree(AVLTree *tree, ElementType value);
#endif // AVLTREE_H_

