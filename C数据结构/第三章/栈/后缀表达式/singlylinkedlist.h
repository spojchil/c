#ifndef SLL_H_
#define SLL_H_
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int IntValue;

typedef IntValue SLLElem;

typedef struct Node{
    SLLElem elements;
    struct Node* next;
} SLLNode;

typedef struct{
    SLLNode *head;
    int len;
} SLL;

// 创建链表
SLL* sll_create(void);

bool sll_is_empty(const SLL* plist);

// 尾插,追加
bool sll_append(SLL* plist, const SLLElem elem);

// 插入，需要指定索引
bool sll_insert(SLL* plist, const SLLElem elem,
    const int index);

int sll_find(const SLL* plist, const SLLElem elem,
    int (*elem_cmp)(const SLLElem, const SLLElem));

// 读取返回数据
bool sll_get(const SLL* plist, const int index,
    SLLElem* pretelem);

bool sll_remove(SLL* plist, const int index);

// 应用到每个数据遍历
void sll_traverse(const SLL* plist,
    void (*pfun)(SLLElem));

bool sll_reverse(SLL* plist);

// 查找并删除特定元素
bool sll_remove_by_value(SLL* plist, 
    const SLLElem elem,
    int (*elem_cmp)(const SLLElem, const SLLElem));

// 清空链表但保持结构
void sll_clear(SLL* plist);

// 销毁单链表
void sll_destroy(SLL* plist);

#ifdef __cplusplus
}
#endif

#endif