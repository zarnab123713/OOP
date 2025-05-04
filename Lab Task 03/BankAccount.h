#include<iostream>
using namespace std;
class BankAccount{
	public:
	float *balance;
	BankAccount(float bl){
		balance= new float(bl);
	}
	BankAccount(const BankAccount &ba){
		balance=ba.balance;
	}
	void displaybalance(){
		cout<<"Balance:"<<*balance<<endl;
		
	}
	void updateBalance(float newbl){
		*balance=newbl;
		cout<<newbl;
	}
	~BankAccount(){
	delete balance;	
	}
};

