#include "minHeap.h"
using namespace std;
template<class T>
minHeap<T>::minHeap(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->arr = new T[capacity];
}
template<class T>
int minHeap<T>::parent(int i) {
    if((i-1)/2 <0){
        return -1;
    }
    return (i - 1) / 2;
}
template<class T>
int minHeap<T>::left(int i) {
    if(2*i+1 >= size){
        return -1;
    }
    return 2 * i + 1;
}
template<class T>
int minHeap<T>::right(int i) {
    if(2*i+2 >= size){
        return -1;
    }
    return 2 * i + 2;
}
template<class T>
int minHeap<T>::getMin() {
    if(size == 0){
        cout<<"Heap is empty"<<endl;
        return -1;
    }
    return arr[0];
}
template<class T>
void minHeap<T>::extractMin() {
    if(size == 0){
        cout<<"Heap is empty"<<endl;
        return;
    }
    if(size == 1){
        size--;
        return;
    }
    arr[0] = arr[size-1];
    size--;
    MinHeapify(0,size);
}
template<class T>
vector<T> minHeap<T>::heapSort() {
    T *temp = new T[size];
    int sz = size;
    for(int i = 0; i < sz; i++){
        temp[i] = arr[i];
    }
    vector<T>sorted;
    int n = size;
    for (int i = 0; i < n; ++i) {
        sorted.push_back(getMin());
        extractMin();
    }
    size = sz;
    for(int i = 0; i < size; i++){
        arr[i] = temp[i];
    }
    return sorted;
}

template<class T>
void minHeap<T>::MinHeapify(int i, int n) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l != -1 && arr[l] < arr[i]){
        smallest = l;
    }
    if(r != -1 && arr[r] < arr[smallest]){
        smallest = r;
    }
    if(smallest != i){
        swap(arr[i],arr[smallest]);
        MinHeapify(smallest,n);
    }
}
template<class T>
void minHeap<T>::insertKey(T k) {
    if(size == capacity){
        cout<<"Heap is full"<<endl;
        return;
    }
    size++;
    arr[size-1] = k;
    bottomUpHeapify(size-1);
}
template<class T>
void minHeap<T>::bottomUpHeapify(int i) {
    if(i == 0){
        return;
    }
    int p = parent(i);
    if(arr[p] > arr[i]){
        swap(arr[p],arr[i]);
        bottomUpHeapify(p);
    }
}
template<class T>
void minHeap<T>::buildMinHeap(T *a, int n) {
    if(n > capacity){
        cout<<"Heap capacity is less than array size"<<endl;
        return;
    }
    size = n;
    for(int i = 0; i < n; i++){
        arr[i] = a[i];
    }
    for(int i = (n-1)/2; i >= 0; i--){
        MinHeapify(i,n);
    }
}
template<class T>
int minHeap<T>::getSize() {
    return size;
}
template<class T>
int minHeap<T>::getCapacity() {
    return capacity;
}
template<class T>
void minHeap<T>::printSorted() {
    T *temp = new T[size];
    T* cpy = new T[size];
    for(int i = 0; i < size; i++){
        cpy[i] = arr[i];
    }
    int n = size;
    for(int i = 0; i < n; i++){
        temp[i] = arr[0];
        extractMin();
    }
    for(int i = 0; i < n; i++){
        cout<<temp[i]<<" ";
    }
    size = n;
    for(int i = 0; i < n; i++){
        arr[i] = cpy[i];
    }
    delete[] temp;
    delete[] cpy;}


