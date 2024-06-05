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
        HashTable[i] = nullptr;             //filling the entire list with nullpointers
    }
}

int HashTable_open::hash(int key) {
    return key % capacity;              //method for hashing
}  

void HashTable_open::insert(int key, int value) {
    if (size >= capacity) {
        cout << "HashTable is full" << endl;
        return;
    }
    int index = hash(key);
    int originalIndex = index;

    while (HashTable[index] != nullptr) {
        if (HashTable[index]->key == key) {
            HashTable[index]->value = value;        //check if this key exist
            return;
        }
        index = (index + 1) % capacity;             //linear probing
        if (index == originalIndex) {
            cout << "Hash table is full" << endl;
            return;
        }
    }
    HashTable[index] = new couple{key, value}; 
    size++;
}

void HashTable_open::remove(int key) {
    int index = hash(key);
    int originalIndex = index;

    while (true) {
         if (HashTable[index] != nullptr) {
            if (HashTable[index]->key == key) {
                delete HashTable[index];
                HashTable[index] = nullptr;             //deleting entire node
                --size;
                return;
            }
        } else if (index == originalIndex) {
            cout << "Key not found";
            return;
        }

        index = (index + 1) % capacity;         //linear probing
    }
}

void HashTable_open::print() {
    for (int i = 0; i < capacity; i++)
    {
        if(HashTable[i] != nullptr)
        {
            cout << " Key: " << HashTable[i]->key << " Value: " << HashTable[i]->value << endl;
        }
        else continue;
    }
}

int HashTable_open::get_size() {
    return size;
}

int HashTable_open::get_capacity(){
    return capacity;
}


HashTable_open::~HashTable_open() {
    for (int i = 0; i < capacity; i++) {
        if (HashTable[i] != nullptr) {
            delete HashTable[i];
        }
    }
    delete[] HashTable;
}