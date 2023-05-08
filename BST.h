//
// Created by Mohannad on 03-May-23.
//

#ifndef STUDY_BST_H
#define STUDY_BST_H


template <class T>
class BSTNode{
public:
    T key;
    BSTNode* left;
    BSTNode* right;

    BSTNode(T& el){
        key = el;
        left= nullptr;
        right= nullptr;
    }
    BSTNode<T>* getLeft(){return left;}
    BSTNode<T>* getRight(){return right;}
    T& getKey(){return key;}

};


template <class T>
class BST{
private:
    BSTNode<T>* root;
public:

    BST();
    void clear();
    bool isEmpty();
    bool search(T el);
    void insert(T data);
    void print(BSTNode<T>* p);
    void deleteNode(T el);
    BSTNode<T>*  getRoot();
};



#endif //STUDY_BST_H
