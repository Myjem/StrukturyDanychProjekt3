#ifndef STRUKTURYDANYCHPROJEKT3_HASHTABLE_2_CHOICE_H
#define STRUKTURYDANYCHPROJEKT3_HASHTABLE_2_CHOICE_H
#include "base.h"
#include "couple.h"
#include "array_list.h"
class HashTable_2_choice:public Base{
    private:
    ArrayList<couple>* HashTab;
    int capacity;
    int size;
    int hash1(int key);
    int hash2(int key);
    public:
    HashTable_2_choice(int c);
    void insert(int key,int value);
    void remove(int key);
    void print();
    int get_size();
    ~HashTable_2_choice();

};
#endif
