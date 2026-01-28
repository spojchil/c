#include "avltree.h"
#include <stdlib.h>
#include <stdio.h>

// 创建一个新的AVL树
AVLTree* create_avl_tree() {
    AVLTree *tree = (AVLTree *)malloc(sizeof(AVLTree));
    if (tree != NULL) {
        tree->size = 0;
        tree->height = 0;
        tree->root = NULL;
    }
    return tree;
}

// 销毁AVL树及其所有节点
static void destroy_avl_nodes(AVLNode *node) {
    if (node != NULL) {
        destroy_avl_nodes(node->left);
        destroy_avl_nodes(node->right);
        free(node);
    }
}

void destroy_avl_tree(AVLTree *tree) {
    if (tree != NULL) {
        destroy_avl_nodes(tree->root);
        free(tree);
    }
}

// 插入值到AVL树

static int get_height(AVLNode *node) {
    return node ? node->height : -1;
}

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static AVLNode* single_rotate_left(AVLNode *k2) {
    AVLNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(get_height(k2->left), get_height(k2->right)) + 1;
    k1->height = max(get_height(k1->left), k2->height)
    + 1;
    return k1;
}

static AVLNode* single_rotate_right(AVLNode *k1) {
    AVLNode *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(get_height(k1->left), get_height(k1->right)) + 1;
    k2->height = max(get_height(k2->right), k1->height)
    + 1;
    return k2;
}

static AVLNode* double_rotate_left(AVLNode *k3) {
    k3->left = single_rotate_right(k3->left);
    return single_rotate_left(k3);
}

static AVLNode* double_rotate_right(AVLNode *k1) {
    k1->right = single_rotate_left(k1->right);
    return single_rotate_right(k1);
}

static AVLNode* insert_subtree(AVLNode *node, ElementType value){
    if (node == NULL) {
        AVLNode *new_node = (AVLNode *)malloc(sizeof(AVLNode));
        if (new_node == NULL) return NULL;
        new_node->data = value;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->height = 0;
        return new_node;
    }
    if (value < node->data) {
        node->left = insert_subtree(node->left, value);
        if (get_height(node->left) - get_height(node->right) == 2) {
            if (value < node->left->data)
                node = single_rotate_left(node);
            else
                node = double_rotate_left(node);
        }
    } else if (value > node->data) {
        node->right = insert_subtree(node->right, value);
        if (get_height(node->right) - get_height(node->left) == 2) {
            if (value > node->right->data)
                node = single_rotate_right(node);
            else
                node = double_rotate_right(node);
        }
    } else {
        // Duplicate value, do nothing
        return node;
    }

    // Update height
    node->height = 1 + max(get_height(node->left), get_height(node->right));
}


bool insert_avl_tree(AVLTree *tree, ElementType value) {
    if (tree->root == NULL) {
        AVLNode *new_node = (AVLNode *)malloc(sizeof(AVLNode));
        if (new_node == NULL) return false;
        new_node->data = value;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->height = 0;
        tree->root = new_node;
        tree->size++;
        return true;
    }
    tree->root = insert_subtree(tree->root, value);
    tree->size++;
    return true;
}