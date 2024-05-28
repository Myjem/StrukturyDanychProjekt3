#include <iostream>
#include "base.h"
#include "array_list.h"
#include "couple.h"
#include "HashTable_chain_separate.h"

using namespace std;

HashTable_chain:: HashTable_chain(int c) : capacity(c), size(0){
    HashTab = new ArrayList<BST>[capacity];
}

int HashTable_chain::hash(int key) {
    return key % capacity;
}

void HashTable_chain::insert(int key, int value) {
    if(size == capacity)
    {
        cout<<"Slownik pelny!"<<endl;
        return;
    }
    if(key<0)
    {
        cout<<"Klucz musi byc wiekszy od zero"<<endl;
        return;
    }
    int index = hash(key);
    HashTab->get(index).insert(key, value);
    size++;
}

void HashTable_chain::remove(int key) {
    int index = hash(key);
    HashTab->get(index).remove(key);
    size--;
}

void HashTable_chain::print() {
    for (int i = 0; i < capacity; i++)
    {
        HashTab->get(i).print();
    }
}

int HashTable_chain::get_size() {
    return size;
}

HashTable_chain::~HashTable_chain() {
    delete[] HashTab;
}