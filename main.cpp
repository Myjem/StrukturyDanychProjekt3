#include<iostream>
#include "HashTable_open_addresing.h"
#include "ui.h"
#include "HashTable_chain_separate.h"
using namespace std;

int main()
{
    HashTable_open a(3);
    a.insert(0,10);
    a.insert(4,20);
    a.insert(3,30);
    cout << a.get_capacity() << endl;
    a.print();
    //ui();
    return 0;
}