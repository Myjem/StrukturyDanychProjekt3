#ifndef STRUKTURYDANYCHPROJEKT3_BST_H
#define STRUKTURYDANYCHPROJEKT3_BST_H
#include "bst_node.h"

class BST{//AVL binary search tree
private:
    bst_node* root;
    int size;
    int get_h(bst_node* n);//get height of node
    int get_balance(bst_node* n);//get balance of node
    bst_node* rotate_right(bst_node* n);
    bst_node* rotate_left(bst_node* n);
    bst_node* insert(bst_node* n,couple& new_node);
    bst_node* balance(bst_node* n);//balance node
    bst_node* remove(bst_node* n,int key);
    bst_node* search(bst_node* n,int key);
    void print(bst_node* n);


public:
    BST();
    void insert(int key,int value);
    void remove(int key);
    int search(int key);
    void print();
    int get_size();
    ~BST();
};
#endif
