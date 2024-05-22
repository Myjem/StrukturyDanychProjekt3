#include "base.h"
#include "array_list.h"
#include "couple.h"
#include "HashTable_chain_separate.h"

using namespace std;

HashTable_chain::HashTable_chain(int capacity) {
    HashTable = ArrayList<ArrayList<couple>>(capacity);
}

int HashTable_chain::hash(int key) {
    return key % capacity;
}

void HashTable_chain::insert(int value, int key) {
    int index = hash(key);
    HashTable[index].push_back(couple(key, value));
    size++;
}

void HashTable_chain::remove(int key) {
    int index = hash(key);
    for (int i = 0; i < HashTable[index].size(); i++) {
        if (HashTable[index][i].key == key) {
            HashTable[index].erase(i);
            size--;
            return;
        }
    }
}

void HashTable_chain::print() {
    for (int i = 0; i < size; i++) {
        cout << i << ": ";
        for (int j = 0; j < HashTable[i].size(); j++) {
            cout << HashTable[i][j].value << " ";
        }
        cout << endl;
    }
}

HashTable_chain::~HashTable_chain() {
    for (int i = 0; i < size; i++) {
        HashTable[i].~ArrayList();
    }
    HashTable.~ArrayList();
}