#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "树.h"

typedef struct A对节点{
    节点 *父节点;
    节点 *目标节点;
    bool 是左节点;
} 对节点;

void 初始化树(树 *树指针){
    树指针->根节点 = NULL;
    树指针->项数 = 0;
}

bool 树是否为空(const 树 *树指针){
    if (树指针->根节点 == NULL)
        return true;
    return false;
}
static bool 去左边(const 项 *, const 项 *);

static bool 去左边(const 项 *项指针, const 项 *树中项){
    int 比较值;
    
    if ((比较值 = strcmp(项指针->宠物名, 树中项->宠物名)) < 0)
        return true;
    else if (比较值 == 0 && strcmp(项指针->宠物种类, 树中项->宠物种类) < 0)
        return true;
    else
        return false;
}

static bool 去右边(const 项 *, const 项 *);

static bool 去右边(const 项 *项指针, const 项 *树中项){
    int 比较值;
    
    if ((比较值 = strcmp(项指针->宠物名, 树中项->宠物名)) > 0)
        return true;
    else if (比较值 == 0 && strcmp(项指针->宠物种类, 树中项->宠物种类) > 0)
        return true;
    else
        return false;
}

static 对节点 项查找(const 项 *项指针, const 树 *树指针){
    对节点 目标 = {NULL, 树指针->根节点};

    if (目标.目标节点 == NULL)
        return 目标;

    while (目标.目标节点 != NULL){
        if (去左边(项指针, &(目标.目标节点->项值))){
            目标.父节点 = 目标.目标节点;
            目标.目标节点 = 目标.目标节点->左节点;
            目标.是左节点 = true;
        }
        else if (去右边(项指针, &(目标.目标节点->项值))){
            目标.父节点 = 目标.目标节点;
            目标.目标节点 = 目标.目标节点->右节点;
            目标.是左节点 = false;
        }
        else
            break;
    }
    
    return 目标;
}

bool 项是否存在(const 项 *项指针, const 树 *树指针){
    return (项查找(项指针, 树指针).目标节点 == NULL ? false : true);
}

int 树的项数(const 树 *树指针){
    return 树指针->项数;
}

static 节点 *创建新节点(const 项 *项指针);

static 节点 *创建新节点(const 项 *项指针){
    节点 *新节点 = malloc(sizeof(节点));

    if (新节点 != NULL){
        新节点->项值 = *项指针;
        新节点->左节点 = NULL;
        新节点->右节点 = NULL;
    }

    return 新节点;
}

bool 树是否已满(const 树 *树指针){
    if (树指针->项数 >= 最多项数)
        return true;
    return false;
}

bool 增加项(const 项 *项指针, 树 *树指针){
    if (树是否已满(树指针)){
        fprintf(stderr, "树已满\n");
        return false;
    }

    对节点 临时对 = 项查找(项指针, 树指针);
    if (临时对.目标节点 != NULL){
        fprintf(stderr, "项已存在\n");
        return false;
    }

    节点 *新节点 = 创建新节点(项指针);
    if (新节点 == NULL){
        fprintf(stderr, "内存分配失败\n");
        return false;
    }
    if (树是否为空(树指针))
        树指针->根节点 = 新节点;
    else if (临时对.是左节点)
        临时对.父节点->左节点 = 新节点;
    else 
        临时对.父节点->右节点 = 新节点;

    return true;
}

static 对节点 寻找最小节点(节点 *节点指针);

static 对节点 寻找最小节点(节点 *节点指针){
    对节点 目标 = {NULL, 节点指针, true};

    while (目标.目标节点->左节点 != NULL){
        目标.父节点 = 目标.目标节点;
        目标.目标节点 = 目标.目标节点->左节点;
    }

    return 目标;
}

static void 删除节点(对节点 *对指针, 树 *树指针);

static void 删除节点(对节点 *对指针, 树 *树指针){
    
    if (对指针->目标节点->左节点 == NULL){
        if (对指针->是左节点)
            对指针->父节点->左节点 = 对指针->目标节点->右节点;
        else
            对指针->父节点->右节点 = 对指针->目标节点->右节点;
    }
    else if (对指针->目标节点->右节点 == NULL){
        if (对指针->是左节点)
            对指针->父节点->左节点 = 对指针->目标节点->左节点;
        else
            对指针->父节点->右节点 = 对指针->目标节点->左节点;
    }
    else {
        // 传入右子树
        对节点 临时对 = 寻找最小节点(对指针->目标节点->右节点);

        // 右子树的根节点就是最小节点
        if (临时对.父节点 == NULL){
            // 值复制或许更简单一点
            if (对指针->是左节点)
                对指针->父节点->左节点 = 临时对.目标节点;
            else
                对指针->父节点->右节点 = 临时对.目标节点;
            // 将原来的左子树接在原来的右子树的根节点的左边
            临时对.目标节点->左节点 = 对指针->目标节点->左节点;

        }
        else {
            if (对指针->是左节点)
                对指针->父节点->左节点 = 临时对.目标节点;
            else 
                对指针->父节点->右节点 = 临时对.目标节点;
            临时对.父节点->左节点 = 临时对.目标节点->右节点;
            临时对.目标节点->右节点 = 对指针->目标节点->右节点;
            临时对.目标节点->左节点 = 对指针->目标节点->左节点;
        }
    }
    free(对指针->目标节点);
}