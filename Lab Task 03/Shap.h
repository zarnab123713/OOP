#include <iostream>
using namespace std;

class Shape {
public:
Shape() {
cout<<"Shape Constructor called." << endl;
  }
};
class Rectangle : public Shape {
public:
Rectangle() {
cout<<"Rectangle constructor called.";
  }
};
