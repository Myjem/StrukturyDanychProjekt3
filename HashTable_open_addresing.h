#ifndef STRUKTURYDANYCHPROJEKT3_HASHTABLE_OPEN_ADDRESING_H
#define STRUKTURYDANYCHPROJEKT3_HASHTABLE_OPEN_ADDRESING_H
#include "base.h"
#include"array_list.h"
#include "couple.h"
class HashTable_open:public Base{
private:
    ArrayList<couple> HashTable;
    int capacity;
    int size;
    int hash(int key);
public:
    HashTable_open(int c);
    void insert(int key,int value);
    void remove(int key);
    void print();
    int get_size();
    ~HashTable_open();
};
#endif
