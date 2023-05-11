#ifndef DS_ASSIGN3_AVL_H
#define DS_ASSIGN3_AVL_H
#include<bits/stdc++.h>
#include "Student.h"
using namespace std;
struct AVL_node{
    Student key;
    AVL_node* parent;
    AVL_node* left;
    AVL_node* right;
    int bf;
    int height;
    AVL_node(Student& data){
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        key = data;
        bf  = 0;
        height = 1;
    }
};
class AVL {
private:
    AVL_node * root;
public:
    AVL(){
        root = nullptr;
    }
    AVL_node* get_root(){
        return root;
    }
    int max(int a , int b){
        return (a > b) ? a : b;
    }
    int get_height(AVL_node* node);
    int getBalanceFactor(AVL_node* node);
    void right_rotate(AVL_node* node);
    void left_rotate(AVL_node* node);
    void insert(Student key);
    void erase(int key);
    bool search(int key);
    vector<Student> getSorted();
    void inorder(AVL_node* node , vector<Student>&v);

};






#endif //DS_ASSIGN3_AVL_H
