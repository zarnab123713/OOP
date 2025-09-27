#include<iostream>
#include"funcOverloading.h"
#include"OpOverloading.h"
using namespace std;

int main() {
//    Calculator calc;
//    cout << "Int Add: " << calc.add(5, 3) << endl;
//    cout << "Double Add: " << calc.add(2.5, 1.2) << endl;
//    cout << "Multiply: " << calc.multiply(4, 3) << endl;
//    cout << "Divide: " << calc.divide(10, 2) << endl;



 
    Distance d1(5, 8), d2(5, 8), d3(6, 2);
    d1.display();
    d2.display();
    d3.display();
    if (d1 == d2)
        cout << "d1 and d2 are equal" << endl;
    else
        cout << "d1 and d2 are not equal" << endl;
    if (d1 == d3)
        cout << "d1 and d3 are equal" << endl;
    else
        cout << "d1 and d3 are not equal" << endl;
    return 0;
 }
