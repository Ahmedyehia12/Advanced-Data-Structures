#include <iostream>
#include<fstream>
#include<map>
#include "BST.cpp"
#include "Student.h"
#include "AVL.cpp"
#include "minHeap.cpp"
#include "maxHeap.cpp"
using namespace std;

int main(){
    BST<int> bst;
    AVL<int> avl;
    minHeap<int> minHeap(100);
    maxHeap<int> maxHeap(100);
    map<int,Student> m;
    map<string , int>dept;
    int n , id ;
    string name , department;
    ifstream in("input.txt");
    // print file

   while(true){
   cout<<"choose data structure :"<<endl;
   cout<<"1-BST"<<endl;
   cout<<"2-AVL"<<endl;
   cout<<"3-Min Heap"<<endl;
   cout<<"4-Max Heap"<<endl;
   cout<<"5-Exit"<<endl;
   int choice ;
   cin>>choice;
   if(choice == 1){
      cout<<"1-Insert Student"<<endl;
      cout<<"2-remove Student"<<endl;
      cout<<"3-Search Student"<<endl;
      cout<<"4-Print sorted BST"<<endl;
      cout<<"5-return to main menu"<<endl;
      while(true){
          int c;
          cin>>c;
          if(c==1){

          }
          else if(c==2){

          }

      }


   }
   else if(choice ==2){

   }

   else if(choice == 3){


   }
   else if(choice == 4){

   }
   else{
       break;
   }

   }

}