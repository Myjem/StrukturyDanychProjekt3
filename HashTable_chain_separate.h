#ifndef STRUKTURYDANYCHPROJEKT3_HASHTABLE_CHAIN_SEPARATE_H
#define STRUKTURYDANYCHPROJEKT3_HASHTABLE_CHAIN_SEPARATE_H
#include "base.h"
#include"array_list.h"
#include "couple.h"
#include "bst.h"
class HashTable_chain:public Base{
private:
    ArrayList<BST>* HashTab;//array of bst(AVL) trees
    int capacity;//quantity of index (m)
    int size;//quantity of elements
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
