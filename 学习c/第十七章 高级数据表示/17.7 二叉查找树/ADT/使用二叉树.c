#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "树.h"

char 菜单(void);
void 增加宠物(树 *);
void 删除宠物(树 *);
void 展示宠物(const 树 *);
void 寻找宠物(const 树 *);
void 打印条目(项);
void 大写字母(char *str);
char *s_gets(char *, int);

int main(void){
    树 宠物;
    char 选择;

    初始化树(&宠物);
    while ((选择 = 菜单()) != 'q'){
        switch (选择){
            case 'a': 增加宠物(&宠物); break;
            case 'l': 展示宠物(&宠物); break;
            case 'f': 寻找宠物(&宠物); break;
            case 'n': printf("%d 只宠物在数中\n", 树的项数(&宠物));
                break;
            case 'd': 删除宠物(&宠物); break;
            default : puts("选择错误");
        }
    }
    删除树(&宠物);
    puts("结束");

    return 0;
}

char 菜单(void){
    int ch;

    puts("宠物记录项目");
    puts("请输入你的选择");
    puts("a) 增加宠物       l) 展示列表");
    puts("n) 宠物数量       f) 查询宠物");
    puts("d) 删除宠物       q) 退出");
    while ((ch = getchar()) != EOF){
        while (getchar() != '\n') continue;
        ch = tolower(ch);
        if (strchr("alrfndq", ch) == NULL)
            puts("请输入一个a,l,f,n,d或者q");
        else break;
    }
    if (ch == EOF)
        ch = 'q';

    return ch;
}

void 增加宠物(树 *树指针){
    项 临时项;

    if (树是否已满(树指针))
        puts("无法创建更多条目");
    else {
        puts("请输入你的宠物名");
        s_gets(临时项.宠物名, 尺寸);
        puts("请输入你的宠物类型");
        s_gets(临时项.宠物种类, 尺寸);
        大写字母(临时项.宠物名);
        大写字母(临时项.宠物种类);
        增加项(&临时项, 树指针);
    }
}

void 展示宠物(const 树 *树指针){
    if (树是否为空(树指针))
        puts("树为空");
    else 
        项函数应用(树指针, 打印条目);
}

void 打印条目(项 项值){
    printf("宠物 %-19s 种类 %-19s\n", 项值.宠物名, 项值.宠物种类);
}

void 寻找宠物(const 树 *树指针){
    项 临时项;

    if (树是否为空(树指针)){
        puts("无");
        return;
    }

    puts("请输入你希望查找的宠物名");
    s_gets(临时项.宠物名, 尺寸);
    puts("请输入你的宠物类型");
    s_gets(临时项.宠物种类, 尺寸);
    大写字母(临时项.宠物名);
    大写字母(临时项.宠物种类);
    printf("%s 的种类是 %s\n", 临时项.宠物名, 临时项.宠物种类);
    if (项是否存在(&临时项, 树指针))
        printf("存在该项\n");
    else
        printf("不存在\n");
}

void 删除宠物(树 *树指针){
    项 临时项;
    
    if (树是否为空(树指针)){
        puts("树为空");
        return;
    }

    puts("请输入你希望删除的宠物名");
    s_gets(临时项.宠物名, 尺寸);
    puts("请输入你的宠物类型");
    s_gets(临时项.宠物种类, 尺寸);
    大写字母(临时项.宠物名);
    大写字母(临时项.宠物种类);
    printf("%s 的种类是 %s\n", 临时项.宠物名, 临时项.宠物种类);
    if (删除项(&临时项, 树指针))
        printf("已经删除该项\n");
    else
        printf("不存在\n");
}

void 大写字母(char *str){
    while (*str){
        *str = toupper(*str);
        str++;
    }
}

