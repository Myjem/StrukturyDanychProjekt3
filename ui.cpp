#include "ui.h"
#include <iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include <string>
#include "array_list.h"
#include "base.h"
#include "HashTable_chain_separate.h"
#include "HashTable_open_addresing.h"
#include "HashTable_cuckoo.h"


void ui() {
    while (true) {
        int number, mode;//mode==type of stucture, number==operation
        int c;//capacity
        Base*tab;
        cout << "Wybierz slownik: " << endl;
        cout << "[1] Tablica mieszajaca z adresowaniem otwartym" << endl;
        cout << "[2] Tablica mieszajaca z metoda lancuchowa" << endl;
        cout << "[3] Tablica mieszajaca z cuckoo hashing" << endl;
        cout << "[0] Zakoncz" << endl << endl;
        cout << "Wybor: ";
        cin >> mode;
        cout << endl;
        bool start = true;//for closing ui
        switch (mode) {//making structure
            case 1: {
                cout << "Podaj przewidywana ilosc par klucz-wartosc: ";
                cin >> c;
                HashTable_open *t= new HashTable_open(3*c);
                tab=t;
                break;
            }
            case 2:{
                cout << "Podaj przewidywana ilosc par klucz-wartosc: ";
                cin >> c;
                HashTable_chain *t = new HashTable_chain(3*c);
                tab=t;
                break;
            }
            case 3: {
                cout << "Podaj przewidywana ilosc par klucz-wartosc: ";
                cin >> c;
                HashTable_cuckoo *t = new HashTable_cuckoo(3*c);
                tab=t;
                break;
            }
            default: {
                cout << "Program zakonczony";
                return;
            }
        }

        while (start == 1) {
            switch (mode) {
                case 1: {
                    cout << "Tablica mieszajaca z adresowaniem otwartym:" << endl;
                    break;

                }
                case 2: {
                    cout << "Tablica mieszajaca z metoda lancuchowa:" << endl;
                    break;
                }
                case 3: {
                    cout << "Tablica mieszajaca z cuckoo hashing:" << endl;
                    break;
                }
                default: {
                    cout << "Zly tryb";
                    start = 0;
                    break;
                }
            }
            cout << "[1] Zbuduj z pliku" << endl;
            cout << "[2] Utworz losowo" << endl;
            cout << "[3] Dodaj pare klucz-element" << endl;
            cout << "[4] Usun pare zwiazana z kluczem" << endl;
            cout << "[5] Wyswietl" << endl;
            cout << "[0] Wroc do menu" << endl << endl;
            cout << "Wybor: ";
            cin >> number;
            cout << endl;
            switch (number) {
                case 0: {
                    start = false;
                    delete tab;
                    break;
                }
                case 1: {
                    string name = "";
                    cout << "Podaj nazwe pliku: ";
                    cin >> name;
                    cout << endl;
                    if (tab->get_size() != 0) {//deleting old structures
                        switch (mode) {
                            case 1: {
                                delete tab;
                                HashTable_open *temp = new HashTable_open(3*c);
                                tab = temp;
                                break;

                            }
                            case 2: {
                                delete tab;
                                HashTable_chain *temp = new HashTable_chain(3*c);
                                tab = temp;
                                break;
                            }
                            case 3: {
                                delete tab;
                                HashTable_cuckoo *temp = new HashTable_cuckoo(3*c);
                                tab = temp;
                                break;
                            }
                        }
                    }
                    fstream file;
                    string k="";
                    string v="";
                    file.open(name, ios::in);//uploading data
                    for (int i = 0; c > i and file.eof() != 1; i++) {
                        getline(file, k, ' ');
                        getline(file, v);
                        tab->insert(stoi(k), stoi(v));
                    }
                    file.close();
                    cout << endl << "Wczytano" << endl << endl;
                    break;
                }
                case 2: {
                    srand(time(NULL));
                    if (tab->get_size() != 0) {
                        switch (mode) {//deleting old stucture
                            case 1: {
                                delete tab;
                                HashTable_open *temp = new HashTable_open(3*c);
                                tab = temp;
                                break;

                            }
                            case 2: {
                                delete tab;
                                HashTable_chain *temp = new HashTable_chain(3*c);
                                tab = temp;
                                break;
                            }
                            case 3: {
                                delete tab;
                                HashTable_cuckoo *temp = new HashTable_cuckoo(3*c);
                                tab = temp;
                                break;
                            }
                        }
                    }
                    int max_v;
                    cout << "Podaj najwieksza mozliwa wartosc: ";
                    cin >> max_v;
                    for (int i = 0; c > i; i++) {
                        int value = (rand() % max_v) + 1;
                        tab->insert(i+1,value) ;//generating random numbers
                    }
                    cout << endl << "Wygenerowano "<<c<<" par o wartosciach z przedzialu <" << 1<< "," << max_v << "> z kluczami z przedzialu <1,"<<c <<">"<< endl << endl;
                    break;
                }
                case 3: {
                    int key;
                    cout << "Podaj wartosc do dodania: ";
                    cin >> number;
                    cout << "Podaj klucz: ";
                    cin >> key;
                    if (key < 0) {
                        cout << endl << "Klucz musi byc dodatni!" << endl << endl;
                        break;
                    }
                    tab->insert(key, number);
                    cout << endl << "Dodano" << endl << endl;
                    break;
                }

                case 4: {
                    cout << "Podaj klucz do usuniecia pary: ";
                    cin >> number;
                    if (number < 0) {
                        cout << endl << "Klucz musi byc dodatni!" << endl << endl;
                        break;
                    }
                    tab->remove(number);
                    cout << endl << "Usunieto pare" << endl << endl;
                    break;
                }

                case 5: {
                    tab->print();
                    break;
                }
                default: {
                    start = false;
                    break;
                }
            }
        }
    }
}