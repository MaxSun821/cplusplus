cmake_minimum_required(VERSION 3.28)
project(c C)

set(CMAKE_C_STANDARD 99)

add_executable(SeqList structure/SeqList/main.c structure/SeqList/SeqList.c structure/SeqList/SeqList.h)

add_executable(main basic/main.c)

add_executable(SList structure/SList/main.c structure/SList/SList.c structure/SList/SList.h structure/SList/test.c)

add_executable(List structure/List/main.c structure/List/List.c structure/List/List.h)

add_executable(Stack structure/Stack/Stack.h
        structure/Stack/main.c
        structure/Stack/Stack.c)
add_executable(Queue structure/Queue/main.c
        structure/Queue/Queue.c)
add_executable(Heap structure/Heap/Heap.c
        structure/Heap/main.c)
add_executable(BinaryTree structure/BinaryTree/main.c
        structure/BinaryTree/BinaryTree.c
        structure/BinaryTree/Queue.c)
add_executable(Sort structure/Sort/main.c
        structure/Sort/Sort.c
        structure/Sort/Sort.h
        structure/Sort/Stack.c)
