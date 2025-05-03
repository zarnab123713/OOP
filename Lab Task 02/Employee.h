#include<iostream>
using namespace std;
class Employee{
	int id;
	string name;
	float salaray;
 public:
 	Employee ()
 	{
 		id=0;
 		name="Not Assigned";
 		salaray=0.0;
	 }
	 void displayDetails()
	 {
	 	cout<<"\n ID :"<<id<<endl;
	 	cout<<"\n Name :"<<name<<endl;
	 	cout<<"\n Salaray :"<<salaray<<endl;
	 }
};

