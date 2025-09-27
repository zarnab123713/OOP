//                                      Lab 5:  Composition & Aggregation

#include<iostream>
#include"Composition.h"
#include"Aggregation.h"

using namespace std;

int main() {
	
//	Task 1
//	Calculator cal;
//	cal.add(44, 60);
//	cal.multiple(3, 8);
//	cal.multiple(55, 22);
//	cout << "Last result: " << cal.show_lastResult();
	
	
	
//	Task 2
	calculator sharedCalculator;
	Student s1(5, 4);
	Student s2(8, 9);
	Student s3(88, 3);
	s1.showAdd("Fatima", &sharedCalculator);
	s2.showMultiply("Muneeba", &sharedCalculator);
	s3.showMultiply("Zarnab", &sharedCalculator);

	return 0;
}
