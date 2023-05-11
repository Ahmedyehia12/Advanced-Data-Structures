#include "BST.h"
#include <iostream>
using namespace std;
BST::BST() {
    root= nullptr;
}
void BST::clear() {
    root = nullptr;
}

bool BST::isEmpty() {
    return root== nullptr;
}

bool BST::search(int id) {
    BSTNode*p=root;
    while(p!= nullptr){
        if(p->getKey().getId() == id)
            return true;
        else if(id < p->getKey().getId())
            p=p->getLeft();
        else
            p=p->getRight();
    }
    return false;
}

void BST::insert(Student data) {
    BSTNode* newNode = new BSTNode(data);
    if (this->root == nullptr) {
        this->root = newNode;
        return;
    }
    BSTNode* current = this->root;
    while (true) {
        if (data.getId() < current->key.getId()) {
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
vector<Student> BST::getSorted() {
    vector<Student> v;
    print(root,v);
    return v;
}

void BST::print(BSTNode*p , vector<Student>& v) {
    if(p!= nullptr){
        print(p->getLeft(),v);
        v.push_back(p->getKey());
        print(p->getRight(),v);
    }
}

void BST::deleteNode(int el) {
    BSTNode* p=root,*prev= nullptr;
        while(p!=nullptr && p->getKey().getId()!=el){
            prev=p;
            if(el > p->getKey().getId())
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
            BSTNode* child;
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
            BSTNode* minRight = p->right;
            BSTNode* prevMinRight = p;
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
    BSTNode* BST::getRoot() {
    return root;
}




