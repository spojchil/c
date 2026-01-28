#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#include <assert.h>

// 辅助结构体：存储目标节点、其父节点、以及是否是左子节点
typedef struct NodePair {
    Node *parent_node;   // 父节点
    Node *target_node;   // 目标节点
    bool is_left_node;   // 是否是左子节点
} NodePair;

// 初始化二叉树
void init_tree(Tree *tree_ptr) {
    tree_ptr->root_ptr = NULL;
    tree_ptr->item_count = 0;
}

// 判断树是否为空
bool is_tree_empty(const Tree *tree_ptr) {
    if (tree_ptr->root_ptr == NULL)
        return true;
    return false;
}

// 内部函数：判断新项是否应该插入到当前节点的左侧
static bool go_left(const Item *item_ptr, const Item *tree_item);

static bool go_left(const Item *item_ptr, const Item *tree_item) {
    int cmp_val;
    
    if ((cmp_val = strcmp(item_ptr->pet_name, tree_item->pet_name)) < 0)
        return true;
    else if (cmp_val == 0 && strcmp(item_ptr->pet_type, tree_item->pet_type) < 0)
        return true;
    else
        return false;
}

// 内部函数：判断新项是否应该插入到当前节点的右侧
static bool go_right(const Item *item_ptr, const Item *tree_item);

static bool go_right(const Item *item_ptr, const Item *tree_item) {
    int cmp_val;
    
    if ((cmp_val = strcmp(item_ptr->pet_name, tree_item->pet_name)) > 0)
        return true;
    else if (cmp_val == 0 && strcmp(item_ptr->pet_type, tree_item->pet_type) > 0)
        return true;
    else
        return false;
}

// 内部函数：查找指定项在树中的位置（返回节点对）
static NodePair find_item(const Item *item_ptr, const Tree *tree_ptr) {
    // 初始化：父节点为NULL，目标节点为根节点
    NodePair target = {NULL, tree_ptr->root_ptr, false};

    if (target.target_node == NULL)
        return target;

    while (target.target_node != NULL) {
        if (go_left(item_ptr, &(target.target_node->item))) {
            target.parent_node = target.target_node;
            target.target_node = target.target_node->left_node;
            target.is_left_node = true;
        }
        else if (go_right(item_ptr, &(target.target_node->item))) {
            target.parent_node = target.target_node;
            target.target_node = target.target_node->right_node;
            target.is_left_node = false;
        }
        else
            break; // 找到匹配项，退出循环
    }

    return target;
}

// 判断指定项是否存在于树中
bool is_item_exist(const Item *item_ptr, const Tree *tree_ptr) {
    return (find_item(item_ptr, tree_ptr).target_node == NULL ? false : true);
}

// 获取树中项的总数
int tree_item_count(const Tree *tree_ptr) {
    return tree_ptr->item_count;
}

// 内部函数：创建新节点并初始化
static Node *create_new_node(const Item *item_ptr);

static Node *create_new_node(const Item *item_ptr) {
    Node *new_node = malloc(sizeof(Node));

    if (new_node != NULL) {
        new_node->item = *item_ptr;
        new_node->left_node = NULL;
        new_node->right_node = NULL;
    }

    return new_node;
}

// 判断树是否已满（测试阶段用数量限制，发布阶段可改为内存检测）
bool is_tree_full(const Tree *tree_ptr) {
    // 测试时：按最大项数判断
    if (tree_ptr->item_count >= MAX_ITEMS)
        return true;
    // 发表时：修改为检测内存分配
    return false;
}

// 向树中添加新项
bool add_item(const Item *item_ptr, Tree *tree_ptr) {
    if (is_tree_empty(tree_ptr)) {
        Node *new_node = create_new_node(item_ptr);
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return false;
        }
        tree_ptr->root_ptr = new_node;
        tree_ptr->item_count++;
        return true;
    }
    
    if (is_tree_full(tree_ptr)) {
        fprintf(stderr, "Tree is full\n");
        return false;
    }

    NodePair temp_pair = find_item(item_ptr, tree_ptr);
    if (temp_pair.target_node != NULL) {
        fprintf(stderr, "Item already exists\n");
        return false;
    }

    Node *new_node = create_new_node(item_ptr);
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return false;
    }

    if (temp_pair.is_left_node)
        temp_pair.parent_node->left_node = new_node;
    else 
        temp_pair.parent_node->right_node = new_node;

    tree_ptr->item_count++;
    return true;
}

// 内部函数：查找指定节点子树中的最小节点
static NodePair find_min_node(Node *node_ptr);

static NodePair find_min_node(Node *node_ptr) {
    // 断言：传入的节点指针不能为空
    assert(node_ptr != NULL && "find_min_node: input pointer is NULL");

    NodePair target = {NULL, node_ptr};

    // 循环查找最左侧节点（二叉搜索树最小值）
    while (target.target_node->left_node != NULL) {
        target.parent_node = target.target_node;
        target.target_node = target.target_node->left_node;
    }

    return target;
}

