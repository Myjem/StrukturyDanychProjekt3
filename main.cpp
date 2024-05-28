#include<iostream>
#include "HashTable_open_addresing.h"
#include "ui.h"
#include "HashTable_chain_separate.h"
using namespace std;

int main()
{
    /*
    HashTable_open a(3);
    a.insert(0,10);
    a.insert(1,20);
    a.insert(1,30);
    //a.remove(5);
    a.print();
    //ui();*/
    HashTable_chain a(3);
    a.insert(4,10);
    a.insert(1,20);
    a.insert(5,30);
    a.print();
    a.remove(5);
    a.print();
    return 0;
}