#include<iostream>
#include<fstream>
using namespace std;

//============================== TASK 01: tellp() program ======================================

 int main(){
 	
// 	fstream out("greet.txt", ios::out);
// 	cout<< "Position of write pointer before writing: " << out.tellp() << endl;
// 	out<<"A";
// 	cout<< "Position of write pointer after writing a single character: " << out.tellp() << endl;
// 	out.close();
 	


//============================== TASK 02: tellg() program ======================================

 	
// 	fstream in("Greet.txt", ios::in);
// 	cout<< "Position of read pointer before reading: " << in.tellg() << endl;
// 	char ch;
// 	in.get(ch);
// 	cout<< "Position of read pointer after reading a single character: " << in.tellg() << endl;
// 	in.close();
 	



//============================== TASK 03: seekp() program ======================================

 	
// 	fstream file("student.txt", ios::in | ios::out | ios::trunc);
// 	file << "01,Ali ,3.4 ";
// 	file << "02,Ayesha,3.7 ";
// 	file << "03,Zoya,2.5 ";
// 	file << "04,Ahmed,4.0 ";
// 	cout<< "Position of write pointer after writing: " << file.tellp() << endl;
//    //one record takes 13 characters and the moment pointer is at 53 means next writing will be start from
//    //53 but Lets move it back to override the Last line
//    //53-13=40
//    //file.seekg(file.tellp()-13); // absolute position without direction.
//    file.seekp(-13, ios::cur); // relative with reference to current position.
// 	file << "05,Nadir,2.78";
// 	file.close();



//============================== TASK 04: seekg() program ======================================

 	
 	fstream file("Student.txt", ios::in | ios::out);
 	cout<< "Position of pointer before reading: " << file.tellg() << endl;
 	char ch;
 	cout<< "Move the read pointer position to 13" << endl;
 	file.seekg(13);
 	while(file.get(ch)){
 		cout<< "Character Read: "<< ch << " Position of pointer after reading: " << file.tellg() << endl;
	 }
 	file.close();
 	return 0;
 }

