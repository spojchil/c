#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define TEST_PASS() printf("✓ 测试通过\n\n")
#define TEST_FAIL(msg) printf("✗ 测试失败: %s\n\n", msg)

/* 测试工具函数 */
static void print_test_header(const char* test_name) {
    printf("====================\n");
    printf("测试: %s\n", test_name);
    printf("====================\n");
}

/* 1. 基本功能测试 */
static void test_basic_operations(void) {
    print_test_header("基本操作测试");
    
    Stack* stack = stack_create();
    if (!stack) {
        printf("❌ 栈创建失败\n");
        return;
    }
    
    // 测试空栈
    printf("1. 空栈测试...\n");
    if (!stack_is_empty(stack)) {
        TEST_FAIL("新创建的栈应为空");
        return;
    }
    
    int value;
    if (stack_top(stack, &value)) {
        TEST_FAIL("空栈获取栈顶元素应失败");
        return;
    }
    
    // 测试单元素入栈出栈
    printf("2. 单元素测试...\n");
    if (!stack_push(stack, 42)) {
        TEST_FAIL("入栈失败");
        return;
    }
    
    if (stack_is_empty(stack)) {
        TEST_FAIL("有元素的栈不应为空");
        return;
    }
    
    if (!stack_top(stack, &value) || value != 42) {
        TEST_FAIL("栈顶元素应为42");
        return;
    }
    
    if (!stack_pop(stack, &value) || value != 42) {
        TEST_FAIL("出栈元素应为42");
        return;
    }
    
    if (!stack_is_empty(stack)) {
        TEST_FAIL("元素出栈后栈应为空");
        return;
    }
    
    TEST_PASS();
    stack_destroy(stack);
}

/* 2. 多元素顺序测试 */
static void test_multiple_elements(void) {
    print_test_header("多元素顺序测试");
    
    Stack* stack = stack_create();
    if (!stack) {
        printf("❌ 栈创建失败\n");
        return;
    }
    
    // 入栈多个元素
    printf("入栈元素: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", i);
        if (!stack_push(stack, i)) {
            printf("\n❌ 入栈失败\n");
            stack_destroy(stack);
            return;
        }
    }
    printf("\n");
    
    // 测试LIFO顺序
    printf("出栈顺序: ");
    int expected = 9;
    while (!stack_is_empty(stack)) {
        int value;
        if (!stack_pop(stack, &value)) {
            printf("\n❌ 出栈失败\n");
            stack_destroy(stack);
            return;
        }
        printf("%d ", value);
        
        if (value != expected) {
            printf("\n❌ 顺序错误，期望 %d，得到 %d\n", expected, value);
            stack_destroy(stack);
            return;
        }
        expected--;
    }
    printf("\n");
    
    if (expected != -1) {
        TEST_FAIL("出栈元素数量不正确");
        stack_destroy(stack);
        return;
    }
    
    TEST_PASS();
    stack_destroy(stack);
}

/* 3. 边界条件测试 */
static void test_edge_cases(void) {
    print_test_header("边界条件测试");
    
    Stack* stack = stack_create();
    if (!stack) {
        printf("❌ 栈创建失败\n");
        return;
    }
    
    printf("1. 空栈出栈测试...\n");
    int value;
    if (stack_pop(stack, &value)) {
        TEST_FAIL("空栈出栈应失败");
        stack_destroy(stack);
        return;
    }
    
    printf("2. 空指针参数测试...\n");
    // 测试NULL指针参数
    if (stack_is_empty(NULL)) {
        TEST_FAIL("传入NULL指针应安全处理");
        stack_destroy(stack);
        return;
    }
    
    if (stack_push(NULL, 1)) {
        TEST_FAIL("传入NULL指针应安全处理");
        stack_destroy(stack);
        return;
    }
    
    if (stack_pop(NULL, &value)) {
        TEST_FAIL("传入NULL指针应安全处理");
        stack_destroy(stack);
        return;
    }
    
    if (stack_pop(stack, NULL)) {
        TEST_FAIL("传出参数为NULL应安全处理");
        stack_destroy(stack);
        return;
    }
    
    printf("3. 多次销毁测试...\n");
    stack_destroy(stack);
    stack_destroy(NULL);  // 应该能安全处理
    
    TEST_PASS();
}

