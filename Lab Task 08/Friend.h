#include<iostream>
using namespace std;

class Rectangle;
class Circle;
 class Rectangle {
    double length, width;
 public:
    Rectangle(double l, double w) {
    	length = l; width = w;
	}
    friend double totalArea(Rectangle r, Circle c);
 };
 class Circle {
    double radius;
 public:
    Circle(double r) {
    	radius = r;
	}
    friend double totalArea(Rectangle r, Circle c);
 };
 
 double totalArea(Rectangle r, Circle c) {
    return (r.length * r.width) + (3.14159 * c.radius * c.radius);
 }
