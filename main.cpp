#include <iostream>
#include<fstream>
#include<map>
#include "BST.cpp"
#include "Student.h"
#include "AVL.cpp"
#include "minHeap.cpp"
#include "maxHeap.cpp"
using namespace std;


void readData(vector<Student> &students){
    ifstream file("input.txt");
    int n;
    file >> n;
    for(int i = 0 ; i < n ; i++){
        string name,dept;
        int id;
        double gpa;
        file >>id;
        file.ignore();
        getline(file,name);
        file >> gpa >> dept;
        students.push_back(Student(id,name,gpa,dept));
    }
    file.close();
}
int main(){
    BST<int> bst;
    AVL<int> avl;
    minHeap<int>minHeap(100);
    maxHeap<int>maxHeap(100);
    map<string , int>dep;
    map<int , Student>std;
    vector<Student>students;
    readData(students);
    for(int i = 0 ; i < students.size() ; i++){
        Student s = students[i];
        if(std.find(s.getId()) == std.end())
            dep[s.getDept()]++;
        std[s.getId()] = s;
        bst.insert(s.getId());
        avl.insert(s.getId());
        minHeap.insertKey(s.getId());
        maxHeap.insert(s.getId());
    }
    while(true){
        cout<<"Choose Data Structure: "<<endl;
       cout<<"1-BST"<<endl;
       cout<<"2-AVL"<<endl;
       cout<<"3-Min Heap"<<endl;
       cout<<"4-Max Heap"<<endl;
       cout<<"5-Exit"<<endl;
   int choice ;
   cin>>choice;
   if(choice == 1){
      while(true){
      cout<<"1-Insert Student"<<endl;
      cout<<"2-Remove Student"<<endl;
      cout<<"3-Search Student"<<endl;
      cout<<"4-Print sorted BST"<<endl;
      cout<<"5-Return to Main Menu"<<endl;
          int c;
          cin>>c;
          if(c==1){
              Student s;
              cout<<"Enter Student ID:"<<endl;
              int id;
              cin>>id;
              while(std.find(id)!=std.end()){
                  cout<<"ID already exists!"<<endl;
                  cout<<"Enter Student ID:"<<endl;
                  cin>>id;
                }
              s.setId(id);
              cout<<"Enter student name: "<<endl;
                string name;
                cin>>name;
                s.setName(name);
                cout<<"Enter student gpa:"<<endl;
                double gpa;
                cin>>gpa;
                s.setGpa(gpa);
                cout<<"Enter student department:"<<endl;
                string dept;
                cin>>dept;
                s.setDept(dept);
                dep[dept]++;
                std[id] = s;
                bst.insert(id);
          }
          else if(c==2){
              cout<<"Enter student ID:"<<endl;
              int id;
              cin>>id;
              Student s = std[id];
              dep[s.getDept()]--;
              std.erase(id);
              bst.deleteNode(id);
          }
          else if(c==3){
                cout<<"Enter student ID:"<<endl;
                int id;
                cin>>id;
                if(bst.search(id)){
                    cout<<"Student found"<<endl;
                    cout<<"ID:"<<id<<endl;
                    cout<<"Name:"<<std[id].getName()<<endl;
                    cout<<"GPA:"<<std[id].getGpa()<<endl;
                    cout<<"Department:"<<std[id].getDept()<<endl;
                }
                else{
                    cout<<"Student not found!"<<endl;
                }
            }
            else if(c==4){
                vector<int>temp;
                vector<int>sorted  = bst.getSorted(temp);
                for(int i = 0 ; i < sorted.size() ; i++){
                    cout<<"ID:"<<sorted[i]<<endl;
                    cout<<"Name:"<<std[sorted[i]].getName()<<endl;
                    cout<<"GPA:"<<std[sorted[i]].getGpa()<<endl;
                    cout<<"Department:"<<std[sorted[i]].getDept()<<endl;
                    if(i!=sorted.size()-1)
                        cout<<endl;
                }
                cout<<endl;
            }
            else{
                break;
            }

      }
   }
   else if(choice ==2){
       while(true){
       cout<<"1-Insert Student"<<endl;
       cout<<"2-remove Student"<<endl;
       cout<<"3-Search Student"<<endl;
       cout<<"4-Print sorted AVL"<<endl;
       cout<<"5-return to main menu"<<endl;
       int c;
       cin>>c;
       if(c==1){
           Student s;
           cout<<"enter student id:"<<endl;
              int id;
              cin>>id;
              while(std.find(id)!=std.end()){
                  cout<<"id already exists"<<endl;
                  cout<<"enter student id:"<<endl;
                  cin>>id;
              }
              s.setId(id);
              cout<<"enter student name:"<<endl;
              string name;
              cin>>name;
              s.setName(name);
              cout<<"enter student gpa:"<<endl;
              double gpa;
              cin>>gpa;
              s.setGpa(gpa);
              cout<<"enter student dept:"<<endl;
              string dept;
              cin>>dept;
              s.setDept(dept);
              dep[dept]++;
              std[id] = s;
              avl.insert(id);
              cout<<"student inserted successfully"<<endl;
       }
       else if(c==2){
              cout<<"enter student id:"<<endl;
                  int id;
                  cin>>id;
                  Student s = std[id];
                  dep[s.getDept()]--;
                  std.erase(id);
                  avl.erase(id);
                  cout<<"student deleted successfully"<<endl;
         }
         else if(c==3){
              cout<<"enter student id:"<<endl;
                 int id;
                 cin>>id;
                 if(avl.search(id)){
                      cout<<"student found"<<endl;
                      cout<<"id:"<<id<<endl;
                      cout<<"name:"<<std[id].getName()<<endl;
                      cout<<"gpa:"<<std[id].getGpa()<<endl;
                      cout<<"dept:"<<std[id].getDept()<<endl;
                 }
                 else{
                      cout<<"student not found"<<endl;
                 }
         }
         else if(c==4){
             vector<int>temp;
             vector<int>sorted = avl.getSorted(temp);
                for(int i = 0 ; i < sorted.size() ; i++){
                    cout<<"id:"<<sorted[i]<<endl;
                    cout<<"name:"<<std[sorted[i]].getName()<<endl;
                    cout<<"gpa:"<<std[sorted[i]].getGpa()<<endl;
                    cout<<"dept:"<<std[sorted[i]].getDept()<<endl;
                    if(i!=sorted.size()-1)
                        cout<<endl;
                }
                cout<<endl;
         }
         else{
              break;
         }}
   }
   else if(choice == 3){
       while(true){
       cout<<"1 -add student"<<endl;
       cout<<"2 -print sorted min heap"<<endl;
       cout<<"3 -return to the main menu"<<endl;
       int c;
       cin>>c;
       if(c==1){
              Student s;
              cout<<"enter student id:"<<endl;
                  int id;
                  cin>>id;
                  while(std.find(id)!=std.end()){
                      cout<<"id already exists"<<endl;
                      cout<<"enter student id:"<<endl;
                      cin>>id;
                    }
                  s.setId(id);
                  cout<<"enter student name:"<<endl;
                  string name;
                  cin>>name;
                  s.setName(name);
                  cout<<"enter student gpa:"<<endl;
                  double gpa;
                  cin>>gpa;
                  s.setGpa(gpa);
                  cout<<"enter student dept:"<<endl;
                  string dept;
                  cin>>dept;
                  s.setDept(dept);
                  dep[dept]++;
                  std[id] = s;
                  minHeap.insertKey(id);
                  cout<<"student inserted successfully"<<endl;
         }
         else if(c==2){
             vector<int>temp = minHeap.heapSort();
                for(int i = 0 ; i < temp.size() ; i++){
                    cout<<"id:"<<temp[i]<<endl;
                    cout<<"name:"<<std[temp[i]].getName()<<endl;
                    cout<<"gpa:"<<std[temp[i]].getGpa()<<endl;
                    cout<<"dept:"<<std[temp[i]].getDept()<<endl;
                    if(i!=temp.size()-1)
                        cout<<endl;
                }
                cout<<endl;
         }

         else{
              break;
       }}
   }
   else if(choice == 4){
       while(true){
         cout<<"1 - add student"<<endl;
         cout<<"2 - print sorted max heap by gpa"<<endl;
         cout<<"3 - return to main menu"<<endl;
         int c;
         cin>>c;
         if(c==1){
                  Student s;
                  cout<<"enter student id:"<<endl;
                    int id;
                    cin>>id;
                    s.setId(id);
                    cout<<"enter student name:"<<endl;
                    string name;
                    cin>>name;
                    s.setName(name);
                    cout<<"enter student gpa:"<<endl;
                    double gpa;
                    cin>>gpa;
                    s.setGpa(gpa);
                    cout<<"enter student dept:"<<endl;
                    string dept;
                    cin>>dept;
                    s.setDept(dept);
                    dep[dept]++;
                    std[id] = s;
                    maxHeap.insert(id);
                    cout<<"student inserted successfully"<<endl;
            }
            else if(c==2){
                vector<int>temp = maxHeap.heapSort();
                for(int i = 0 ; i < temp.size() ; i++){
                    cout<<"id:"<<temp[i]<<endl;
                    cout<<"name:"<<std[temp[i]].getName()<<endl;
                    cout<<"gpa:"<<std[temp[i]].getGpa()<<endl;
                    cout<<"dept:"<<std[temp[i]].getDept()<<endl;
                    if(i!=temp.size()-1)
                        cout<<endl;
                }
                cout<<endl;
            }
            else{
                  break;
         }
       }
   }
   else{
       break;
   }
    }
    cout<<"departments:"<<endl;
    for(auto it = dep.begin();it!=dep.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

}