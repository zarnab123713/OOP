#include <iostream>
 using namespace std;
 class Distance {
    int feet, inches;
    
 public:
    Distance(int f, int i) {
    	feet = f; inches = i;
	} 
    bool operator == (Distance d) {
        return (feet == d.feet && inches == d.inches);
    }
    void display() {
        cout << feet << " feet " << inches << " inches" << endl;
    }
 };
