#include "student.h"


Student::Student(string inputName, int inputAge)
{
    setName(inputName);
    setAge(inputAge);

}

void Student::setAge(int inputAge)
{
    age = inputAge;
}

void Student::setName(string inputName)
{
    name = inputName;
}

string Student::getName()
{
    return name;
}

int Student::getAge()
{
    return age;
}

void Student::printStudentInfo()
{
    cout<<"Student "<<getName()<<" Age "<<getAge()<<endl;

}
