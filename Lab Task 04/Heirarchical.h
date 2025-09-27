#include <iostream>
using namespace std;

class employee {
public:
    string name;
    double salary;

    void display_employee() {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }
};

class Developer : public employee {
public:
    string programming_language;

    void display_developer() {
        display_employee();
        cout << "Programming Language: " << programming_language << endl;
    }
};

class Designer : public employee {
public:
    string design_tool;

    void display_designer() {
        display_employee();
        cout << "Design Tool: " << design_tool << endl;
    }
};



    

