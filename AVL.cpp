#include "AVL.h"
using namespace std;
template<class T>
int AVL<T>::get_height(AVL_node<T> *node) {
    int left = 0 , right = 0;
    if(node->left != nullptr){
        left = node->left->height;
    }
    if(node->right != nullptr){
        right = node->right->height;
    }
    return  1 + max(left , right);
}
template<class T>
int AVL<T>::getBalanceFactor(AVL_node<T> *node) {
    int left = 0 , right = 0;
    if(node->left != nullptr){
        left = node->left->height;
    }
    if(node->right != nullptr){
        right = node->right->height;
    }
    return left - right;
}
template<class T>
void AVL<T>::right_rotate(AVL_node<T> *node) {
    AVL_node<T>* temp = node->left;
    node->left = temp->right;
    if(temp->right != nullptr){
        temp->right->parent = node;
    }
    temp->parent = node->parent;
    if(node->parent == nullptr){
        this->root = temp;
    }
    else if(node == node->parent->left){
        node->parent->left = temp;
    }
    else{
        node->parent->right = temp;
    }
    temp->right = node;
    node->parent = temp;
    node->height = get_height(node);
    temp->height = get_height(temp);
    node->bf = getBalanceFactor(node);
    temp->bf = getBalanceFactor(temp);

}
template<class T>
void AVL<T>::left_rotate(AVL_node<T> *node) {
    AVL_node<T>* temp = node->right;
    node->right = temp->left;
    if(temp->left != nullptr){
        temp->left->parent = node;
    }
    temp->parent = node->parent;
    if(node->parent == nullptr){
        this->root = temp;
    }
    else if(node == node->parent->left){
        node->parent->left = temp;
    }
    else{
        node->parent->right = temp;
    }
    temp->left = node;
    node->parent = temp;
    node->height = get_height(node);
    temp->height = get_height(temp);
    node->bf = getBalanceFactor(node);
    temp->bf = getBalanceFactor(temp);
}
template<class T>
void AVL<T>::insert(T key) {
    AVL_node<T> *node = new AVL_node<T>(key);
    if (this->root == nullptr) {
        this->root = node;
        return;
    }
    AVL_node<T> *temp = this->root;
    while (true) {
        if (key < temp->key) {
            if (temp->left == nullptr) {
                temp->left = node;
                node->parent = temp;
                break;
            }
            temp = temp->left;
        } else {
            if (temp->right == nullptr) {
                temp->right = node;
                node->parent = temp;
                break;
            }
            temp = temp->right;
        }
    }
    while(temp != nullptr){
        temp->height = get_height(temp);
        temp->bf = getBalanceFactor(temp);
        temp = temp->parent;
    }
    temp = node->parent;
    while(temp!= nullptr){
        if(temp->bf < -1 && temp->right->bf < 0){
            left_rotate(temp);
        }
        else if(temp->bf < -1 && temp->right->bf > 0){
            right_rotate(temp->right);
            left_rotate(temp);
        }
        else if(temp->bf > 1 && temp->left->bf > 0){
            right_rotate(temp);
        }
        else if(temp->bf > 1 && temp->left->bf < 0){
            left_rotate(temp->left);
            right_rotate(temp);
        }
        temp = temp->parent;
    }}
template<class T>
void AVL<T>::erase(T key) {


}

template<class T>
void AVL<T>::print_sorted() {
    stack<AVL_node<T>*> s;
    AVL_node<T>* temp = this->root;
    while(temp != nullptr){
        s.push(temp);
        temp = temp->left;
    }
    while(!s.empty()){
        temp = s.top();
        s.pop();
        cout << temp->key << " ";
        temp = temp->right;
        while(temp != nullptr){
            s.push(temp);
            temp = temp->left;
        }
    }
    cout << endl;

}

