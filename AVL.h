#ifndef DS_ASSIGN3_AVL_H
#define DS_ASSIGN3_AVL_H
#include<bits/stdc++.h>
using namespace std;
template <class T>
struct AVL_node{
    T key;
    AVL_node* parent;
    AVL_node* left;
    AVL_node* right;
    int bf;
    int height;
    AVL_node(int data){
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        key = data;
        bf  = 0;
        height = 1;
    }
};
template <class T>
class AVL {
private:
    AVL_node<T> * root;
    vector<T>v;
public:
    AVL(){
        root = nullptr;
    }
    AVL_node<T>* get_root(){
        return root;
    }
    int max(int a , int b){
        return (a > b) ? a : b;
    }
    int get_height(AVL_node<T>* node);
    int getBalanceFactor(AVL_node<T>* node);
    void right_rotate(AVL_node<T>* node);
    void left_rotate(AVL_node<T>* node);
    void insert(T key);
    void erase(T key);
    bool search(T key);
    vector<T> getSorted(vector<T>&v);
    void inorder(AVL_node<T>* node , vector<T>&v);

};






#endif //DS_ASSIGN3_AVL_H
