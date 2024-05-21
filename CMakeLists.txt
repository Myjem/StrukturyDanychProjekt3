cmake_minimum_required(VERSION 3.28)
project(StrukturyDanychProjekt3)

set(CMAKE_CXX_STANDARD 14)

add_executable(StrukturyDanychProjekt3
        main.cpp
        ui.cpp
        ui.h
        HashTable_cuckoo.h
        HashTable_close_addresing.h
        HashTable_open_addresing.h
        base.h
        array_list.h)
