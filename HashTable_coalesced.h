#ifndef STRUKTURYDANYCHPROJEKT3_HASHTABLE_COALESCED_H
#define STRUKTURYDANYCHPROJEKT3_HASHTABLE_COALESCED_H
#include "base.h"
class HashTable_coalesced:public Base{
    private:

    int capacity;
    int size;
public:
    HashTable_coalesced(int c);
    void insert(int key,int value);
    void remove(int key);
    void print();
    int get_size();
    ~HashTable_coalesced();
};
#endif
