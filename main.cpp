#include <iostream>
#include<fstream>
#include<map>
#include "BST.cpp"
#include "Student.h"
#include "AVL.cpp"
#include "minHeap.cpp"
#include "maxHeap.cpp"
using namespace std;

Student operator >> (istream &in , Student &s){
    int id ;
    string name ;
    double gpa;
    string dept;
    in>>id>>name>>gpa>>dept;
    s.setId(id);
    s.setName(name);
    s.setGpa(gpa);
    s.setDept(dept);
    return s;
}

bool operator >(Student &s1 , Student &s2){
    return s1.getId() > s2.getId();
}
bool operator <(Student &s1 , Student &s2){
    return s1.getId() < s2.getId();
}
bool operator ==(Student &s1 , Student &s2){
    return s1.getId() == s2.getId();
}
bool operator !=(Student &s1 , Student &s2){
    return s1.getId() != s2.getId();
}
bool operator >=(Student &s1 , Student &s2){
    return s1.getId() >= s2.getId();
}
bool operator <=(Student &s1 , Student &s2){
    return s1.getId() <= s2.getId();
}




int main(){
    BST<Student> bst;
    AVL<Student> avl;
    minHeap<Student>minHeap(100);
    maxHeap<Student>maxHeap(100);
    map<string , int>dept;
    ifstream in("input.txt");
    Student s;
    while(in>>s){

    }
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