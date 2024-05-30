#include<iostream>
#include "HashTable_open_addresing.h"
#include "ui.h"
#include "HashTable_chain_separate.h"
#include "HashTable_cuckoo.h"
#include<fstream>
#include<ctime>
#include <cstdlib>
#include <stdio.h>
#include <chrono>
#include <string>
#include "array_list.h"
using namespace std;

void load_data(HashTable_open *hashTable, int amount_of_data)
{
    fstream file;
    string k="";
    string v="";
    file.open("key_value.txt", ios::in);
    for (int i = 0; i < amount_of_data; i++) 
    {
        getline(file, k, ' ');
        getline(file, v);
        hashTable->insert(stoi(k), stoi(v));
    }
    file.close();
    cout << endl << "Wczytano" << endl << endl;
}

void load_keys(ArrayList<int>&Keys){
    fstream file;
    string k="";
    string v="";
    file.open("keys.txt", ios::in);
    for (int i = 0; i < Keys.get_size(); i++)
    {
        getline(file, k, ' ');
        getline(file, v);
        Keys.push_back(stoi(k));
    }
    file.close();
    cout << endl << "Wczytano klucze" << endl << endl;
}

int main()
{

    int q = 50;
    int amount_of_data = 3;//quantity of data
    ArrayList<int>Keys(amount_of_data);
    HashTable_open* hashTables[q];
     for (int i = 0; i < q; i++) {
        hashTables[i] = new HashTable_open(amount_of_data);
        load_data(hashTables[i],amount_of_data);
    }
    load_keys(Keys);

    auto begin = std::chrono::high_resolution_clock::now();
    for(int i=0;q>i;i++) hashTables[i]->insert();
    auto end = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
     cout<<"Czas dodania: "<<time.count()/q<<" ns"<<endl;

    //extract
    begin = std::chrono::high_resolution_clock::now();
    for(int i=0;q>i;i++) hashTables[i]->remove();               
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
    cout<<"Czas wyjecia najwiekszego priorytetu: "<<time.count()/q<<" ns"<<endl;
    //ui();
    return 0;
    
}