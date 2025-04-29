#include<iostream>
using namespace std;
class Voter{
 private:
	string name;
	int age;
 public:
 	void setData(string n, int a);
 	bool isEligible();                 //function to check eligibility
};
    void Voter :: setData(string n, int a){
    	name=n;
    	age=a;
	}
 	bool Voter ::isEligible(){
 		return age>18;
	 }


