 #include<iostream>
 #include"staticdm.h"
 #include"staticmf.h"
 using namespace std;
 
 int main() {
//                                            	Static Data members
//    Counter c1, c2, c3;
//    c1.showCount();
//    c2.showCount();


//                                                 Static Member functions
    counter c1, c2;
    counter::print();
    counter c3;
    counter::print();
    
    return 0;
 }
