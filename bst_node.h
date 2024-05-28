#ifndef STRUKTURYDANYCHPROJEKT3_BST_NODE_H
#define STRUKTURYDANYCHPROJEKT3_BST_NODE_H
#include "couple.h"
struct bst_node{
    couple data;
    bst_node* left;
    bst_node* right;
};
#endif
