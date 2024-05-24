#ifndef STRUKTURYDANYCHPROJEKT3_HASHTABLE_CUCKOO_H
#define STRUKTURYDANYCHPROJEKT3_HASHTABLE_CUCKOO_H
#include "base.h"
#include"array_list.h"
class HashTable_cuckoo:public Base{
private:
    int size;
    int capacity;
public:
    HashTable_cuckoo(int c);
    void insert(int key,int value);
    void remove(int key);
    void print();
    int get_size();
    ~HashTable_cuckoo();
};
#endif
