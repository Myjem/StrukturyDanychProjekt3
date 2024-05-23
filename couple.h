#ifndef STRUKTURYDANYCHPROJEKT3_COUPLE_H
#define STRUKTURYDANYCHPROJEKT3_COUPLE_H
struct couple{
    int key;
    int value;
    couple() : key(0), value(0) {}
    couple(int k,int v):key(k),value(v){}
};
#endif
