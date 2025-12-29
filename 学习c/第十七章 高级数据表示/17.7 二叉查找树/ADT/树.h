#ifndef _树_H_
#define _树_H_

#include <stdbool.h>

#define 尺寸 20

typedef struct A项{
    char 宠物名[尺寸];
    char 宠物种类[尺寸];
} 项;

#define 最多项数 100

typedef struct A节点{
    项 项值;
    struct A节点 *左节点;
    struct A节点 *右节点;
} 节点;

typedef struct A树{
    节点 *根节点;
    int 项数;
} 树;

void 初始化树(树 *);

bool 树是否为空(const 树 *);

bool 树是否已满(const 树 *);

int 树的项数(const 树 *);

bool 增加项(const 项 *, 树 *);

bool 项是否存在(const 项 *, const 树 *);

bool 删除项(const 项 *, const 树 *);

void 项函数应用(const 树 *, void (*)(项));

void 删除树(树 *);

#endif