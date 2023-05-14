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
    BST bst;
    AVL avl;
    minHeap minHeap(100);
    maxHeap maxHeap(100);
    map<int , Student>std;
    vector<Student>students;
    students.clear();
    readData(students);
    for(int i = 0 ; i < students.size() ; i++){
        Student s = students[i];
        std[s.getId()] = s;
        bst.insert(s);
        avl.insert(s);
        minHeap.insertKey(s);
        maxHeap.insert(s);
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
              while(bst.search(id)){
                  cout<<"ID already exists!"<<endl;
                  cout<<"Enter Student ID:"<<endl;
                  cin>>id;
                }
                s.setId(id);
               cout<<"Enter Student Name: "<<endl;
                string name;
                cin>>name;
                s.setName(name);
                cout<<"Enter Student GPA:"<<endl;
                double gpa;
                cin>>gpa;
                s.setGpa(gpa);
                cout<<"Enter Student Department:"<<endl;
                string dept;
                cin>>dept;
                s.setDept(dept);
                std[id] = s;
                bst.insert(s);
                cout<<"\nStudent inserted successfully !!\n"<<endl;
          }
          else if(c==2){
              cout<<"Enter Student ID:"<<endl;
              int id;
              cin>>id;
              if(!bst.search(id)){
                  cout<<"\nStudent not found!\n"<<endl;
                  continue;
              }
              std.erase(id);
              bst.deleteNode(id);
                cout<<"\nStudent deleted successfully !!\n"<<endl;
          }
          else if(c==3){
                cout<<"Enter Student ID:"<<endl;
                int id;
                cin>>id;
                if(bst.search(id)){
                    cout<<"\nStudent found"<<endl;
                    cout<<"ID:"<<id<<endl;
                    cout<<"Name:"<<std[id].getName()<<endl;
                    cout<<"GPA:"<<std[id].getGpa()<<endl;
                    cout<<"Department:"<<std[id].getDept()<<endl;
                    cout<<endl;
                }
                else{
                    cout<<"\nStudent not found!\n"<<endl;
                }
            }
            else if(c==4){
                map<string , int>dep;
                vector<Student> sorted = bst.getSorted();
                for(int i = 0 ; i < sorted.size() ; i++){
                    Student s = sorted[i];
                    cout<<"ID:"<<s.getId()<<endl;
                    cout<<"Name:"<<s.getName()<<endl;
                    cout<<"GPA:"<<s.getGpa()<<endl;
                    cout<<"Department:"<<s.getDept()<<endl;
                    dep[s.getDept()]++;
                    if(i!=sorted.size()-1)
                        cout<<endl;
                }
                cout<<endl;
                cout<<"Number of students in each department in BST:"<<endl;
                for(auto it = dep.begin() ; it != dep.end() ; it++){
                    cout<<it->first<<" "<<it->second<<endl;
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
       cout<<"2-Remove Student"<<endl;
       cout<<"3-Search Student"<<endl;
       cout<<"4-Print Sorted AVL"<<endl;
       cout<<"5-Return to Main Menu"<<endl;
       int c;
       cin>>c;
       if(c==1){
           Student s;
           cout<<"Enter Student ID:"<<endl;
              int id;
              cin>>id;
              while(avl.search(id)){
                  cout<<"ID already exists!"<<endl;
                  cout<<"Enter Student ID:"<<endl;
                  cin>>id;
              }
              s.setId(id);
              cout<<"Enter Student Name:"<<endl;
              string name;
              cin>>name;
              s.setName(name);
              cout<<"Enter Student GPA:"<<endl;
              double gpa;
              cin>>gpa;
              s.setGpa(gpa);
              cout<<"Enter Student Department:"<<endl;
              string dept;
              cin>>dept;
              s.setDept(dept);
              std[id] = s;
              avl.insert(s);
              cout<<"\nStudent inserted successfully !!\n"<<endl;
       }
       else if(c==2){
              cout<<"Enter Student ID:"<<endl;
                  int id;
                  cin>>id;
                    if(!avl.search(id)){
                        cout<<"\nStudent not found!\n"<<endl;
                        continue;
                    }
                  Student s = std[id];
                  std.erase(id);
                  avl.erase(id);
                  cout<<"\nStudent deleted successfully \n"<<endl;
         }
         else if(c==3){
              cout<<"\nEnter Student ID:"<<endl;
                 int id;
                 cin>>id;
                 if(avl.search(id)){
                      cout<<"Student Found !"<<endl;
                      cout<<"ID:"<<id<<endl;
                      cout<<"Name:"<<std[id].getName()<<endl;
                      cout<<"GPA:"<<std[id].getGpa()<<endl;
                      cout<<"Department:"<<std[id].getDept()<<endl;
                        cout<<endl;
                 }
                 else{
                      cout<<"\nStudent not found !\n"<<endl;
                 }
         }
         else if(c==4){
             vector<Student>sorted = avl.getSorted();
             map<string , int>dep;
                for(int i = 0 ; i < sorted.size() ; i++){
                    cout<<"ID:"<<sorted[i].getId()<<endl;
                    cout<<"Name:"<<sorted[i].getName()<<endl;
                    cout<<"GPA:"<<sorted[i].getGpa()<<endl;
                    cout<<"Department:"<<sorted[i].getDept()<<endl;
                    dep[sorted[i].getDept()]++;
                    if(i!=sorted.size()-1)
                        cout<<endl;
                }
                cout<<endl;
                cout<<"Number of Students in each department in AVL:"<<endl;
                for(auto it = dep.begin() ; it != dep.end() ; it++){
                    cout<<it->first<<" "<<it->second<<endl;
                }
                cout<<endl;
         }
         else{
              break;
         }}
   }
   else if(choice == 3){
       while(true){
       cout<<"1-Add Student"<<endl;
       cout<<"2-Print sorted by gpa Min Heap"<<endl;
       cout<<"3-Return to the Main Menu"<<endl;
       int c;
       cin>>c;
       if(c==1){
              Student s;
              cout<<"Enter Student ID:"<<endl;
                  int id;
                  cin>>id;
                  while(minHeap.search(id)){
                      cout<<"ID already exists !"<<endl;
                      cout<<"Enter Student ID:"<<endl;
                      cin>>id;
                    }
                  s.setId(id);
                  cout<<"Enter Student Name:"<<endl;
                  string name;
                  cin>>name;
                  s.setName(name);
                  cout<<"Enter Student GPA:"<<endl;
                  double gpa;
                  cin>>gpa;
                  s.setGpa(gpa);
                  cout<<"Enter Student Department:"<<endl;
                  string dept;
                  cin>>dept;
                  s.setDept(dept);
                  std[id] = s;
                  minHeap.insertKey(s);
                  cout<<"\nStudent inserted successfully !!\n"<<endl;
         }
         else if(c==2){
             vector<Student>temp = minHeap.heapSort();
             map<string , int>dep;
                for(int i = 0 ; i < temp.size() ; i++){
                    cout<<"ID:"<<temp[i].getId()<<endl;
                    cout<<"Name:"<<temp[i].getName()<<endl;
                    cout<<"GPA:"<<temp[i].getGpa()<<endl;
                    cout<<"Department:"<<temp[i].getDept()<<endl;
                    dep[temp[i].getDept()]++;
                    if(i!=temp.size()-1)
                        cout<<endl;
                }
                cout<<endl;
                cout<<"Number of Students in each department in Min Heap:"<<endl;
                for(auto it = dep.begin() ; it != dep.end() ; it++){
                    cout<<it->first<<" "<<it->second<<endl;
                }
                cout<<endl;
         }

         else{
              break;
       }}
   }
   else if(choice == 4){
       while(true){
         cout<<"1-Add Student"<<endl;
         cout<<"2-Print Sorted by GPA "<<endl;
         cout<<"3-Return to Main Menu"<<endl;
         int c;
         cin>>c;
         if(c==1){
                  Student s;
                  cout<<"Enter Student ID:"<<endl;
                    int id;
                    cin>>id;
                    while(maxHeap.search(id)){
                        cout<<"ID already exists !"<<endl;
                        cout<<"Enter Student ID:"<<endl;
                        cin>>id;
                    }
                    s.setId(id);
                    cout<<"Enter Student Name:"<<endl;
                    string name;
                    cin>>name;
                    s.setName(name);
                    cout<<"Enter Student GPA:"<<endl;
                    double gpa;
                    cin>>gpa;
                    s.setGpa(gpa);
                    cout<<"Enter Student Department:"<<endl;
                    string dept;
                    cin>>dept;
                    s.setDept(dept);
                    std[id] = s;
                    maxHeap.insert(s);
                    cout<<"\nStudent Inserted Successfully !! \n"<<endl;
            }
            else if(c==2){
                vector<Student>temp = maxHeap.heapSort();
                map<string , int>dep;
                for(int i = 0 ; i < temp.size() ; i++){
                    dep[temp[i].getDept()]++;
                    cout<<"ID:"<<temp[i].getId()<<endl;
                    cout<<"Name:"<<temp[i].getName()<<endl;
                    cout<<"GPA:"<<temp[i].getGpa()<<endl;
                    cout<<"Department:"<<temp[i].getDept()<<endl;
                    if(i!=temp.size()-1)
                        cout<<endl;
                }
                cout<<endl;
                cout<<"Number of Students in each department in Max Heap:"<<endl;
                for(auto it = dep.begin() ; it != dep.end() ; it++){
                    cout<<it->first<<" "<<it->second<<endl;
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

}