#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

#include "student.h"

using namespace std;

int main ()
{
  int selection =0;
  vector<Student>studentList;

  do
    {
      cout<<endl;
      cout<<"Select"<<endl;
      cout<<"Add students = 0"<<endl;
      cout<<"Print all students = 1"<<endl;
      cout<<"Sort and print students according to Name = 2"<<endl;
      cout<<"Sort and print students according to Age = 3"<<endl;
      cout<<"Find and print student = 4"<<endl;
      cin>>selection;

      switch(selection)
      {
        case 0:
        {
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.
            cout<<"Enter student name: "<<endl;
            string name;
            cin>>name;
            cout<<"Enter student age: "<<endl;
            int age;
            cin>>age;
            Student s(name, age);
            studentList.push_back(s);

            break;
        }
        case 1:
        {
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
		    // nimet. 
            for(Student s: studentList)
            {
                cout<<s.getName()<<endl;
            }
            break;
        }
        case 2:
        {
		    // Järjestä StudentList vektorin Student oliot nimen mukaan
		    // algoritmikirjaston sort funktion avulla
		    // ja tulosta printStudentInfo() funktion avulla järjestetyt
		    // opiskelijat
            sort(studentList.begin(), studentList.end(), [](Student s1, Student s2){
                return s1.getName() < s2.getName();
            });
            for(Student s: studentList)
            {
                s.printStudentInfo();
            }
            break;
        }
        case 3:
        {
		    // Järjestä StudentList vektorin Student oliot iän mukaan
		    // algoritmikirjaston sort funktion avulla
		    // ja tulosta printStudentInfo() funktion avulla järjestetyt
		    // opiskelijat
            sort(studentList.begin(), studentList.end(), [](Student s1, Student s2){
                return s1.getAge() < s2.getAge();
            });
            for(Student s: studentList)
            {
                s.printStudentInfo();
            }
            break;
        }
        case 4:
        {
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            cout<<"Enter student name to find: "<<endl;
            string nameToFind;
            cin>>nameToFind;
            auto it = find_if(studentList.begin(), studentList.end(), [nameToFind](Student s){
                return s.getName() == nameToFind;
            });
            if(it != studentList.end())
            {
                it->printStudentInfo();
            }
            else
            {
                cout<<"Student not found"<<endl;
            }
            break;
        }
        default:
        {
            cout<< "Wrong selection, stopping..."<<endl;
            break;
        }
      }
    }while(selection < 5);

  return 0;
}
