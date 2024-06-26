#ifndef STRUKTURYDANYCHPROJEKT3_BASE_H
#define STRUKTURYDANYCHPROJEKT3_BASE_H
class Base{//base class for all data structures with virtual methods
public:
    virtual void insert(int key,int value)=0;
    virtual void remove(int key)=0;
    virtual void print()=0;
    virtual int get_size()=0;
    virtual ~Base(){};
};
#endif
