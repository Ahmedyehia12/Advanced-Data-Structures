#ifndef DS_ASSIGN3_MAXHEAP_H
#define DS_ASSIGN3_MAXHEAP_H
template <class T>
class maxHeap {
private:
    int size;
    T *arr;
    int capacity;
public:
    maxHeap(int sz){
        size = 0;
        capacity = sz;
        arr = new T[capacity];
    };
    int get_parent(int i){
        return (i-1)/2;
    };
    int get_left_child(int i){
        return 2*i+1;
    };
    int get_right_child(int i){
        return 2*i+2;
    };
    int get_size(){
        return size;
    };
    void max_heapify(int i);
    void insert(T val);
    void build_max_heap(T *arr , int size);
    void print_sorted();
    T& operator[](int i){
        return arr[i];
    };


};



#endif //DS_ASSIGN3_MAXHEAP_H
