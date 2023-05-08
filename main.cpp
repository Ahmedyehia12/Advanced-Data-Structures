#include <iostream>
#include "AVL.cpp"
#include "BST.cpp"
using namespace std;

int main(){
    AVL<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(50);
    tree.insert(25);
    tree.insert(35);
    tree.insert(45);
    tree.erase(20);
    tree.print(tree.get_root());


}