 #include <iostream>
 using namespace std;
 
 class Shape {
 public:
    virtual void draw() = 0; 
 };
 
 class circle : public Shape {
 public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
 };
 class rectangle : public Shape {
 public:
    void draw() override {
        cout << "Drawing a Rectangle" << endl;
    }
 };
    

