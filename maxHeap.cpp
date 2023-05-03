#include "maxHeap.h"
#include<queue>
#include<iostream>
using namespace std;
template<class T>
void maxHeap<T>::max_heapify(int i) {
    int left = get_left_child(i);
    int right = get_right_child(i);
    int largest = i;
    if(left < size && arr[left] > arr[i]){
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        max_heapify(largest);
    }
}

template<class T>
void maxHeap<T>::insert(T val) {
    if(size == capacity){
        cout<<"Heap is full"<<endl;
        return;
    }
    size++;
    int i = size-1;
    arr[i] = val;
    while(i >0 && (arr[get_parent(i)] < arr[i])){
        swap(arr[i] , arr[get_parent(i)]);
        i = get_parent(i);
    }

}
template<class T>
void maxHeap<T>::build_max_heap(T *arr, int size) {
    this->size = size;
    this->arr = arr;
    for(int i = size/2 ; i >= 0 ; i--){
        max_heapify(i);
    }
}
template<class T>
void maxHeap<T>::print_sorted() {
priority_queue<T> q;
    for(int i=0;i<this->size;i++){
        q.push(arr[i]);
    }
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;

}





