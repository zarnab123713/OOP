#include <iostream>
 using namespace std;
 
 class Calculator {
 public:
    int add(int a, int b)
	 { return a + b; 
	 }
    double add(double a, double b) {
	 return a + b; 
	 }
	 
    int multiply(int a, int b) {
	 return a * b; 
	 }
    double multiply(double a, double b) {
	 return a * b; 
	 }
    int subtract(int a, int b) {
	 return a - b; 
	 }
    double subtract(double a, double b) {
	 return a - b; 
	 }
    double divide(double a, double b) 
	{
        if (b == 0) {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return a / b;
    }
 };
 
