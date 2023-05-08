//Author : Mohanad Hisham

#include "BST.h"
#include <iostream>
using namespace std;



template<class T>
BST<T>::BST() {
    root= nullptr;
}

template<class T>
void BST<T>::clear() {
    root = nullptr;
}

template<class T>
bool BST<T>::isEmpty() {
    return root== nullptr;
}

template<class T>
bool BST<T>::search(T el) {
    BSTNode<T>* p=root;
    while(p!= nullptr){
        if(p->getKey() == el)
            return true;
        else if(el < p->getKey())
            p=p->getLeft();
        else
            p=p->getRight();
    }
    return false;
}


template<class T>
void BST<T>::insert(T data) {
    BSTNode<T>* newNode = new BSTNode<T>(data);
    if (this->root == nullptr) {
        this->root = newNode;
        return;
    }
    BSTNode<T>* current = this->root;
    while (true) {
        if (data < current->key) {
            if (current->left == nullptr) {
                current->left = newNode;
                return;
            }
            current = current->left;
        }
        else {
            if (current->right == nullptr) {
                current->right = newNode;
                return;
            }
            current = current->right;
        }
    }
}
template<class T>
vector<T> BST<T>::getSorted(vector<T> &v){
    print(root,v);
    return v;
}
template<class T>
void BST<T>::print(BSTNode<T> *p, vector<T>& v) {
    if(p!= nullptr){
        print(p->getLeft(),v);
        v.push_back(p->getKey());
        print(p->getRight(),v);
    }
}

template<class T>
void BST<T>::deleteNode(T el) {
    BSTNode<T>* p=root,*prev= nullptr;
        while(p!=nullptr && p->getKey()!=el){
            prev=p;
            if(el > p->getKey())
                p=p->right;
            else
                p=p->left;
        }
        if(p==nullptr){
            cout << "Node not found\n";
            return;
        }
        if(p->left==nullptr && p->right==nullptr){
            if(prev==nullptr)
                root = nullptr;
            else if(prev->left==p)
                prev->left=nullptr;
            else
                prev->right=nullptr;
            delete p;
        }
        else if(p->left==nullptr || p->right==nullptr){
            BSTNode<T>* child;
            if(p->left==nullptr)
                child=p->right;
            else
                child=p->left;
            if(prev==nullptr)
                root = child;
            else if(prev->left==p)
                prev->left=child;
            else
                prev->right=child;
            delete p;
        }
        else {
            BSTNode<T>* minRight = p->right;
            BSTNode<T>* prevMinRight = p;
            while (minRight->left != nullptr) {
                prevMinRight = minRight;
                minRight = minRight->left;
            }
            p->key = minRight->key;
            if(minRight == prevMinRight->right){
                prevMinRight->right = nullptr;
            }
            else if(minRight == prevMinRight->left){
                prevMinRight->left = nullptr;
            }
            delete minRight;
        }
    }

template<class T>
BSTNode<T>* BST<T>::getRoot() {
    return root;
}



