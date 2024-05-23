#include <iostream>
#include "HashTable_open_addresing.h"
#include "couple.h"
#include "array_list.h"
#include "base.h"

using namespace std;

HashTable_open::HashTable_open(int c):capacity(c),size(c),HashTable(ArrayList<couple>(c)) {}

int HashTable_open::hash(int key) {
    return 0;
}

void HashTable_open::insert(int value, int key) {
}

void HashTable_open::remove(int key) {
}

void HashTable_open::print() {
}

HashTable_open::~HashTable_open() {
}