#ifndef STRUKTURYDANYCHPROJEKT3_HASHTABLE_CHAIN_SEPARATE_H
#define STRUKTURYDANYCHPROJEKT3_HASHTABLE_CHAIN_SEPARATE_H
#include "base.h"
#include"array_list.h"
#include "couple.h"
class HashTable_chain:public Base{
private:
    ArrayList<ArrayList<couple>> HashTable;
    int size;
    int hash(int key);
public:
    HashTable_chain(int size);
    void insert(int value,int key);
    void remove(int key);
    void print();
    ~HashTable_chain();
};
#endif