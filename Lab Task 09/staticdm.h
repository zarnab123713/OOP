#include <iostream>
 using namespace std;
 
 class Counter {
    static int count; 
 public:
    Counter() {
	 count++; 
	 }
    void showCount() { cout << "Count = " << count << endl; }
 };
 
 int Counter::count = 0; 
 

