#ifndef STRUKTURYDANYCHPROJEKT3_COUPLE_COALESCED_H
#define STRUKTURYDANYCHPROJEKT3_COUPLE_COALESCED_H
struct couple_coalesced
{
    int key;
    int value;
    couple_coalesced *next;
    couple_coalesced() : key(0), value(0), next(nullptr) {}//constructors
    couple_coalesced(int k,int v, couple_coalesced *n):key(k),value(v),next(n){}
};
#endif