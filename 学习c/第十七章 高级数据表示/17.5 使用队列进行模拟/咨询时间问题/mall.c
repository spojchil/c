#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#define MIN_PER_HR 60.0

bool newcustomer(double x);
Item customertime(long when);

int main(void){
    Queue line;
    Item temp;
    int hours;
    int perhour;
    long cycle, cyclelimit;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    double min_per_cust;
    long line_wait = 0;

    InitializeQueue(&line);
    srand((unsigned int) time(0));
    puts("案例研究: SL的案例咨询台");
    puts("请输入模拟的小时数:");
    while (scanf("%d", &hours) != 1){
        puts("请重新输入一个整数");
        while (getchar() != '\n') continue;
    }
    cyclelimit = MIN_PER_HR * hours;
    puts("请输入平均每小时多少顾客");
    while (scanf("%d", &perhour) != 1){
        puts("请重新输入一个整数");
        while (getchar() != '\n') continue;
    }
    min_per_cust = MIN_PER_HR / perhour;
    for (cycle = 0; cycle < cyclelimit; cycle++){
        if (newcustomer(min_per_cust)){
            if (QueueIsFull(&line))
                turnaways++;
            else {
                customers++;
                temp = customertime(cycle);
                EnQueue(temp, &line);
            }
        }
        if (wait_time <= 0 && !QueueIsEmpty(&line)){
            DeQueue(&temp, &line);
            wait_time = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += QueueItemCount(&line);
    }
    if (customers > 0){
        printf("接受了%ld个顾客\n", customers);
        printf("  服务了%ld个顾客\n", served);
        printf("    队列满后拒绝了%ld个顾客\n", turnaways);
        printf("平均等待长度: %.2f\n",
            (double) sum_line / cyclelimit);
        printf("  平均等待时间 %.2f 分钟\n",
            (double) line_wait / served);
        
    }
    else puts("没有顾客");
    EmptyTheQueue(&line);
    puts("Bye!");

    return 0;
}

bool newcustomer(double x){
    if (rand() * x / RAND_MAX < 1)
        return true;
    else return false;
}

Item customertime(long when){
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}
