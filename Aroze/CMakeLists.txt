cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本
project(Aroze VERSION 0.1)

# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加源文件夹
file(GLOB SOURCES "src/*.cpp")

# 添加可执行文件
add_executable(Aroze ${SOURCES} "src/Utils.h" "src/math/vector.h")