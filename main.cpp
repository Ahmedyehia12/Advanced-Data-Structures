#include <iostream>
#include "BST.cpp"
using namespace std;

int main(){
    BST<int> bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.deleteNode(5);
    bst.print(bst.getRoot());

}