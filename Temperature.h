#include<iostream>
using namespace std;
class Temperature{
 public:
 	float celsius;
 	float tofahrenheit(){
 		return (celsius * 9.0/5.0)+32;
	 }
	 void display(){
	 	float fahrenheit= tofahrenheit();
	 	cout<<"Temprature in fahrenheit: "<<fahrenheit<<" F"<<endl;
	 }
};

