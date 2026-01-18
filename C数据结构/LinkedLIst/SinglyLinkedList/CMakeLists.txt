cmake_minimum_required(VERSION 3.10)
project(SinglyLinkedList C)

# 设置C标准
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# 编译选项
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror -Wpedantic -Wall -fdiagnostics-color=always -g")

# 包含目录
include_directories(${PROJECT_SOURCE_DIR}/src)

# 添加库
add_library(singlylinkedlist ${PROJECT_SOURCE_DIR}/src/singlylinkedlist.c)

# 添加可执行文件
add_executable(test_singlylinkedlist 
    ${PROJECT_SOURCE_DIR}/test/test.c
)

# 链接库
target_link_libraries(test_singlylinkedlist singlylinkedlist)

# 安装规则（可选）
install(TARGETS singlylinkedlist ARCHIVE DESTINATION lib)
install(FILES ${PROJECT_SOURCE_DIR}/src/singlylinkedlist.h DESTINATION include)