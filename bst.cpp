#include "bst.h"
#include "bst_node.h"
#include<iostream>
#include <algorithm>

using namespace std;

BST::BST() {
    root = nullptr;//root of the tree
    size = 0;
}

int BST::get_h(bst_node *n) {//get height of the node
    if(n == nullptr)
        return 0;
    return n->h;
}

int BST::get_balance(bst_node *n) {//get balance of the node
    if(n == nullptr)
        return 0;
    return get_h(n->left) - get_h(n->right);//left height - right height
}

bst_node *BST::rotate_right(bst_node *n) {
    bst_node* x = n->left;//left child of n
    bst_node* y = x->right;//right child of x

    x->right = n;
    n->left = y;

    n->h = max(get_h(n->left), get_h(n->right)) + 1;//update height
    x->h = max(get_h(x->left), get_h(x->right)) + 1;

    return x;
}

bst_node *BST::rotate_left(bst_node *n) {
    bst_node* x = n->right;//right child of n
    bst_node* y = x->left;//left child of x

    x->left = n;
    n->right = y;

    n->h = max(get_h(n->left), get_h(n->right)) + 1;//update height
    x->h = max(get_h(x->left), get_h(x->right)) + 1;

    return x;
}

bst_node *BST::insert(bst_node *n, couple &new_node) {
    if (n == nullptr) {
        size++;
        return new bst_node(new_node.key ,new_node.value);
    }

    if (new_node.key < n->data.key)
        n->left = insert(n->left, new_node);
    else if (new_node.key > n->data.key)
        n->right = insert(n->right, new_node);
    else
    {
        n->data.value = new_node.value;
        return n;
    }


    n->h = 1 + max(get_h(n->left), get_h(n->right));

    int balance = get_balance(n);

    if (balance > 1 && new_node.key < n->left->data.key)
        return rotate_right(n);

    if (balance < -1 && new_node.key > n->right->data.key)
        return rotate_left(n);

    if (balance > 1 && new_node.key > n->left->data.key) {
        n->left = rotate_left(n->left);
        return rotate_right(n);
    }

    if (balance < -1 && new_node.key < n->right->data.key) {
        n->right = rotate_right(n->right);
        return rotate_left(n);
    }

    return n;
}


bst_node *BST::balance(bst_node *n) {
    int balance = get_balance(n);

    if(balance > 1 && get_balance(n->left) >= 0)
        return rotate_right(n);

    if(balance > 1 && get_balance(n->left) < 0)
    {
        n->left = rotate_left(n->left);
        return rotate_right(n);
    }

    if(balance < -1 && get_balance(n->right) <= 0)
        return rotate_left(n);

    if(balance < -1 && get_balance(n->right) > 0)
    {
        n->right = rotate_right(n->right);
        return rotate_left(n);
    }

    return n;
}

bst_node *BST::remove(bst_node *n, int key) {
    if(n == nullptr)
        return n;

    if(key < n->data.key)
        n->left = remove(n->left,key);
    else if(key > n->data.key)
        n->right = remove(n->right,key);
    else
    {
        if(n->left == nullptr || n->right == nullptr)
        {
            bst_node* temp = n->left ? n->left : n->right;

            if(temp == nullptr)
            {
                temp = n;
                n = nullptr;
            }
            else
                *n = *temp;

            delete temp;
        }
        else
        {
            bst_node* temp = n->right;
            while(temp->left != nullptr)
                temp = temp->left;

            n->data = temp->data;
            n->right = remove(n->right,temp->data.key);
        }
    }

    if(n == nullptr) return n;

    n->h = 1 + max(get_h(n->left), get_h(n->right));

    return balance(n);
}

bst_node *BST::search(bst_node *n, int key) {
    if(n == nullptr and n->data.key == key) return n;
    if(n->data.key < key) return search(n->right,key);
    return search(n->left,key);
}

void BST::insert(int key, int value) {
    couple new_node(key,value);
    root = insert(root,new_node);
}

void BST::remove(int key) {
    root = remove(root,key);
}

int BST::search(int key) {
    bst_node* temp = search(root,key);
    if(temp == nullptr) return -1;
    return temp->data.value;
}

int BST::get_size() {
    return size;
}

void BST::print(bst_node *n) {
    if(n == nullptr) return;
    print(n->left);
    cout << "Key: " << n->data.key << " Value: " << n->data.value << endl;
    print(n->right);
}

void BST::print() {
    print(root);
}

BST::~BST() {
    delete root;
}