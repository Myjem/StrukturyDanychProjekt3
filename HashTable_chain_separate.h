#ifndef STRUKTURYDANYCHPROJEKT3_HASHTABLE_CHAIN_SEPARATE_H
#define STRUKTURYDANYCHPROJEKT3_HASHTABLE_CHAIN_SEPARATE_H
#include "base.h"
#include"array_list.h"
#include "couple.h"
class HashTable_chain:public Base{
private:
    ArrayList<couple>* HashTab;
    int capacity;//quantity of index (m)
    int size;//qua tity of elements
    int hash(int key);//hash function x mod m
public:
    HashTable_chain(int c);
    void insert(int key,int value);
    void remove(int key);
    void print();
    int get_size();
    ~HashTable_chain();
};
#endif
