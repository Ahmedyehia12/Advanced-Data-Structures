#include "maxHeap.h"
#include<queue>
#include<iostream>
using namespace std;
template<class T>
void maxHeap<T>::max_heapify(int i , int sz) {
    int left = get_left_child(i);
    int right = get_right_child(i);
    int largest = i;
    if(left < sz && left>=0 && arr[left] > arr[i]){
        largest = left;
    }
    if(right < sz && right>=0&& arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        max_heapify(largest , sz);
    }
}
template<class T>
void maxHeap<T>::bottom_up_heapify(int i) {
    int parent = (i - 1) / 2;
    if(parent < 0)
        return;

    if (arr[i] > arr[parent]) {
        swap(arr[i], arr[parent]);
        bottom_up_heapify(parent);
    }

}

template<class T>
void maxHeap<T>::insert(T val) {
    if(size == capacity){
        cout<<"Heap is full"<<endl;
        return;
    }
    arr[size] = val;
    bottom_up_heapify(size);
    size++;
}
template<class T>
void maxHeap<T>::build_max_heap(T *arr, int size) {
    this->size = size;
    this->arr = arr;
    for(int i = size/2 ; i >= 0 ; i--){
        max_heapify(i , size);
    }
}
template<class T>
void maxHeap<T>::print_sorted() {
    priority_queue<T>q;
    for(int i=0;i<size;i++){
        q.push(-arr[i]);
    }
    while(!q.empty()){
        cout<<(-q.top())<<' ';
        q.pop();
    }
    cout<<endl;
}
template<class T>
void maxHeap<T>::heapSort() {
int cpy = this->size;
swap(arr[0],arr[cpy-1]);
cpy--;
max_heapify(0,cpy);
while(cpy>0){
    swap(arr[0],arr[cpy-1]);
    cpy--;
    max_heapify(0,cpy);
}}
template<class T>
void maxHeap<T>::print() {
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;

}





