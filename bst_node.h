#ifndef STRUKTURYDANYCHPROJEKT3_BST_NODE_H
#define STRUKTURYDANYCHPROJEKT3_BST_NODE_H
#include "couple.h"
struct bst_node{
    couple data;//key and value
    bst_node* left;
    bst_node* right;
    int h;//height of node
    bst_node(int k,int v) : data(couple(k,v)), left(nullptr), right(nullptr), h(1) {}
};
#endif
