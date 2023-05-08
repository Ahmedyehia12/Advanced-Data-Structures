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
    }

}
template<class T>
void AVL<T>::erase(T key) {
    AVL_node<T>* temp = this->root;
    AVL_node<T>* node = nullptr;
    while(temp != nullptr){
        if(temp->key == key){
            break;
        }
        else if(key < temp->key){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    if(temp == nullptr){
        return;
    }
    if(temp->left == nullptr && temp->right == nullptr){
        if(temp == this->root){
            this->root = nullptr;
        }
        else if(temp == temp->parent->left){
            temp->parent->left = nullptr;
        }
        else{
            temp->parent->right = nullptr;
        }
        node = temp->parent;
        delete temp;
    }
    else if(temp->left == nullptr){
        if(temp == this->root){
            this->root = temp->right;
            temp->right->parent = nullptr;
        }
        else if(temp == temp->parent->left){
            temp->parent->left = temp->right;
            temp->right->parent = temp->parent;
        }
        else{
            temp->parent->right = temp->right;
            temp->right->parent = temp->parent;
        }
        node = temp->parent;
        delete temp;
    }
    else if(temp->right == nullptr){
        if(temp == this->root){
            this->root = temp->left;
            temp->left->parent = nullptr;
        }
        else if(temp == temp->parent->left){
            temp->parent->left = temp->left;
            temp->left->parent = temp->parent;
        }
        else{
            temp->parent->right = temp->left;
            temp->left->parent = temp->parent;
        }
        node = temp->parent;
        delete temp;
    }
    else{
        AVL_node<T>* temp2 = temp->right;
        while(temp2->left != nullptr){
                temp2 = temp2->left;
            }
        temp->key = temp2->key;
            if(temp2 == temp2->parent->left){
                temp2->parent->left =  nullptr;
            }
            else if(temp2 == temp2->parent->right){
                temp2->parent->right = nullptr;
            }
            node = temp2->parent;
            delete temp2;
    }
    AVL_node<T>* temp3 = node;
    while(node != nullptr){
        node->height = get_height(node);
        node->bf = getBalanceFactor(node);
        node = node->parent;
    }
    while(temp3 != nullptr){
        if(temp3->bf<-1 && temp3->right->bf < 0){
            left_rotate(temp3);
        }
        else if(temp3->bf < -1 && temp3->right->bf > 0){
            right_rotate(temp3->right);
            left_rotate(temp3);
        }
        else if(temp3->bf > 1 && temp3->left->bf > 0){
            right_rotate(temp3);
        }
        else if(temp3->bf > 1 && temp3->left->bf < 0){
            left_rotate(temp3->left);
            right_rotate(temp3);
        }
        temp3 = temp3->parent;
    }

}
template<class T>
void AVL<T>::print_in_order(AVL_node<T> *node) {
    if (node == nullptr) {
        return;
    }
    print(node->left);
    cout << node->key << " ";
    print(node->right);
}


