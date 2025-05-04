#include <iostream>
using namespace std;

class Bankaccount1 {
private:
    double* balance;  // Pointer to dynamically allocate memory for balance

public:
    // Constructor: Dynamically allocates memory for the balance
    Bankaccount1(double amount) {
        balance = new double(amount);
        cout << "BankAccount created with balance: " << *balance << endl;
    }

    // Deep Copy Constructor: Allocates new memory for copied object
    Bankaccount1(const Bankaccount1& other) {
        balance = new double(*other.balance);  // Creates a new copy
        cout << "Deep copy constructor called!" << endl;
    }

    // Function to update the balance
    void setBalance(double new_balance) {
        *balance = new_balance;
    }

    // Function to display the balance
    void display() const {
        cout << "Balance: " << *balance << endl;
    }

    // Destructor: Properly deallocates memory
    ~Bankaccount1() {
        cout << "Deleting balance: " << *balance << endl;
        delete balance;
    }
};

