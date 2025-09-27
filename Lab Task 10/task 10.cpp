#include <iostream>
#include <fstream>
#include <string>
using namespace std;

  int main() {
//    ofstream out("notes.txt");
//    out << "Hello, this is a file." << endl;
//    out << "We are writing in notes.txt file" << endl;
//    out.close();
//    
//    ifstream in("notes.txt");
//    string line;
//    cout << "File Content: ";
//    while (getline(in, line)) {
//    cout << line << endl;
//    }
//    in.close();
//    
//    
//    ofstream appendFile("notes.txt", ios::app);
//    appendFile << "Name: Zarnab" << endl;
//	appendFile << "Roll: 14" << endl;
//    appendFile.close();

 
 
 //  ===================== TASK 02 ==========================


//    ifstream file("notes.txt");  
//    if (!file) {
//        cout << "File not found!" << endl;
//        return 1;
//    }
//
//    string s;
//    int count = 0;
//
//    while (getline(file, s)) {
//        count++;   
//    }
//
//    file.close();
//    cout << "Total number of lines in file = " << count << endl;

    
    
//
// //  ===================== TASK 03 ==========================
//
//    fstream filein("notes.txt",ios::in);   
//    fstream fileout("copy.txt",ios::out);   
//    string line;
//    int lineCount = 0;
//
//    if (!filein) {
//        cout << "Error: Unable to open notes.txt" << endl;
//        return 1;
//    }
//
//    // Copy line by line and count
//    while (getline(filein, line)) {
//        fileout << line << endl;   // Write line to copy.txt
//        lineCount++;
//    }
//
//    filein.close();
//    fileout.close();
//
//    cout << "Content copied to copy.txt successfully." << endl;
//    cout << "Total number of lines in the file: " << lineCount << endl;


//
// //  ===================== TASK 04 ==========================
//	
	fstream filestd("Students.txt",ios::out);
	filestd<<"Student details:"<<endl;
	filestd<<"||   Name    | Roll No    |   Registration No ||"<<endl;
	filestd<<"||--------------------------------------------||"<<endl;
	filestd<<"||Ali        | 2024-SE-110|     ABC153        ||" <<endl;
	filestd<<"||Ayesha     | 2024-SE-153|     ABC446        ||" <<endl;
	filestd<<"||Fatima     | 2024-SE-141|     ABC786        ||" <<endl;
	filestd<<"-----------------------------------------------------"<<endl;
	filestd.close();
	
	fstream filein("Students.txt",ios::in);
	string s;
	while (getline(filein,s)){
		cout<<s<<endl;
	} 
	filein.close(); 
//	
	return 0;
}    

