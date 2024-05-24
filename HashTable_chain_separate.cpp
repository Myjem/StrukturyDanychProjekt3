#include <iostream>
#include "base.h"
#include "array_list.h"
#include "couple.h"
#include "HashTable_chain_separate.h"

using namespace std;

HashTable_chain:: HashTable_chain(int c) : capacity(c), size(0){
    HashTab = new ArrayList<couple>[capacity];
}

int HashTable_chain::hash(int key) {
    return key % capacity;
}

void HashTable_chain::insert(int key, int value) {
    int index = hash(key);
    ArrayList<couple> &chain = HashTab[index];
    for(int i = 0; i < chain.get_size(); i++) {
        if (chain.get(i).key == key) {
            chain.get(i).value = value;
            return;
        }
    }
    chain.push_back(couple(key, value));
    size++;
}

void HashTable_chain::remove(int key) {
    int index = hash(key);
    ArrayList<couple> &chain = HashTab[index];
    for (int i = 0; i < chain.get_size(); i++) {
        if (chain.get(i).key == key) {
            chain.del(i);
            size--;
            return;
        }
    }
}

void HashTable_chain::print() {
    for (int i = 0; i < capacity; i++) {
        cout << i << ": ";
        for (int j = 0; j < HashTab[i].get_size(); j++) {
            cout<<"Klucz: "<<HashTab[i].get(j).key << " ";
            cout <<"Wartosc: " <<HashTab[i].get(j).value << " ";
        }
        cout << endl;
    }
}

int HashTable_chain::get_size() {
    return size;
}

HashTable_chain::~HashTable_chain() {
    delete[] HashTab;
}