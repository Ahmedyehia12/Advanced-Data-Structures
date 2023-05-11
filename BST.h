#ifndef STUDY_BST_H
#define STUDY_BST_H
#include <vector>
#include "Student.h"
using namespace std;

class BSTNode{
public:
    Student key;
    BSTNode* left;
    BSTNode* right;

    BSTNode(Student& el){
        key = el;
        left= nullptr;
        right= nullptr;
    }
    BSTNode* getLeft(){return left;}
    BSTNode* getRight(){return right;}
    Student& getKey(){return key;}

};
class BST{
private:
    BSTNode* root;
public:

    BST();
    void clear();
    bool isEmpty();
    bool search(int id);
    void insert(Student data);
    vector<Student> getSorted();
    void print(BSTNode* p , vector<Student>& v);
    void deleteNode(int  el);
    BSTNode*  getRoot();
};





#endif //STUDY_BST_H
