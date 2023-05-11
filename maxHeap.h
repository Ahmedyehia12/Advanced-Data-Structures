#ifndef DS_ASSIGN3_MAXHEAP_H
#define DS_ASSIGN3_MAXHEAP_H
#include "Student.h"
#include <bits/stdc++.h>
using namespace std;
class maxHeap {
private:
    int size;
    Student *arr;
    int capacity;
public:
    maxHeap(int sz){
        size = 0;
        capacity = sz;
        arr = new Student[capacity];
    };
    int get_parent(int i){
        if(i == 0)
            return -1;
        return (i-1)/2;
    };
    int get_left_child(int i){
        if(2*i+1 >= size)
            return -1;
        return 2*i+1;
    };
    int get_right_child(int i){
        if(2*i+2 >= size)
            return -1;
        return 2*i+2;
    };
    int get_size(){
        return size;
    };
    void max_heapify(int i , int size);
    void bottom_up_heapify(int i);
    void insert(Student& val);
    void build_max_heap(Student *a , int n);
    void print_sorted();
    void print();
    Student get_max();
    void extract_max();
    bool search(int id);
    vector<Student> heapSort();
    Student&operator[](int i){
        if(i >= size || i < 0)
            throw "Index out of bound";
        return arr[i];
    };


};




#endif //DS_ASSIGN3_MAXHEAP_H
