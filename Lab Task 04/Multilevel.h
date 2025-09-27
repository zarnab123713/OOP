#include<iostream>
using namespace std;

class Person {
	protected:
		string name;
		int age;
		public:
			void setPerson() {
				cout << "Enter name: "; cin >> name;
				cout << "Enter age: "; cin >> age;
			}
			void display_person() {
				cout << "\n\nDetails:\n";
				cout << "Name: " << name << endl;
				cout << "Age: " << age << endl;
			}
};

class Employee : public Person {
	protected:
		int employee_id;
		public:
			void setEmployee() {
				setPerson();
				cout << "Enter Employee ID: "; cin >> employee_id;
			}
			void display_employee() {
				display_person();
				cout << "Employee ID: " << employee_id << endl;
			}
};

class Manager : public Employee {
	private:
		string department;
		public:
			void setManager() {
				setEmployee();
				cout << "Enter Department: "; cin >> department;
			}
			void display_manager() {
				display_employee();
				cout << "Department: " << department;
			}
};

