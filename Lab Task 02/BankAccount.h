 #include<iostream>
	using namespace std;
	class BankAccount{
		string accountNumber;
		string accountHolder;
		double balance;
	 public:
	 	BankAccount(string an,string ah,double b)
	 	{
	 		accountNumber=an;
	 		accountHolder=ah;
	 		balance=b;
		 }
		 void showAccountDetails()
		 {
		 	cout<<"ACCOUNT NUMBER :"<<accountNumber<<endl;
		 	cout<<"ACCOUNT HOLDER :"<<accountHolder<<endl;
		 	cout<<"BALANCE :"<<balance<<endl;
		 }
	};

