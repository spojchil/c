#include <stdio.h>
#include "queue.h"

int main(void){
    Queue line;
    Item temp;
    char ch;

    InitializeQueue(&line);
    puts("测试队列结构,请输入a增加一个数值");
    puts("输入d删除一个值，输入q退出");
    while ((ch = getchar()) != 'q'){
        if (ch != 'a' && ch != 'd') continue;
        if (ch == 'a'){
            printf("增加一个整数:");
            scanf("%d", &temp);
            if (!QueueIsFull(&line)){
                printf("正在增加%d到队列中\n", temp);
                EnQueue(temp, &line);
            }
            else puts("队列已满");
        }
        else {
            if (QueueIsEmpty(&line))
                puts("队列为空");
            else {
                DeQueue(&temp, &line);
                printf("正在从队列中移除 %d\n", temp);
            }
        }
        printf("队列中还有%d个项\n", QueueItemCount(&line));
        puts("输入a增加,d删除,q退出");
    }
    EmptyTheQueue(&line);
    puts("Bye!");

    return 0;
}
