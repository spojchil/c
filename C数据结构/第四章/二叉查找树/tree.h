#ifndef TREE_H_
#define TREE_H_

#include <stdbool.h>

// 字符串数组尺寸
#define SIZE 20

// 树节点存储的项结构
typedef struct Item {
    char pet_name[SIZE];   // 宠物名
    char pet_type[SIZE];   // 宠物种类
} Item;

// 测试用的最大项数限制
#define MAX_ITEMS 10

// 二叉树节点结构
typedef struct Node {
    Item item;             // 节点存储的项
    struct Node *left_node;// 左子节点指针
    struct Node *right_node;// 右子节点指针
} Node;

// 二叉树结构
typedef struct Tree {
    Node *root_ptr;        // 根节点指针
    int item_count;        // 树中项的总数
} Tree;

// 函数声明
void init_tree(Tree *);

bool is_tree_empty(const Tree *);

bool is_tree_full(const Tree *);

int tree_item_count(const Tree *);

bool add_item(const Item *, Tree *);

bool is_item_exist(const Item *, const Tree *);

bool delete_item(const Item *, Tree *);

void traverse_tree(const Tree *, void (*)(Item));

void destroy_tree(Tree *);

#endif // TREE_H_