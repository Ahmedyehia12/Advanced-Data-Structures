#include "maxHeap.h"
#include<queue>
#include<iostream>
using namespace std;
void maxHeap::max_heapify(int i , int sz) {
    int left = get_left_child(i);
    int right = get_right_child(i);
    int largest = i;
    if(left < sz && left>=0 && arr[left].getGpa() > arr[i].getGpa()){
        largest = left;
    }
    if(right < sz && right>=0&& arr[right].getGpa() > arr[largest].getGpa()){
        largest = right;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        max_heapify(largest , sz);
    }
}
void maxHeap::bottom_up_heapify(int i) {
    int parent = (i - 1) / 2;
    if(parent < 0)
        return;
    if (arr[i].getGpa() > arr[parent].getGpa()) {
        swap(arr[i], arr[parent]);
        bottom_up_heapify(parent);
    }

}
void maxHeap::insert(Student& val) {
    if(size == capacity){
        cout<<"Heap is full"<<endl;
        return;
    }
    arr[size] = val;
    bottom_up_heapify(size);
    size++;
}

Student maxHeap::get_max() {
    if(size == 0){
        cout<<"Heap is empty"<<endl;
        exit(1);
    }
    return arr[0];
}
void maxHeap::extract_max() {
    if(this->size == 0){
        cout<<"Heap is empty"<<endl;
        return;
    }
    swap(arr[0],arr[size-1]);
    size--;
    max_heapify(0,size);
}
void maxHeap::build_max_heap(Student *a, int n) {
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
void maxHeap::print_sorted() {
    Student* cpy = new Student[size];
    int sz = size;
    Student* temp = new Student[size];
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
        cout<<cpy[i].getGpa()<<" ";
        cout<<cpy[i].getId()<<" ";
        cout<<cpy[i].getName()<<endl;
        cout<<cpy[i].getDept()<<endl;
        cout<<endl;
    }
    cout<<endl;
    delete [] cpy;
}
bool maxHeap::search(int val) {
    for(int i = 0; i < size; i++){
        if(arr[i].getId() == val)
            return true;
    }
    return false;
}
vector<Student> maxHeap::heapSort() {
    vector<Student> sorted;
    Student *cpy = new Student[size];
    for(int i = 0 ; i < size ; i++){
        cpy[i] = arr[i];
    }
    int sz = size;
    for(int i = 0 ; i < sz ; i++){
        sorted.push_back(get_max());
        extract_max();
    }
    size = sz;
    for(int i = 0 ; i < size ; i++){
        arr[i] = cpy[i];
    }
    delete [] cpy;
    return sorted;
}
void maxHeap::print() {
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i].getGpa()<<" ";
    }
    cout<<endl;

}





