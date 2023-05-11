#ifndef DS_ASSIGN3_STUDENT_H
#define DS_ASSIGN3_STUDENT_H
#include<iostream>;
using namespace std;

class Student {
private:
    int id ;
    string name ;
    double gpa;
    string dept;
public:
    Student(){
        id = 0;
        name = "";
        gpa = 0;
        dept = "";
    }
    Student(int id, string name, double gpa, string dept){
        this->id = id;
        this->name = name;
        this->gpa = gpa;
        this->dept = dept;
    }
    string getDept(){
        return dept;
    }
    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
    double getGpa(){
        return gpa;
    }
    void setDept(string dept){
        this->dept = dept;
    }
    void setId(int id){
        this->id = id;
    }
    void setName(string name){
        this->name = name;
    }
    void setGpa(double gpa){
        this->gpa = gpa;
    }
};


#endif //DS_ASSIGN3_STUDENT_H
