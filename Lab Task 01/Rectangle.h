#include<iostream>
using namespace std;
class Rectangle{
 private:
 	//class Data
 	int length;
 	int width;
public:
	//class function outside the class
	void setDimension(int l,int w);
	int area();
	int perimeter();     
};
       //Member function definition outside the class
 void Rectangle :: setDimension(int l,int w){
       length=l;
       width=w;
 }
 int Rectangle :: area(){
   return length*width;
 }
 int Rectangle :: perimeter(){
 	return 2*(length + width);
 }

