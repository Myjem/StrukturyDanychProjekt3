#include "HashTable_coalesced.h"
#include <iostream>

using namespace std;

HashTable_coalesced::HashTable_coalesced(int c) : capacity(c), size(0), cellar(0.86*capacity), cellar_size(0) {
    Hashtable = new couple_coalesced[capacity];
}

HashTable_coalesced::~HashTable_coalesced() {
    delete[] Hashtable;
}

void HashTable_coalesced::insert(int key, int value) {
    if(size == capacity) {
        cout << "table is full" << endl;                //check if full
        return;
    }
    int index = hash(key);
    if (Hashtable[index].key == 0 && Hashtable[index].value == 0) {
        Hashtable[index] = couple_coalesced(key, value, nullptr);           //if hashed key is empty, insert into slot
        size++;
        return;           
    }
    else {
        couple_coalesced* temp = &Hashtable[index];
        couple_coalesced* checker = &Hashtable[index];
        while(checker != nullptr) {                 //check if key exists
            if(checker->key == key){
                checker->value = value;
                return;
            }
            checker = checker->next;
            if(checker != nullptr){
                temp = temp->next;              //holds one value previous of checker for adding element later
            }                      
        }
        if (cellar_size == capacity-cellar) {               //check if strych is pełny
            cout << "Cellar is full" << endl;
            return;
        }        
            Hashtable[cellar + cellar_size].key = key;
            Hashtable[cellar + cellar_size].value = value;
            Hashtable[cellar + cellar_size].next = nullptr;            //fill the first empty cellar couple
            temp->next = &Hashtable[cellar + cellar_size];              //point from the original index to newly made couple
            size++;
            cellar_size++;
            return;
    }
}

void HashTable_coalesced::remove(int key) {
     int index = hash(key);
    couple_coalesced* temp = &Hashtable[index];
    couple_coalesced* prev = nullptr;

    while (temp != nullptr && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        // Key not found
        return;
    }

    if (prev == nullptr) {
        if(temp->next == nullptr)
        {
            Hashtable[index] = couple_coalesced();
            size--;
            return;   //first case if there is no depth
        }
        Σ = &Hashtable[cellar_size + cellar - 1];     // point to the last node in cellar
        couple_coalesced* hold_next = temp->next;
        Hashtable[index].key = hold_next->key;
        Hashtable[index].value = hold_next->value;              //second case if the first element contains next key
        Hashtable[index].next = hold_next->next;
        hold_next->key = Σ->key;
        hold_next->value = Σ->value;
        hold_next->next = Σ->next;
        *Σ = couple_coalesced();
        cellar_size--;
    }
    else {
        Σ = &Hashtable[cellar_size + cellar - 1];
        prev->next = temp->next;
        temp->key = Σ->key;
        temp->value= Σ->value;
        temp->next = Σ->next;
        *Σ = couple_coalesced();
        cellar_size--;
    }
    size--;
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
    return key % cellar;
}