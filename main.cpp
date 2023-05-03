#include <iostream>
#include "maxHeap.cpp"
using namespace std;

int main(){
    maxHeap<int> h(10);
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);
    h.insert(60);
    h.insert(70);
    h.insert(80);
    for(int i=0;i<h.get_size()/2;i++){
      cout<<h[i]<<' '<<h[h.get_left_child(i)]<<' '<<h[h.get_right_child(i)]<<endl;
    }
}