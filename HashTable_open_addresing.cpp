#include <iostream>
#include "HashTable_open_addresing.h"
#include "couple.h"
#include "array_list.h"
#include "base.h"

using namespace std;

HashTable_open::HashTable_open(int c):capacity(c),size(0)
{
    HashTable = new couple*[capacity];
    for(int i = 0; i < capacity; i++)
    {
        HashTable[i] = nullptr;
    }
}

int HashTable_open::hash(int key) {
    return key % capacity;
}

void HashTable_open::insert(int key, int value) {
    if(size >= capacity)
    {
        cout << "HashTable is full";
    }
    int index = hash(key);
        int originalIndex = index;
        while (HashTable[index] != nullptr) {
            index = (index + 1) % capacity;
            if (index == originalIndex) {
                cout << "Hash table is full";
                return;
            }
        }
        HashTable[index] = new couple{key, value};
        ++size;
}

void HashTable_open::remove(int key) {
}

void HashTable_open::print() {
    for (int i = 0; i < capacity; i++)
    {
        if(HashTable[i] != nullptr)
        {
            cout << "Index: " << i << " Key: " << HashTable[i]->key << " Value: " << HashTable[i]->value << endl;
        }
        else
        {
            cout << "Index: " << i << " is empty" << endl;
        }
        
    }
}

int HashTable_open::get_size() {
    return size;
}

int HashTable_open::get_capacity(){
    return capacity;
}


HashTable_open::~HashTable_open() {
}