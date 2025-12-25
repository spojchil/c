#include <stdio.h>

#define MYTPE(X) _Generic((X),\
    int: "int",\
    float: "float",\
    double: "double",\
    default: "other"\
)

int main(void){
    int d = 5;

    printf("%s\n", MYTPE(++d));
    printf("%d\n", d);  // 泛型不会求值
    printf("%s\n", MYTPE(2.0*d));
    printf("%s\n", MYTPE(3L));
    printf("%s\n", MYTPE(&d));

    return 0;
}