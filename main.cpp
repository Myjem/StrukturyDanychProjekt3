#include<iostream>
#include "HashTable_open_addresing.h"
#include"array_list.h"
using namespace std;

int main()
{
    HashTable_open a(10);
    a.insert(10,5);
    a.print();
    //ArrayList<couple> test(10);
    //cout << test.get_capacity();
    //return 0;
}