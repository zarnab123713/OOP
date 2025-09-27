#include <iostream>
#include <stdexcept>
using namespace std;

template<class T>
class Calculator {
private:
    T num1,num2;

public:
    Calculator(T a, T b) {
        num1=a;
        num2=b;
    }

    T add(){
        return num1 + num2;
    }

    T subtract(){
        return num1 - num2;
    }

    T multiply(){
        return num1 * num2;
    }

    T divide(){
        if (num2 == 0){
            throw runtime_error("Error: Division by zero!"); // exception handling
        }
        return num1 / num2;
    }
};
