#include <iostream>
#include <stdexcept>
using namespace std;

template<class T>
class Logger{
	public:
		T error;
		 
		void show(){
		 	cout<<error<<endl;
		 }
};
