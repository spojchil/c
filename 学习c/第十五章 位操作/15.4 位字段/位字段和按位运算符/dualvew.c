#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// 边框线样式
#define SOLID 0
#define DOTTED 1
#define DASHED 2

// 三原色
#define BLUE 4
#define GREEN 2
#define RED 1

// 混合颜色
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

// 位方法中的宏常量
#define OPAQUE 0x1
#define FILL_BLUE 0X8
#define FILL_GREEN 0X4
#define FILL_RED 0X2
#define FILL_MASK 0XE
#define BORDER 0X100
#define BORDER_BLUE 0X800

#define BORDER_GREEN 0X400
#define BORDER_RED0X 200
#define BORDER_MASK 0XE00
#define B_SOLLD 0
#define B_DOTTED 0X1000
#define B_DASHED 0X2000
#define STYLE_MASK0X 3000

const char * colors[8] = {"black", "red", "green", "yellow", "blue", "magenta",
"cyan", "white"};

struct box_props {
    bool opaque : 1;
    unsigned int fill_color : 3;
    unsigned int : 4;
    bool show_border : 1;
    unsigned int border_color : 3;
    unsigned int border_style : 2;
    unsigned int : 2;
};

union Views{
    struct box_props st_view;
    unsigned short us_view;
};

void show_settings(const struct box_props *pb);
void show_settings1(unsigned short);
char *itobs(int n, char *ps);

int main(void){
    // 创建联合,并初始化
    union Views box = {{true, YELLOW, true, GREEN, DASHED}};
    char bin_str[8 * sizeof(unsigned int) + 1];

    printf("Original box settings:\n");
    show_settings(&box.st_view);
    printf("\nBox settings using unsigned int view:\n");
    show_settings1(box.us_view);
    printf("bits are %s\n",
        itobs(box.us_view, bin_str));

    return 0;
}

void show_settings(const struct box_props *pb){
    printf("Box is %s.\n",
        pb->opaque == true ? "opaque" : "transparent");
    printf("The fill color is %s. \n", colors[pb->fill_color]);
    printf("Border %s.\n",
        pb->show_border == true ? "shown" : "not shown");
    printf("The border color is %s.\n", colors[pb->border_color]);
    printf("The border style is ");
    switch (pb->border_style){
        case SOLID: printf("solid.\n"); break;
        case DOTTED: printf("dotted.\n"); break;
        case DASHED: printf("dasher.\n"); break;
    }
}

void show_settings1(unsigned short us){
    printf("box is %s.\n",
        (us & OPAQUE) == OPAQUE ? "opaque" : "transparent");
    printf("The fill color is %s.\n",
        colors[(us >> 1) & 07]);
    printf("Border %s.\n",
            (us & BORDER) == BORDER ? "shown" : "not shown");
    printf("The border style is ");
    switch (us & STYLE_MASK0X){
        case B_SOLLD : printf("solid.\n"); break;
        case B_DOTTED : printf("dotted.\n"); break;
        case B_DASHED : printf("dashed.\n"); break;
        default : printf("unknow type.\n");
    }
    printf("The border color is %s.\n",
        colors[(us >> 9) & 07]);
}

char * itobs(int n, char * ps){
    int i;
    const static int size = CHAR_BIT * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}