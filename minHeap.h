#ifndef DS_ASSIGN3_MINHEAP_H
#define DS_ASSIGN3_MINHEAP_H
#include <bits/stdc++.h>
using namespace std;
template <class T>
class minHeap {
private:
    T *arr;
    int capacity;
    int size;
public:
    minHeap(int capacity);
    int parent(int i);
    int left(int i);
    int right(int i);
    int getMin();
    void extractMin();
    void insertKey(T k);
    void MinHeapify(int i , int n);
    void buildMinHeap(T *a, int n);
    void bottomUpHeapify(int i);
    int getSize();
    int getCapacity();
    void printSorted();
    vector<T> heapSort();

    T& operator[](int i){
        if(i >= size){
            cout<<"Index out of bounds"<<endl;
            exit(1);
        }
        return arr[i];
    }

};



#endif //DS_ASSIGN3_MINHEAP_H
