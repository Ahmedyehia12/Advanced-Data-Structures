#ifndef DS_ASSIGN3_MINHEAP_H
#define DS_ASSIGN3_MINHEAP_H
#include <bits/stdc++.h>
#include "Student.h"
using namespace std;
class minHeap {
private:
    Student *arr;
    int capacity;
    int size;
public:
    minHeap(int capacity);
    int parent(int i);
    int left(int i);
    int right(int i);
    Student getMin();
    void extractMin();
    void insertKey(Student k);
    void MinHeapify(int i , int n);
    void buildMinHeap(Student *a, int n);
    void bottomUpHeapify(int i);
    int getSize();
    int getCapacity();
    vector<Student> heapSort();
    bool search(int id);

    Student& operator[](int i){
        if(i >= size){
            cout<<"Index out of bounds"<<endl;
            exit(1);
        }
        return arr[i];
    }

};



#endif //DS_ASSIGN3_MINHEAP_H
