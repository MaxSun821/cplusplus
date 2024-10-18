cmake_minimum_required(VERSION 3.28)
project(cplusplus)

set(CMAKE_CXX_STANDARD 11)

add_executable(basic basic/main.cpp)
add_executable(Date Date/main.cpp
        Date/Date.cpp)
add_executable(string string/main.cpp
        string/string.h)
add_executable(vector vector/main.cpp
        vector/vector.h)
add_executable(list list/main.cpp
        list/list.h)
add_executable(stack stack&&queue/main.cpp
        stack&&queue/stack.h
        stack&&queue/queue.h
)
add_executable(binary_search_tree binary-search-tree/BinarySearchTree.h
        binary-search-tree/main.cpp)
add_executable(AVLTree AVLTree/main.cpp
        AVLTree/AVLTree.h)
add_executable(set_map set-map/set.h
        set-map/main.cpp
        set-map/map.h
        set-map/RBTree.h)
add_executable(hash Hash/main.cpp
        Hash/hash_table.h
        Hash/hash_backet.h)
add_executable(hashset-hashmap hashset-hashmap/my_unordered_set.h
        hashset-hashmap/hash_backet.h
        hashset-hashmap/my_unordered_set.h
        hashset-hashmap/main.cpp
        hashset-hashmap/my_unordered_map.h)
add_executable(smart_ptr smart_ptr/share_ptr.h
        smart_ptr/main.cpp)
add_executable(program-design program_design/main.cpp)