/* 4. 内存和性能测试 */
static void test_memory_and_performance(void) {
    print_test_header("内存和性能测试");
    
    Stack* stack = stack_create();
    if (!stack) {
        printf("❌ 栈创建失败\n");
        return;
    }
    
    const int LARGE_COUNT = 10000;
    printf("1. 大数据量测试 (%d个元素)...\n", LARGE_COUNT);
    
    // 大量入栈
    for (int i = 0; i < LARGE_COUNT; i++) {
        if (!stack_push(stack, i)) {
            printf("❌ 第 %d 个元素入栈失败\n", i);
            stack_destroy(stack);
            return;
        }
    }
    
    // 验证栈顶
    int top_value;
    if (!stack_top(stack, &top_value) || top_value != LARGE_COUNT - 1) {
        TEST_FAIL("栈顶元素不正确");
        stack_destroy(stack);
        return;
    }
    
    // 全部出栈
    int count = 0;
    while (!stack_is_empty(stack)) {
        int value;
        if (!stack_pop(stack, &value)) {
            printf("❌ 第 %d 个元素出栈失败\n", count);
            stack_destroy(stack);
            return;
        }
        
        // 验证顺序
        if (value != LARGE_COUNT - 1 - count) {
            printf("❌ 顺序错误，期望 %d，得到 %d\n", 
                   LARGE_COUNT - 1 - count, value);
            stack_destroy(stack);
            return;
        }
        count++;
    }
    
    if (count != LARGE_COUNT) {
        TEST_FAIL("出栈数量不正确");
        stack_destroy(stack);
        return;
    }
    
    printf("2. 多次创建销毁测试...\n");
    for (int i = 0; i < 100; i++) {
        Stack* temp_stack = stack_create();
        if (!temp_stack) {
            printf("❌ 第 %d 次创建失败\n", i);
            return;
        }
        stack_push(temp_stack, i);
        stack_destroy(temp_stack);
    }
    
    TEST_PASS();
    stack_destroy(stack);
}

/* 5. 混合操作测试 */
static void test_mixed_operations(void) {
    print_test_header("混合操作测试");
    
    Stack* stack = stack_create();
    if (!stack) {
        printf("❌ 栈创建失败\n");
        return;
    }
    
    printf("执行混合操作...\n");
    
    // 交替进行push和pop
    for (int i = 0; i < 5; i++) {
        stack_push(stack, i);
        
        int value;
        if (i % 2 == 0) {
            stack_top(stack, &value);
            printf("  栈顶: %d\n", value);
        }
    }
    
    // 部分出栈
    printf("部分出栈: ");
    for (int i = 0; i < 3; i++) {
        int value;
        stack_pop(stack, &value);
        printf("%d ", value);
    }
    printf("\n");
    
    // 再次入栈
    printf("再次入栈: ");
    for (int i = 10; i < 15; i++) {
        stack_push(stack, i);
        printf("%d ", i);
    }
    printf("\n");
    
    // 验证最终状态
    printf("最终出栈顺序: ");
    while (!stack_is_empty(stack)) {
        int value;
        stack_pop(stack, &value);
        printf("%d ", value);
    }
    printf("\n");
    
    if (!stack_is_empty(stack)) {
        TEST_FAIL("最终栈应为空");
        stack_destroy(stack);
        return;
    }
    
    TEST_PASS();
    stack_destroy(stack);
}

/* 6. 用户原始测试用例 */
static void test_original_case(void) {
    print_test_header("原始测试用例");
    
    Stack* stack = stack_create();
    for(int i = 0; i < 5; i++){
        stack_push(stack, i);
    }
    
    int tmp;
    stack_top(stack, &tmp);
    printf("栈顶元素: %d\n", tmp);
    
    printf("出栈元素: \n");
    while(!stack_is_empty(stack)){
        int value;
        stack_pop(stack, &value);
        printf("%d ", value);
    }
    printf("\n");
    
    stack_destroy(stack);
    TEST_PASS();
}

int main(void) {
    printf("开始栈测试套件\n");
    printf("========================================\n\n");
    
    test_basic_operations();
    test_multiple_elements();
    test_edge_cases();
    test_memory_and_performance();
    test_mixed_operations();
    test_original_case();
    
    printf("========================================\n");
    printf("所有测试完成！\n");
    
    return 0;
}