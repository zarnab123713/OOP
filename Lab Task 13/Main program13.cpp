#include <iostream>
#include <stdexcept>
#include"Calculator.h"
#include"Logger.h"
using namespace std;

 // ===================== TASK 01(Calculator Template) ==========================
 

int main() {
//    try {
//        double a,b;
//        char op;
//
//        cout<<"Enter first number: ";
//        cin>>a;
//        cout<<"Enter second number: ";
//        cin>>b;
//        cout<<"Enter operation (+, -, *, /): ";
//        cin>>op;
//
//        Calculator<double> calc(a,b);
//        
//        switch (op){
//            case '+':
//                cout<<"Result = "<<calc.add()<<endl;
//                break;
//            case '-':
//                cout <<"Result = "<<calc.subtract()<<endl;
//                break;
//            case '*':
//                cout<<"Result = "<<calc.multiply()<<endl;
//                break;
//            case '/':
//                cout<<"Result = "<<calc.divide()<<endl;
//                break;
//            default:
//                cout<<"Invalid operator!"<<endl;
//        }
//    }
//    catch(exception &e){
//        cout<<e.what()<<endl; // print exception message
//    }




// ===================== TASK 02(Logger Template) ==========================


    Logger<int> log;
    log.error=404;
    log.show();

    Logger<string> log2;
    log2.error="Something happened";
    log2.show();

    return 0;
}
 

