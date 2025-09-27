#include<iostream>
using namespace std;

class calculator {
	private:
		double result;
	public:
		void add(double a, double b) {
			result = a + b;
			cout << "Addition: " << result << endl << endl;
		}
		void multiply(double a, double b) {
			result = a * b;
			cout << "Multiplication: " << result << endl << endl;
		}
};

class Student {
	private:
		calculator *cal;
		string name;
		double num1; double num2;
		public:
			Student(int x, int y) {
				num1 = x; num2 = y;
			}
			void showAdd(string n, calculator *c) {
				name = n; cal = c;
				cout << name << " performing addition.. " << endl; 
				cal->add(num1, num2);
			}
				void showMultiply(string n, calculator *c) {
				name = n; cal = c;
				cout << name << " performing multiplication.. " << endl; 
				cal->multiply(num1, num2);
			}
};


