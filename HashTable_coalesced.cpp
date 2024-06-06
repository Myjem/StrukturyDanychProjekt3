#include <iostream>
#include "HashTable_coalesced.h"
#include "base.h"
#include "couple_coalesced.h"

using namespace std;

HashTable_coalesced::HashTable_coalesced(int c):capacity(c),size(0)
{
    Hashtable = new couple_coalesced*[capacity];
}