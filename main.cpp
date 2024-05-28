#include<iostream>
#include "HashTable_open_addresing.h"
#include"array_list.h"
#include "ui.h"
#include "HashTable_chain_separate.h"
using namespace std;

int main()
{
    HashTable_open a(10);
    a.insert(5,10);
    a.insert(6,6);
    a.insert(5,3);
    a.print();
    //ui();
    return 0;
}