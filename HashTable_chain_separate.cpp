#include <iostream>
#include "base.h"
#include "array_list.h"
#include "couple.h"
#include "HashTable_chain_separate.h"

using namespace std;

HashTable_chain::HashTable_chain(int c):capacity(c),size(0) {
    HashTable = ArrayList<ArrayList<couple>>(capacity);
}

int HashTable_chain::hash(int key) {
    return key % capacity;
}

void HashTable_chain::insert(int value, int key) {
    int index = hash(key);
    ArrayList<couple> &chain = HashTable.get(index);
    for (int i = 0; i < chain.get_size(); i++) {
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
    ArrayList<couple> &chain = HashTable.get(index);
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
        for (int j = 0; j < HashTable.get(i).get_size(); j++) {
            cout << HashTable.get(i).get(j).value << " ";
        }
        cout << endl;
    }
}

HashTable_chain::~HashTable_chain(){
    for (int i = 0; i < capacity; i++) {
        HashTable.get(i).~ArrayList();
    }
    HashTable.~ArrayList();
}