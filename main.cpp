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
int main(){
    BST<int> bst;
    AVL<int> avl;
    minHeap<int>minHeap(100);
    maxHeap<int>maxHeap(100);
    map<string , int>dep;
    map<int , Student>std;
    ifstream file("input.txt");
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << '\n';
        }
        file.close();
    }
    else{
        cout<<"file not found"<<endl;
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
      while(true){
      cout<<"1-Insert Student"<<endl;
      cout<<"2-remove Student"<<endl;
      cout<<"3-Search Student"<<endl;
      cout<<"4-Print sorted BST"<<endl;
      cout<<"5-return to main menu"<<endl;
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
                bst.insert(id);
          }
          else if(c==2){
              cout<<"enter student id:"<<endl;
              int id;
              cin>>id;
              Student s = std[id];
              dep[s.getDept()]--;
              std.erase(id);
              bst.deleteNode(id);
          }
          else if(c==3){
                cout<<"enter student id:"<<endl;
                int id;
                cin>>id;
                if(bst.search(id)){
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
                bst.print(bst.getRoot());
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
            avl.print(avl.get_root());
            cout<<endl;
         }
         else{
              break;
         }}
   }
   else if(choice == 3){
       while(true){
       cout<<"1 - add student"<<endl;
       cout<<"2 - print sorted min heap"<<endl;
       cout<<"3 - return to the main menu"<<endl;
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
                  minHeap.insertKey(id);
                  cout<<"student inserted successfully"<<endl;
         }
         else if(c==2){
              minHeap.printSorted();
              cout<<endl;
         }

         else{
              break;
       }}
   }
   else if(choice == 4){
       while(true){
         cout<<"1 - add student"<<endl;
         cout<<"2 - print sorted max heap"<<endl;
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
                  maxHeap.print_sorted();
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