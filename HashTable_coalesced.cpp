#include "HashTable_coalesced.h"
#include <iostream>

using namespace std;

HashTable_coalesced::HashTable_coalesced(int c) : capacity(c), size(0) {
    Hashtable = new couple_coalesced[capacity];
}

HashTable_coalesced::~HashTable_coalesced() {
    delete[] Hashtable;
}

void HashTable_coalesced::insert(int key, int value) {
    if(size == capacity)
    {
        cout << "table is full";                //check if full
        return;
    }
    int index = hash(key);
    if (Hashtable[index].key == 0 && Hashtable[index].value == 0) {
        Hashtable[index] = couple_coalesced(key, value, nullptr);           //if hashed key is empty, insert into slot
    } else {
        couple_coalesced* temp = &Hashtable[index];
        while(temp->next != nullptr)
        {
            temp = temp->next;                      //look for the last node of the chain to connect to
        }
        for(int i = capacity - 1; i >= 0; i--)          //look for the first empty slot from the back of the hashtable
        {                                                           //(linear probing)
            if(Hashtable[i].key == 0 && Hashtable[i].value == 0)
            {
                Hashtable[i] = couple_coalesced(key, value, nullptr);
                temp->next = &Hashtable[i];
            }
        }
    }
    size++;
}

void HashTable_coalesced::remove(int key) {
    
}

void HashTable_coalesced::print() {
    for (int i = 0; i < capacity; i++) {
        cout << "Index: " << i << " Key: " << Hashtable[i].key << " Value: " << Hashtable[i].value << endl;
    }
}

int HashTable_coalesced::get_size() {
    return size;
}

int HashTable_coalesced::hash(int key) {
    return key % capacity;
}