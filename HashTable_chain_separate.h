#ifndef STRUKTURYDANYCHPROJEKT3_HASHTABLE_CHAIN_SEPARATE_H
#define STRUKTURYDANYCHPROJEKT3_HASHTABLE_CHAIN_SEPARATE_H
#include "base.h"
#include"array_list.h"
class HashTable_chain:public Base{
private:
    ArrayList<ArrayList<int>> HashTable;
    int size;
    int hash(int key);
public:
    HashTable_chain(int s);
    void insert(int value,int key);
    void remove(int key);
    void print();
    ~HashTable_chain();
};
#endif
