	#include<iostream>
	using namespace std;
	class Rectangle{
   	private:
		float length;
		float width;
	public:	
		Rectangle(){               //default constructor
			length=1.0;
			width=1.0;
		}
		Rectangle(float l,float w){         //parameterized constructor
			length=l;
			width=w;
		}
		Rectangle(float s){                  //single-paramreterized constructor
		      length=s;
		      width=s;
		}
		float area(){
		 return	length*width;
       }
		void Display(){
			cout<<"Length= "<<length<<endl;
			cout<<"Width= "<<width<<endl;
		}
		
	}; 

