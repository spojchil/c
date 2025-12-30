#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_VALUE 999999  // 随机数的最大值
#define COUNT_SIZE 1000000  // 计数数组大小（MAX_VALUE + 1）

void xuanze_optimized(int size);

int main(void) {
    time_t start, end;
    double time_used;
    int size;
    
    printf("当前系统的RAND_MAX = %d\n", RAND_MAX);
    
    srand(time(NULL));
    
    printf("请输入要生成随机数的数量: ");
    scanf("%d", &size);
    
    if(size <= 0) {
        printf("数量必须大于0！\n");
        return 1;
    }
    
    printf("注意：此版本使用计数方法，可处理大数量数据但值范围有限\n");
    printf("随机数范围: 0 ~ %d\n", MAX_VALUE);
    
    start = time(NULL);
    xuanze_optimized(size);
    end = time(NULL);
    
    time_used = difftime(end, start);
    printf("程序运行时间: %.2f 秒\n", time_used);
    
    return 0;
}

// 优化的选择函数，使用计数方法
void xuanze_optimized(int size) {
    // 使用计数数组，每个值记录该随机数出现的次数
    int* count = (int*)calloc(COUNT_SIZE, sizeof(int));
    if(count == NULL) {
        printf("无法分配计数数组！\n");
        return;
    }
    
    printf("已分配计数数组（%.2f MB）\n", 
           (double)COUNT_SIZE * sizeof(int) / (1024.0 * 1024.0));
    
    printf("\n正在生成 %d 个随机数并统计...\n", size);
    
    long long large_random = 0;
    int value = 0;
    int k = size / 2;  // 要找第k大的数
    
    // 生成随机数并计数
    for(int i = 0; i < size; i++) {
        // 生成随机数
        large_random = (long long)rand() << 16 | rand();
        value = (int)(large_random % (MAX_VALUE + 1));
        
        // 计数
        count[value]++;
        
        // 显示进度
        if(i % 10000000 == 0 && i > 0) {
            printf("已生成 %d/%d 个随机数 (%.1f%%)\n", 
                   i, size, (double)i / size * 100);
        }
    }
    
    printf("随机数生成和统计完成！\n");
    printf("寻找第 %d 大的数（k = N/2，其中N=%d）\n", k, size);
    
    // 通过累计计数找到第k大的数
    int cumulative_count = 0;
    int kth_largest = -1;
    
    // 从最大值开始向下累加
    for(int i = MAX_VALUE; i >= 0; i--) {
        cumulative_count += count[i];
        if(cumulative_count >= k) {
            kth_largest = i;
            break;
        }
    }
    
    printf("\n找到第 %d 大的数: %d\n", k, kth_largest);
    
    // 统计信息
    int min_val = MAX_VALUE + 1;
    int max_val = -1;
    long long sum = 0;
    long long actual_count = 0;
    
    for(int i = 0; i <= MAX_VALUE; i++) {
        if(count[i] > 0) {
            if(i < min_val) min_val = i;
            if(i > max_val) max_val = i;
            sum += (long long)i * count[i];
            actual_count += count[i];
        }
    }
    
    // 验证总数
    if(actual_count != size) {
        printf("警告：实际统计数量(%lld)与目标数量(%d)不一致！\n", 
               actual_count, size);
    }
    
    double average = (double)sum / actual_count;
    
    printf("\n随机数统计信息:\n");
    printf("最小值: %d\n", min_val);
    printf("最大值: %d\n", max_val);
    printf("平均值: %.2f\n", average);
    printf("中位数(第%d大): %d\n", k, kth_largest);
    
    // 计算有多少个数小于、等于、大于中位数
    int less_count = 0, equal_count = 0, greater_count = 0;
    
    for(int i = 0; i < kth_largest; i++) {
        less_count += count[i];
    }
    equal_count = count[kth_largest];
    for(int i = kth_largest + 1; i <= MAX_VALUE; i++) {
        greater_count += count[i];
    }
    
    printf("小于中位数的数: %d 个 (%.2f%%)\n", 
           less_count, (double)less_count / size * 100);
    printf("等于中位数的数: %d 个 (%.2f%%)\n", 
           equal_count, (double)equal_count / size * 100);
    printf("大于中位数的数: %d 个 (%.2f%%)\n", 
           greater_count, (double)greater_count / size * 100);
    
    // 显示分布情况
    printf("\n分布情况（每10万为一个区间）:\n");
    int intervals = 10;  // 分成10个区间显示
    int interval_size = MAX_VALUE / intervals;
    
    for(int i = 0; i < intervals; i++) {
        int start = i * interval_size;
        int end = (i + 1) * interval_size - 1;
        if(i == intervals - 1) end = MAX_VALUE;
        
        int interval_count = 0;
        for(int j = start; j <= end; j++) {
            interval_count += count[j];
        }
        
        printf("[%6d-%6d]: %8d 个 (%.2f%%)\n", 
               start, end, interval_count, 
               (double)interval_count / size * 100);
    }
    
    // 释放内存
    free(count);
}