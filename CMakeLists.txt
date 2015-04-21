cmake_minimum_required(VERSION 3.1)
project(Cours)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Cours ${SOURCE_FILES} templateLinkedList.cpp LinkedList.cpp Cell.cpp mainTemplate.h mainTemplate.cpp)