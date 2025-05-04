#include <iostream>
using namespace std;
class Person {
public:
int age;
string name;

public:
void setPerson(int a, string n) {
age=a; name=n;
}
void showPerson() {
cout << "Name: " << name;
cout << "\nAge: " << age;
}
};
class Student : public Person {
int rollNo;

public:
void setStudent(int a, string n, int r) {
setPerson(age,name);
rollNo = r;
}
void showStudent() {
cout << "\n\nName: " << name;
cout << "\nAge: " << age;
cout << "\nRoll No: " << rollNo;
}
};
