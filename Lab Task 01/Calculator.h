#include<iostream>
using namespace std;
class Calculator{
  private:
  	float num1;
  	float num2;
 public:
 	void setvalues(float a, float b){
 		num1=a;
 		num2=b;
	 }
	 //Arithimetic operations
	float add(){
		return num1+num2;
	}
	float subtract(){
		return num1-num2;
	}
	float multiply(){
		return num1*num2;
	}
	float divide(){
		if(num2!=0)
		return num1/num2;
		else{
			cout<<"Error: Division by zero!"<<endl;
		return 0;
	    }
	}
};

