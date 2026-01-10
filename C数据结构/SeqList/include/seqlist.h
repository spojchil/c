#ifndef SEQLIST_H_
#define SEQLIST_H_
#include <stdbool.h>

// 业务数据类型
typedef int IntType;

// 顺序表元素类型
typedef IntType SeqListElem;

// 线性表
#define SEQ_LIST_DEFAULT_CAP 5
typedef struct{
    SeqListElem* elements;
    int len;
    int cap;
} SeqList;

// 给已经声明的线性表初始化
void seq_list_init(SeqList *plist);

// 检测表是否已满
bool seq_list_is_full(const SeqList* plist);

// 检测表是否为空
bool seq_list_is_empty(const SeqList* plist);

// 追加元素
bool seq_list_append(SeqList* plist, const SeqListElem* elem);

// 插入元素
bool seq_list_insert(SeqList* plist, const SeqListElem* elem,
     const int index);

// 设置元素
bool seq_list_set(SeqList* plist, const SeqListElem* elem, const int index);

// 查找元素
int seq_list_find(const SeqList* plist,const SeqListElem* elem,
     int (*elem_cmp)(const SeqListElem* elem1,
        const SeqListElem* elem2));

// 读取元素，不使用返回指针的写法，因为那个写法不安全也破坏了封装性
bool seq_list_get(const SeqList* plist, const int index,
     SeqListElem* value);

// 删除元素,根据索引
bool seq_list_remove(SeqList* plist, const int index);

// 应用函数到每个元素，遍历
void seq_list_traverse(const SeqList* plist,
     void (*pfun)(int index, SeqListElem));

// 返回线性表的项树
int seq_list_lenght(const SeqList* plist);

// 销毁线性表
void seq_list_destroy(SeqList* plist);

// 清空
void seq_list_clear(SeqList* plist);

#endif