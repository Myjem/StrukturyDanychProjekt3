#include "HashTable_2_choice.h"

using namespace std;

HashTable_2_choice::HashTable_2_choice(int c):capacity(c),size(0) {
    HashTab = new ArrayList<couple>[capacity];
}
int HashTable_2_choice::hash1(int key) {
    return key % capacity; // hash function x mod m
}
int HashTable_2_choice::hash2(int key) {
    return (key / capacity) % capacity; // hash function (x div m) mod m
}

void HashTable_2_choice::insert(int key, int value) {
    int index1 = hash1(key);
    int index2 = hash2(key);

    for (int i = 0; i < HashTab[index1].get_size(); i++) {
        if (HashTab[index1].get(i).key == key) {
            HashTab[index1].set(i, couple(key, value));
            return;
        }
    }

    for (int i = 0; i < HashTab[index2].get_size(); i++) {
        if (HashTab[index2].get(i).key == key) {
            HashTab[index2].set(i, couple(key, value));
            return;
        }
    }

    if (HashTab[index1].get_size() <= HashTab[index2].get_size()) {
        HashTab[index1].push_back(couple(key, value));
    } else {
        HashTab[index2].push_back(couple(key, value));
    }
    size++;
}

void HashTable_2_choice::remove(int key) {
    int index1 = hash1(key);
    int index2 = hash2(key);

    for (int i = 0; i < HashTab[index1].get_size(); i++) {
        if (HashTab[index1].get(i).key == key) {
            HashTab[index1].del(i);
            size--;
            return;
        }
    }

    for (int i = 0; i < HashTab[index2].get_size(); i++) {
        if (HashTab[index2].get(i).key == key) {
            HashTab[index2].del(i);
            size--;
            return;
        }
    }
}

void HashTable_2_choice::print() {
    for (int i = 0; i < capacity; i++) {
        if (HashTab[i].get_size() == 0) continue;
        for (int j = 0; j < HashTab[i].get_size(); j++) {
            couple t = HashTab[i].get(j);
            cout << "key " << t.key << " ";
            cout << "value " << t.value << endl;
        }
    }
}

int HashTable_2_choice::get_size() {
    return size;
}

HashTable_2_choice::~HashTable_2_choice() {
    delete [] HashTab;
}
