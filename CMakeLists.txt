cmake_minimum_required(VERSION 3.28)
project(StrukturyDanychProjekt3)

set(CMAKE_CXX_STANDARD 14)

add_executable(StrukturyDanychProjekt3
        main.cpp
        ui.cpp
        ui.h
        HashTable_cuckoo.h
        HashTable_chain_separate.h
        HashTable_open_addresing.h
        base.h
        array_list.h
        HashTable_chain_separate.cpp
        HashTable_open_addresing.cpp
        couple.h
        HashTable_cuckoo.cpp
        bst_node.h
        bst.h
        bst.cpp
        HashTable_2_choice.h
        HashTable_coalesced.h
        HashTable_2_choice.cpp)
