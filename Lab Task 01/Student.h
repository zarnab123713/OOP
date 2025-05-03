#include<iostream>
using namespace std;
class Student{
 private:       //Access specifier
     //class Data
	string name;
	int rollno;
	float marks;
 public:
 	 //class Function
	void getData(){
		cout<<"----------------INPUT STUDENT DATA---------------"<<endl;
		cout<<"Enter name: ";
		getline(cin,name);
		cout<<"Enter Rollno: ";
		cin>>rollno;
		cout<<"Enter Marks: ";
		cin>>marks;
	}
	void displayData(){
		cout<<"------------------DISPLAY STUDENT DATA------------"<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Roll no: "<<rollno<<endl;
		cout<<"Marks: "<<endl;
	}
};

