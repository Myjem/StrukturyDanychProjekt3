#include <iostream>
#include "HashTable_open_addresing.h"
#include "couple.h"
#include "array_list.h"
#include "base.h"

using namespace std;

HashTable_open::HashTable_open(int c):capacity(c),size(0),HashTable(c*2) {}

int HashTable_open::hash(int key) {
    return key % capacity;
}

void HashTable_open::insert(int key, int value) {
    HashTable.append(hash(key),couple(key,value));
}

void HashTable_open::remove(int key) {
}

void HashTable_open::print() {
    cout << "Capacity: " << HashTable.get_capacity() << endl;
    cout << "Size: " << HashTable.get_size() << endl;
    for(int i = 0; i < HashTable.get_capacity(); i++)
    {
        cout << "Klucz: " << HashTable.get(i).key << " ";
        cout << "Value: " << HashTable.get(i).value << endl;
    }
}

int HashTable_open::get_size() {
    return size;
}


HashTable_open::~HashTable_open() {
}