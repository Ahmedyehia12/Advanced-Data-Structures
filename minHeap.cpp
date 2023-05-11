#include "minHeap.h"
using namespace std;

minHeap::minHeap(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->arr = new Student[capacity];
}

int minHeap::parent(int i) {
    if((i-1)/2 <0){
        return -1;
    }
    return (i - 1) / 2;
}
int minHeap::left(int i) {
    if(2*i+1 >= size){
        return -1;
    }
    return 2 * i + 1;
}

int minHeap::right(int i) {
    if(2*i+2 >= size){
        return -1;
    }
    return 2 * i + 2;
}

Student minHeap::getMin() {
    if(size == 0){
        cout<<"Heap is empty"<<endl;
        exit(1);
    }
    return arr[0];
}

void minHeap::extractMin() {
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
vector<Student> minHeap::heapSort() {
    Student *temp = new Student[size];
    int sz = size;
    for(int i = 0; i < sz; i++){
        temp[i] = arr[i];
    }
    vector<Student>sorted;
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

bool minHeap::search(int val) {
    for(int i = 0; i < size; i++){
        if(arr[i].getId() == val){
            return true;
        }
    }
    return false;
}
void minHeap::MinHeapify(int i, int n) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l != -1 && arr[l].getGpa() < arr[i].getGpa()){
        smallest = l;
    }
    if(r != -1 && arr[r].getGpa() < arr[smallest].getGpa()){
        smallest = r;
    }
    if(smallest != i){
        swap(arr[i],arr[smallest]);
        MinHeapify(smallest,n);
    }
}
void minHeap::insertKey(Student k) {
    if(size == capacity){
        cout<<"Heap is full"<<endl;
        return;
    }
    size++;
    arr[size-1] = k;
    bottomUpHeapify(size-1);
}
void minHeap::bottomUpHeapify(int i) {
    if(i == 0){
        return;
    }
    int p = parent(i);
    if(arr[p].getGpa() > arr[i].getGpa()){
        swap(arr[p],arr[i]);
        bottomUpHeapify(p);
    }
}
void minHeap::buildMinHeap(Student *a, int n) {
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
int minHeap::getSize() {
    return size;
}

int minHeap::getCapacity() {
    return capacity;
}



