#include<iostream>
using namespace std;

class Display {
	private: 
	int last_result;
	public:
	void show_Result(double Answer) {
		last_result = Answer;
		cout << "Result: " << Answer << endl;
	}
	double Last_result() {
		return last_result;
	}
	};

class Calculator {
	private: 
	Display display;
	double result;
	public:
		void add(double a, double b) {
			result = a + b;
			display.show_Result(result);
		}
		void multiple(double a, double b) {
			result = a * b;
			display.show_Result(result);
		}
		double show_lastResult() {
			return display.Last_result();
		}
};
