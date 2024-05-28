#ifndef STRUKTURYDANYCHPROJEKT3_BST_H
#define STRUKTURYDANYCHPROJEKT3_BST_H
#include "bst_node.h"

class BST{
private:
    bst_node* root;
    int size;
public:
    BST();
    void insert(int key,int value);
    void remove(int key);
    bst_node search(int key);
    int get_size();
    ~BST();
};
#endif
