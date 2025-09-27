//                      Lab 06 - Runtime Polymorphism

#include <iostream>
#include"Runtime.h"
 using namespace std;
 
 int main() {
    Shape* s1;
    Shape* s2;
    Rectangle rect(5, 3);
    Circle circ(4);
    s1 = &rect;
    cout << "Rectangle Area: " << s1->area() << endl;
    s2 = &circ;
    cout << "Circle Area: " << s2->area() << endl;
    return 0;
 }
