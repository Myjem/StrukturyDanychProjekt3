#include "HashTable_cuckoo.h"

using namespace std;

HashTable_cuckoo::HashTable_cuckoo(int c) {
    capacity = c;
    size = 0;
    HashTable1 = new couple*[capacity];
    HashTable2 = new couple*[capacity];
    for(int i=0;i<capacity;i++){
        HashTable1[i] = nullptr;
        HashTable2[i] = nullptr;
    }
}

int HashTable_cuckoo::hash1(int key) {
    return key % capacity;
}

int HashTable_cuckoo::hash2(int key) {
    return (key / capacity) % capacity;
}

void HashTable_cuckoo::rehash() {
    couple** oldTable1 = HashTable1;
    couple** oldTable2 = HashTable2;
    int oldCapacity = capacity;

    capacity *= 2;
    size = 0;
    HashTable1 = new couple*[capacity];
    HashTable2 = new couple*[capacity];
    for(int i = 0; i < capacity; i++) {
        HashTable1[i] = nullptr;
        HashTable2[i] = nullptr;
    }

    for(int i = 0; i < oldCapacity; i++) {
        if(oldTable1[i] != nullptr) {
            insert(oldTable1[i]->key, oldTable1[i]->value);
            delete oldTable1[i];
        }
        if(oldTable2[i] != nullptr) {
            insert(oldTable2[i]->key, oldTable2[i]->value);
            delete oldTable2[i];
        }
    }

    delete[] oldTable1;
    delete[] oldTable2;
}

void HashTable_cuckoo::insert(int key, int value) {
    int count = 0;
    couple* temp = new couple(key, value);

    while (count < capacity) {
        int index1 = hash1(temp->key);
        if (HashTable1[index1] == nullptr) {
            HashTable1[index1] = temp;
            size++;
            return;
        }
        else if(HashTable1[index1]->key == temp->key)
        {
            HashTable1[index1]->value = temp->value;
            delete temp;
            return;
        }
        else
        {
            swap(temp, HashTable1[index1]);
        }

        int index2 = hash2(temp->key);
        if (HashTable2[index2] == nullptr) {
            HashTable2[index2] = temp;
            size++;
            return;
        }
        else if(HashTable2[index2]->key == temp->key)
        {
            HashTable2[index2]->value = temp->value;
            delete temp;
            return;
        }
        else
        {
            swap(temp, HashTable2[index2]);
        }
        count++;
    }

    delete temp;
    rehash();
    insert(key, value);
}


void HashTable_cuckoo::remove(int key) {
    int index1 = hash1(key);
    if (HashTable1[index1] != nullptr && HashTable1[index1]->key == key) {
        delete HashTable1[index1];
        HashTable1[index1] = nullptr;
        size--;
        return;
    }

    int index2 = hash2(key);
    if (HashTable2[index2] != nullptr && HashTable2[index2]->key == key) {
        delete HashTable2[index2];
        HashTable2[index2] = nullptr;
        size--;
        return;
    }
}


void HashTable_cuckoo::print() {
    for(int i = 0; i < capacity; i++) {
        if(HashTable1[i] != nullptr) {
            cout <<" Key: " << HashTable1[i]->key << " Value: " << HashTable1[i]->value << endl;
        }
        if(HashTable2[i] != nullptr) {
            cout <<" Key: " << HashTable2[i]->key << " Value: " << HashTable2[i]->value << endl;
        }
        else continue;
    }
}

int HashTable_cuckoo::get_size() {
    return size;
}

HashTable_cuckoo::~HashTable_cuckoo() {
    for (int i = 0; i < capacity; i++) {
        if (HashTable1[i] != nullptr) {
            delete HashTable1[i];
        }
        if (HashTable2[i] != nullptr) {
            delete HashTable2[i];
        }
    }
    delete[] HashTable1;
    delete[] HashTable2;
}