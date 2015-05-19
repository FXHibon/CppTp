cmake_minimum_required(VERSION 3.1)
project(Cours)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Cours ${SOURCE_FILES} TP/AList.cpp TP/TreeList/TreeList.cpp TP/TreeList/Node.cpp TP/mainTp.cpp TP/LinkedList/Cell.cpp TP/LinkedList/LinkedList.cpp)