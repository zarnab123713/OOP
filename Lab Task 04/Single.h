#include<iostream>
using namespace std;

class person {
	protected:
		string name;
		int age;
		public:
			void setperson() {
				cout << "Enter Name: "; cin >> name;
				cout << "\nEnter age: "; cin >> age;
			}
			void display_person_info() {
				cout << "Name: " << name << endl;
				cout << "Age: " << age << endl;
			}
};

class Student : public person {
	private:
	int student_id;
	public: 
	setStudent() {
		setperson();
		cout << "\nEnter Student ID: "; cin >> student_id;
	}
	display_student_info() {
		cout << "\nStudent Details\n";
		display_person_info();
		cout << "Student ID: " << student_id;
	}
};
