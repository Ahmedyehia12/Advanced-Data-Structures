#include <iostream>
#include "minHeap.cpp"
using namespace std;

int main(){
    minHeap<int> h(10);
    h.insertKey(10);
    h.insertKey(20);
    h.insertKey(30);
    h.insertKey(40);
    h.insertKey(50);
    h.printSorted();
    cout<<endl;
    for(int i = 0 ; i < 5 ; i++){
        cout<<h[i]<<" ";
    }

}