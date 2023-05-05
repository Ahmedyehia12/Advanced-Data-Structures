#include <iostream>
#include "AVL.cpp"
using namespace std;

int main(){
    AVL<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    tree.insert(35);
    tree.print();

}