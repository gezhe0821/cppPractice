cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(PolygonIntersect)

# 添加可执行文件
add_executable(PolygonIntersect src/main.cpp src/PolygonIntersect.cpp src/ReadPoints.cpp)

# 设置包含目录
include_directories(include)
