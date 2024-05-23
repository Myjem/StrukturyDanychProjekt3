#ifndef STRUKTURYDANYCHPROJEKT3_HASHTABLE_OPEN_ADDRESING_H
#define STRUKTURYDANYCHPROJEKT3_HASHTABLE_OPEN_ADDRESING_H
#include "base.h"
#include"array_list.h"
#include "couple.h"
class HashTable_open:public Base{
private:
    ArrayList<couple> HashTable;
    int hash(int key);
public:
    HashTable_open(int s);
    void insert(int value,int key);
    void remove(int key);
    void print();
    ~HashTable_open();
};
#endif
