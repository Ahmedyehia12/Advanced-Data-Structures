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
T maxHeap<T>::get_max() {
    if(size == 0){
        cout<<"Heap is empty"<<endl;
        return -1;
    }
    return arr[0];
}
template<class T>
void maxHeap<T>::extract_max() {
    if(this->size == 0){
        cout<<"Heap is empty"<<endl;
        return;
    }
    swap(arr[0],arr[size-1]);
    size--;
    max_heapify(0,size);
}
template<class T>
void maxHeap<T>::build_max_heap(T *a, int n) {
    if(n > capacity){
        cout<<"Heap capacity is less than array size"<<endl;
        return;
    }
    size = n;
    for(int i = 0 ; i < n ; i++){
        arr[i] = a[i];
    }
    for(int i = n/2 ; i >= 0 ; i--){
        max_heapify(i,n);
    }
}
template<class T>
void maxHeap<T>::print_sorted() {
    T* cpy = new T[size];
    int sz = size;
    T* temp = new T[size];
    for(int i = 0 ; i < sz ; i++){
        temp[i] = arr[i];
    }
    for(int i = 0 ; i < sz ; i++){
        cpy[i] = arr[0];
        extract_max();
    }
    cout<<endl;
    size = sz;
    for(int i = 0 ; i < sz ; i++){
        arr[i] = temp[i];
    }
    delete [] temp;
    for(int i = sz-1 ; i >=0 ; i--){
        cout<<cpy[i]<<' ';
    }
    cout<<endl;
    delete [] cpy;
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
}
}
template<class T>
void maxHeap<T>::print() {
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;

}





