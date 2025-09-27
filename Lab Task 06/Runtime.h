#include <iostream>
 using namespace std;
 
 class Shape {
 public:
    virtual double area() {
    	cout << "Area of Shape.";
    }
 };
 
 class Rectangle : public Shape {
    double length, width;
 public:
    Rectangle(double l, double w) {
    	length = l; width = w;
	} 
	
    double area() override {
	 return length * width;
	}
 };
 
 class Circle : public Shape {
    double radius;
 public:
    Circle(double r) {
    	radius = r;
	}
    double area() override {
	  return 3.14159 * radius * radius;
	   }
 };
