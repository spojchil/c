#include <stdio.h>
#include <float.h>
int main(void) {
    // 1. 检查 long double 类型的大小
    printf("sizeof(long double) = %zu bytes\n", sizeof(long double));
    printf("sizeof(double)      = %zu bytes\n\n", sizeof(double));

    // 2. 检查预定义宏（不同编译器的标志）
    #if defined(__STDC_VERSION__)
        printf("C Standard Version: %ld\n", __STDC_VERSION__);
    #endif

    #if defined(__GNUC__)
        printf("GCC/GNU Compiler (Version: %d.%d.%d)\n", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
    #endif

    #if defined(_MSC_VER)
        printf("MSVC Compiler (Version: %d)\n", _MSC_VER);
    #endif

    // 3. 检查 long double 的精度和范围
    #if defined(LDBL_MANT_DIG)
        printf("\nlong double 特性支持:\n");
        printf("LDBL_MANT_DIG (尾数位数)  : %d\n", LDBL_MANT_DIG);
        printf("LDBL_MIN     (最小正数)  : %Le\n", LDBL_MIN);
        printf("LDBL_MAX     (最大值)    : %Le\n", LDBL_MAX);
    #else
        printf("\nlong double 特性未定义!\n");
    #endif
    // 4. 实际打印测试
    long double dip = 5.32e-5L;
    printf("\n实际输出测试:\n");
    printf("预期值  : 0.000053 或 5.32e-05\n");
    printf("实际输出: %Lf 或 %Le\n", dip, dip);

    return 0;
}
/*
---

### **事件经过总结（学习日记记录）**  

#### **📌 问题发现**  
- **环境**：Windows + MinGW（GCC 14.2.0） + VSCode。  
- **现象**：`long double` 类型变量（如 `5.32e-5L`）用 `printf("%Lf")` 输出时，结果为 `0.000000` 或乱码（如 `3.108210e-317`），而教科书预期输出为 `0.000053`。  

#### **🔍 排查过程**  
1. **初步验证**  
   - 检查 `sizeof(long double)`，显示为 `16` 字节（正常应为 80/128 位扩展精度）。  
   - 但 `LDBL_MIN` 和 `LDBL_MAX` 输出异常（如 `3.108226e-317`），表明运行时库支持异常。  

2. **内存分析**  
   - 通过内存转储发现，`long double` 的实际数据（如 `58 09 71 40 A6 10 23 DF F0 3F`）符合扩展双精度格式，但 `printf` 无法正确解析。  

3. **根本原因**  
   - **Windows CRT 的限制**：Windows 的 C 运行时库（CRT）默认将 `long double` 视为 `double`（64 位），导致格式化函数 `printf` 无法处理 128 位数据。  
   - **MinGW 的特殊性**：MinGW 提供两种 `printf` 实现：  
     - **系统 CRT 版**（默认）：兼容 Windows，不支持 `long double`。  
     - **ANSI 标准版**：需通过宏 `__USE_MINGW_ANSI_STDIO=1` 启用，支持真正的 `long double`。  

#### **✅ 解决方案**  
1. **代码级修复**  
   - 在源代码开头添加宏定义（必须在所有 `#include` 之前）：  
     ```c
     #define __USE_MINGW_ANSI_STDIO 1
     #include <stdio.h>
     ```  
   - **验证**：输出 `0.000053`，问题解决。  

2. **工程级配置（推荐）**  
   - **VSCode 配置**：  
     - **`tasks.json`**：在编译参数中添加 `-D__USE_MINGW_ANSI_STDIO=1`。  
     - **`c_cpp_properties.json`**：在 `defines` 中添加宏，确保 IntelliSense 正确提示。  
   - **其他方法**：  
     - 静态链接（`gcc -static`）。  
     - 更换编译器（如 MSYS2 MinGW-w64）。  

#### **📚 经验总结**  
1. **Windows 兼容性问题**：  
   - Windows CRT 对 C 标准的支持有限，`long double` 是经典案例。  
   - MinGW 通过 `__USE_MINGW_ANSI_STDIO` 提供兼容性补丁。  

2. **调试技巧**：  
   - 使用 `sizeof` 和内存转储验证类型实际存储。  
   - 通过预定义宏控制编译器行为。  

3. **最佳实践**：  
   - **跨平台代码**：条件编译处理 `long double`（如 `#ifdef __MINGW32__`）。  
   - **文档记录**：类似问题可优先检查运行时库实现差异。  

#### **🔗 关联知识**  
- **IEEE 754 浮点标准**：`long double` 的扩展精度（80/128 位）与硬件支持。  
- **ABI 兼容性**：编译器与运行时库的交互规则。  

--- 

**✏️ 学习心得**  
此问题揭示了底层运行时库对语言特性的关键影响。在 Windows 开发中，需特别注意 CRT 与编译器的协作机制，宏定义和构建配置是解决问题的有效工具。未来遇到类似“不符合预期”的行为时，应优先排查环境兼容性！  

最后使用了工程级配置
修改了 tasks.json
*/

