#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
using namespace std;

class Student
{
public:
    Student(string inputName, int inputAge);
    void setAge(int inputAge);
    void setName(string inputName);
    string getName();
    int getAge();
    void printStudentInfo();


private:
    string name;
    int age;

};

#endif // STUDENT_H
