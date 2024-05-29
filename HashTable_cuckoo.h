#ifndef STRUKTURYDANYCHPROJEKT3_HASHTABLE_CUCKOO_H
#define STRUKTURYDANYCHPROJEKT3_HASHTABLE_CUCKOO_H
#include "base.h"
#include"array_list.h"
#include "couple.h"
class HashTable_cuckoo:public Base{
private:
    couple** HashTable1;
    couple**HashTable2;
    int size;
    int capacity;
    int hash1(int key);
    int hash2(int key);
    void rehash();
public:
    HashTable_cuckoo(int c);
    void insert(int key,int value);
    void remove(int key);
    void print();
    int get_size();
    ~HashTable_cuckoo();
};
#endif
