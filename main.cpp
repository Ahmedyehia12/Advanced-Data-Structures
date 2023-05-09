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
    map<int , Student>std;
    vector<Student>students;
    readData(students);
    for(int i = 0 ; i < students.size() ; i++){
        Student s = students[i];
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
                bst.insert(id);
                cout<<"\nStudent inserted successfully !!\n"<<endl;
          }
          else if(c==2){
              cout<<"Enter Student ID:"<<endl;
              int id;
              cin>>id;
              Student s = std[id];
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
                vector<int>temp;
                vector<int>sorted  = bst.getSorted(temp);
                map<string , int>dep;
                for(int i = 0 ; i < sorted.size() ; i++){
                    dep[std[sorted[i]].getDept()]++;
                    cout<<"ID:"<<sorted[i]<<endl;
                    cout<<"Name:"<<std[sorted[i]].getName()<<endl;
                    cout<<"GPA:"<<std[sorted[i]].getGpa()<<endl;
                    cout<<"Department:"<<std[sorted[i]].getDept()<<endl;
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
              avl.insert(id);
              cout<<"\nStudent inserted successfully !!\n"<<endl;
       }
       else if(c==2){
              cout<<"Enter Student ID:"<<endl;
                  int id;
                  cin>>id;
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
             vector<int>temp;
             vector<int>sorted = avl.getSorted(temp);
             map<string , int>dep;
                for(int i = 0 ; i < sorted.size() ; i++){
                    dep[std[sorted[i]].getDept()]++;
                    cout<<"ID:"<<sorted[i]<<endl;
                    cout<<"Name:"<<std[sorted[i]].getName()<<endl;
                    cout<<"GPA:"<<std[sorted[i]].getGpa()<<endl;
                    cout<<"Department:"<<std[sorted[i]].getDept()<<endl;
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
       cout<<"2-Print sorted Min Heap"<<endl;
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
                  minHeap.insertKey(id);
                  cout<<"\nStudent inserted successfully !!\n"<<endl;
         }
         else if(c==2){
             vector<int>temp = minHeap.heapSort();
             map<string , int>dep;
                for(int i = 0 ; i < temp.size() ; i++){
                    dep[std[temp[i]].getDept()]++;
                    cout<<"ID:"<<temp[i]<<endl;
                    cout<<"Name:"<<std[temp[i]].getName()<<endl;
                    cout<<"GPA:"<<std[temp[i]].getGpa()<<endl;
                    cout<<"Department:"<<std[temp[i]].getDept()<<endl;
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
         cout<<"2-Print sorted Max Heap"<<endl;
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
                    maxHeap.insert(id);
                    cout<<"\nStudent Inserted Successfully !! \n"<<endl;
            }
            else if(c==2){
                vector<int>temp = maxHeap.heapSort();
                map<string , int>dep;
                for(int i = 0 ; i < temp.size() ; i++){
                    dep[std[temp[i]].getDept()]++;
                    cout<<"ID:"<<temp[i]<<endl;
                    cout<<"Name:"<<std[temp[i]].getName()<<endl;
                    cout<<"GPA:"<<std[temp[i]].getGpa()<<endl;
                    cout<<"Department:"<<std[temp[i]].getDept()<<endl;
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