// 内部函数：删除非根节点的子节点
static void delete_child_node(NodePair *pair_ptr, Tree *tree_ptr);

static void delete_child_node(NodePair *pair_ptr, Tree *tree_ptr) {
    if (pair_ptr->target_node->left_node == NULL) {
        if (pair_ptr->is_left_node)
            pair_ptr->parent_node->left_node = pair_ptr->target_node->right_node;
        else
            pair_ptr->parent_node->right_node = pair_ptr->target_node->right_node;
    }
    else if (pair_ptr->target_node->right_node == NULL) {
        if (pair_ptr->is_left_node)
            pair_ptr->parent_node->left_node = pair_ptr->target_node->left_node;
        else
            pair_ptr->parent_node->right_node = pair_ptr->target_node->left_node;
    }
    else {
        // 查找右子树的最小节点（替换节点）
        NodePair temp_pair = find_min_node(pair_ptr->target_node->right_node);

        // 右子树的根节点就是最小节点
        if (temp_pair.parent_node == NULL) {
            if (pair_ptr->is_left_node)
                pair_ptr->parent_node->left_node = temp_pair.target_node;
            else
                pair_ptr->parent_node->right_node = temp_pair.target_node;
            // 将原节点的左子树挂载到替换节点的左侧
            temp_pair.target_node->left_node = pair_ptr->target_node->left_node;

        }
        else {
            if (pair_ptr->is_left_node)
                pair_ptr->parent_node->left_node = temp_pair.target_node;
            else 
                pair_ptr->parent_node->right_node = temp_pair.target_node;
            temp_pair.parent_node->left_node = temp_pair.target_node->right_node;
            temp_pair.target_node->right_node = pair_ptr->target_node->right_node;
            temp_pair.target_node->left_node = pair_ptr->target_node->left_node;
        }
    }
    free(pair_ptr->target_node);
}

// 内部函数：删除根节点
static void delete_root_node(Tree *tree_ptr);

static void delete_root_node(Tree *tree_ptr) {
    if (tree_ptr->root_ptr->right_node == NULL) {
        Node *temp = tree_ptr->root_ptr;
        tree_ptr->root_ptr = tree_ptr->root_ptr->left_node;
        free(temp);
        return;
    }
    NodePair temp_pair = find_min_node(tree_ptr->root_ptr->right_node);
    if (temp_pair.parent_node == NULL) {
        temp_pair.target_node->left_node = tree_ptr->root_ptr->left_node;
        free(tree_ptr->root_ptr);
        tree_ptr->root_ptr = temp_pair.target_node;
    }
    else {
        temp_pair.parent_node->left_node = temp_pair.target_node->right_node;
        temp_pair.target_node->left_node = tree_ptr->root_ptr->left_node;
        temp_pair.target_node->right_node = tree_ptr->root_ptr->right_node;
        free(tree_ptr->root_ptr);
        tree_ptr->root_ptr = temp_pair.target_node;
    }
}

// 从树中删除指定项
bool delete_item(const Item *item_ptr, Tree *tree_ptr) {
    if (is_tree_empty(tree_ptr)) {
        fprintf(stderr, "Tree is empty\n");
        return false;
    }
    NodePair temp_pair = find_item(item_ptr, tree_ptr);
    if (temp_pair.target_node == NULL) {
        fprintf(stderr, "Item does not exist\n");
        return false;
    }
    if (temp_pair.parent_node == NULL) {
        delete_root_node(tree_ptr);
        tree_ptr->item_count--;
        return true;
    }
    delete_child_node(&temp_pair, tree_ptr);
    tree_ptr->item_count--;
    
    return true;
}

// 内部函数：中序遍历树并对每个项应用指定函数
static void in_order_traversal(const Node *node_ptr, void (*item_func)(Item));

static void in_order_traversal(const Node *node_ptr, void (*item_func)(Item)) {
    if (node_ptr != NULL) {
        in_order_traversal(node_ptr->left_node, item_func);
        item_func(node_ptr->item);
        in_order_traversal(node_ptr->right_node, item_func);
    }
}

// 遍历树并对每个项应用指定函数（对外接口）
void traverse_tree(const Tree *tree_ptr, void (*item_func)(Item)) {
    if (tree_ptr != NULL)
        in_order_traversal(tree_ptr->root_ptr, item_func);
}

// 内部函数：递归删除所有节点
static void delete_all_nodes(Node *node_ptr) {
    if (node_ptr != NULL) {
        delete_all_nodes(node_ptr->left_node);
        delete_all_nodes(node_ptr->right_node);
        free(node_ptr);
    }
}

// 销毁整个树（释放所有内存）
void destroy_tree(Tree *tree_ptr) {
    delete_all_nodes(tree_ptr->root_ptr);
    tree_ptr->root_ptr = NULL;
    tree_ptr->item_count = 0;
}