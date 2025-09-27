 #include <iostream>
 #include"Friend.h"
 #include"PureVirtual.h"
 using namespace std;

 int main() {
 	
// 	                                             Task of Friend Function
//    Rectangle rect(4, 5);
//    Circle circ(3);
//    cout << "Total Area: " << totalArea(rect, circ) << endl;

//                                                  Task of Pure Virual Function
    Shape* s1;
    Shape* s2;
    circle c;
    rectangle r;
    s1 = &c;
    s1->draw();
    s2 = &r;
    s2->draw();
    
    
    return 0;
 }
