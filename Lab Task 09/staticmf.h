#include <iostream>
 using namespace std;
 
 class counter {
    static int count;
 public:
    counter() {
	 count++; 
	 }
    static void print() { cout << "Total Objects Created = " << count << endl; }
 };
 int counter::count = 0;
 
