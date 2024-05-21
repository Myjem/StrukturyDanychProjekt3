#ifndef STRUKTURYDANYCHPROJEKT3_BASE_H
#define STRUKTURYDANYCHPROJEKT3_BASE_H
class Base{//base class for all data structures with virtual methods
public:
    virtual void insert(int v,int k)=0;//v-value, k-key
    virtual void remove(int k)=0;//k-key
    virtual ~Base(){};
};
#endif
