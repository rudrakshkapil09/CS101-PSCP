//Program that utilises a savings account class and calculates interest & balance
//Rudraksh Kapil - 951775 - M - 12/4/2018

#include <iostream>
using namespace std;

//class definitions
class SavingsAccount{
private:
    double balance;
    static double rate;
    
public:
    //constructors (overloaded)
    SavingsAccount(){
        balance = 1000.0;
        rate = 0.0;
    }
    
    SavingsAccount(double balance, double rate){
        this->balance = balance;
        this->rate = rate;
    }
    
    //member functions
    double calculateMonthlyInterest(){
        double amt;
        amt = balance*rate/1200;
        balance += amt;
        
        return amt;
    }
    
    void modifyInterestRate(double r){
        rate = r;
    }
};

//setting the static variable the initial value
double SavingsAccount::rate = 8.0;

//[MAIN] to test class
int main()
{
    cout << "\n\n[This is a program that utilises a savings account class and calculates monthly interest]\n\n";
    
    SavingsAccount acc(10000,8.0);
    
    cout << "Current rate is 8.0\n";
    cout << "Monthly interest = ";
    cout << acc.calculateMonthlyInterest() << endl;
    
    acc.modifyInterestRate(6.0);
    cout << "The interest rate is now changed to 6.0\n";
    cout << "New monthly interest = ";
    cout << acc.calculateMonthlyInterest() << endl;
    
    return 0;
}
