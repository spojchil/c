#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bin_heap.h"

// 辅助函数：打印堆的内容
void print_heap(bin_heap_t heap) {
    printf("堆状态: 容量=%d, 大小=%d\n", heap->capacity, heap->size);
    printf("堆元素: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

// 测试堆创建和销毁
void test_create_destroy() {
    printf("==== 测试1: 堆创建和销毁 ====\n");
    
    bin_heap_t heap = bin_heap_create(10);
    assert(heap != NULL);
    assert(heap->capacity == 10);
    assert(heap->size == 0);
    assert(heap->data != NULL);
    
    printf("创建成功: 容量=%d, 大小=%d\n", heap->capacity, heap->size);
    
    bin_heap_destroy(heap);
    printf("销毁成功\n\n");
}

// 测试空堆判断
void test_empty() {
    printf("==== 测试2: 空堆判断 ====\n");
    
    bin_heap_t heap = bin_heap_create(5);
    
    // 测试空堆
    assert(bin_heap_is_empty(heap) == 1);
    printf("空堆判断: 正确\n");
    
    // 插入一个元素后测试非空
    bin_heap_insert(heap, 10);
    assert(bin_heap_is_empty(heap) == 0);
    printf("非空堆判断: 正确\n");
    
    // 删除元素后变空
    Elem elem;
    bin_heap_remove_min(heap, &elem);
    assert(bin_heap_is_empty(heap) == 1);
    printf("删除后变空: 正确\n");
    
    bin_heap_destroy(heap);
    printf("\n");
}

// 测试满堆判断
void test_full() {
    printf("==== 测试3: 满堆判断 ====\n");
    
    bin_heap_t heap = bin_heap_create(3);
    
    // 初始不为满
    assert(bin_heap_is_full(heap) == 0);
    printf("初始堆未满: 正确\n");
    
    // 插入元素直到满
    bin_heap_insert(heap, 5);
    bin_heap_insert(heap, 3);
    bin_heap_insert(heap, 7);
    
    assert(bin_heap_is_full(heap) == 1);
    printf("堆满判断: 正确\n");
    
    // 删除一个元素后不满
    Elem elem;
    bin_heap_remove_min(heap, &elem);
    assert(bin_heap_is_full(heap) == 0);
    printf("删除后不满: 正确\n");
    
    bin_heap_destroy(heap);
    printf("\n");
}

// 测试插入操作
void test_insert() {
    printf("==== 测试4: 插入操作 ====\n");
    
    bin_heap_t heap = bin_heap_create(5);
    
    // 测试插入返回值
    assert(bin_heap_insert(heap, 10) == 0); // 假设成功返回0
    assert(heap->size == 1);
    printf("插入1个元素: 成功\n");
    
    assert(bin_heap_insert(heap, 5) == 0);
    assert(heap->size == 2);
    printf("插入2个元素: 成功\n");
    
    assert(bin_heap_insert(heap, 15) == 0);
    assert(bin_heap_insert(heap, 3) == 0);
    assert(bin_heap_insert(heap, 8) == 0);
    assert(heap->size == 5);
    printf("插入5个元素: 成功\n");
    
    // 测试堆满时插入
    assert(bin_heap_insert(heap, 20) != 0); // 应该失败
    assert(heap->size == 5);
    printf("满堆插入失败: 正确\n");
    
    print_heap(heap);
    bin_heap_destroy(heap);
    printf("\n");
}

// 测试查找最小值
void test_find_min() {
    printf("==== 测试5: 查找最小值 ====\n");
    
    bin_heap_t heap = bin_heap_create(5);
    Elem min_val;
    
    // 空堆查找应该失败
    assert(bin_heap_find_min(heap, &min_val) != 0);
    printf("空堆查找失败: 正确\n");
    
    // 插入测试数据
    bin_heap_insert(heap, 10);
    bin_heap_insert(heap, 5);
    bin_heap_insert(heap, 15);
    bin_heap_insert(heap, 3);
    bin_heap_insert(heap, 8);
    
    // 查找最小值
    assert(bin_heap_find_min(heap, &min_val) == 0);
    assert(min_val == 3); // 堆的最小值应该是3
    printf("找到最小值: %d\n", min_val);
    
    print_heap(heap);
    bin_heap_destroy(heap);
    printf("\n");
}

// 测试删除最小值
void test_remove_min() {
    printf("==== 测试6: 删除最小值 ====\n");
    
    bin_heap_t heap = bin_heap_create(5);
    Elem elem;
    
    // 空堆删除应该失败
    assert(bin_heap_remove_min(heap, &elem) != 0);
    printf("空堆删除失败: 正确\n");
    
    // 插入测试数据
    bin_heap_insert(heap, 10);
    bin_heap_insert(heap, 5);
    bin_heap_insert(heap, 15);
    bin_heap_insert(heap, 3);
    bin_heap_insert(heap, 8);
    
    printf("初始堆:\n");
    print_heap(heap);
    
    // 依次删除最小值
    int expected[] = {3, 5, 8, 10, 15};
    for (int i = 0; i < 5; i++) {
        assert(bin_heap_remove_min(heap, &elem) == 0);
        assert(elem == expected[i]);
        printf("删除第%d个最小值: %d (期望: %d)\n", i+1, elem, expected[i]);
        printf("删除后堆大小: %d\n", heap->size);
    }
    
    // 删除完应该为空
    assert(bin_heap_is_empty(heap) == 1);
    printf("删除后堆为空: 正确\n");
    
    bin_heap_destroy(heap);
    printf("\n");
}

// 综合测试
void test_integration() {
    printf("==== 测试7: 综合测试 ====\n");
    
    bin_heap_t heap = bin_heap_create(10);
    Elem elem;
    
    // 随机插入
    int test_data[] = {45, 12, 67, 23, 89, 34, 56, 78, 90, 1};
    for (int i = 0; i < 10; i++) {
        bin_heap_insert(heap, test_data[i]);
    }
    
    printf("插入10个元素后:\n");
    print_heap(heap);
    
    // 验证堆属性
    assert(bin_heap_find_min(heap, &elem) == 0);
    printf("当前最小值: %d\n", elem);
    
    // 有序删除
    printf("按序删除元素:\n");
    int last_min = -1;
    while (!bin_heap_is_empty(heap)) {
        bin_heap_remove_min(heap, &elem);
        printf("%d ", elem);
        if (last_min != -1) {
            assert(elem >= last_min); // 验证有序性
        }
        last_min = elem;
    }
    printf("\n删除完成，堆已空\n");
    
    bin_heap_destroy(heap);
    printf("\n");
}

int main() {
    printf("开始测试二叉堆实现...\n\n");
    
    // 运行各个测试
    test_create_destroy();
    test_empty();
    test_full();
    test_insert();
    test_find_min();
    test_remove_min();
    test_integration();
    
    printf("所有测试通过！\n");
    return 0;
}