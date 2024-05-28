#ifndef STRUKTURYDANYCHPROJEKT3_HASHTABLE_OPEN_ADDRESING_H
#define STRUKTURYDANYCHPROJEKT3_HASHTABLE_OPEN_ADDRESING_H
#include "base.h"
#include "couple.h"
class HashTable_open:public Base{
private:
    int capacity;
    int size;
    int hash(int key);
    couple** HashTable;
public:
    HashTable_open(int c);
    void insert(int key,int value);
    void remove(int key);
    void print();
    int get_size();
    int get_capacity();
    ~HashTable_open();
};
#endif
