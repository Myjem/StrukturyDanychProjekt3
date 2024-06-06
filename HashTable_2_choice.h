#ifndef STRUKTURYDANYCHPROJEKT3_HASHTABLE_2_CHOICE_H
#define STRUKTURYDANYCHPROJEKT3_HASHTABLE_2_CHOICE_H
#include "base.h"
class HashTable_2_choice:public Base{
    private:
    int capacity;
    int size;
    public:
    HashTable_2_choice(int c);
    void insert(int key,int value);
    void remove(int key);
    void print();
    int get_size();
    ~HashTable_2_choice();

};
#endif
