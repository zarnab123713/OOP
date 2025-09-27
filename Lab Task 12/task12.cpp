#include<iostream>
#include<stdexcept>
using namespace std;

// ========================================TASK 01==============================================


int main() {
//    double numerator,denominator;
//    cout<<"Enter the value of numerator: ";
//    cin>>numerator;
//    cout<<"Enter the value of denominator: ";
//    cin>>denominator;
//    try {
//        if(denominator == 0){
//            throw runtime_error("Error: Cannot divide by zero!");  
//        }
//        double divide=numerator/denominator;
//        cout<<"The division is: "<<divide<<endl;
//    }
//    catch(runtime_error &e){
//        cout<<e.what()<<endl;   // prints error message
//    }
// ========================================TASK 02==============================================



	
	double arr[4]={0.0,0.0,0.0,0.0};
    int index,value;
    cout <<"Enter index (0 to 3): ";
    cin>>index;
    cout<<"Enter value: ";
    cin>>value;

    try {
        if(index<0||index>=4) {
            throw out_of_range("Error: Index is out of range!");
        }
        arr[index]=value;
        cout<<"Value stored successfully at index "<<index<<endl;
    }
    catch(out_of_range &e){
        cout<<e.what()<<endl;
    }

    // Display final array
    cout<<"Final array values: ";
    for(int i = 0; i < 4; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}

 

















