#include <iostream>
using namespace std;

struct BankDeposit{
	double amt;
	int tenure;
};

struct Dates{
	int day;
	int month;
	int year;
};

int calculateAge(Dates &D1, Dates &D2){
	int y = D2.year - D1.year;
	if((D1.month < D2.month) || (D1.month == D2.month && D1.day > D2.day)){
		y--;
	}
	return y;
}

int main()
{
	cout << "\n[This is a program that calculates total amount of money a person receives depending on DOB and DO Deposit]\n\n"; 
	
	int age;
	double rate, total;
	Dates DOB;
	Dates Depos;
	BankDeposit User;
	
	cout << "Enter the date of birth (DD MM YYYY):\n";
	cin >> DOB.day >> DOB.month >> DOB.year;
	
	cout << "Enter the date of deposit (DD MM YYYY):\n";
	cin >> Depos.day >> Depos.month >> Depos.year;
	
	cout << "Enter the amount to be deposited:\n";
	cin >> User.amt;

	cout << "Enter the length of tenure (years):\n";
	cin >> User.tenure;

	age = calculateAge(DOB, Depos);
	if (age >= 60)
		rate = 0.09;
	else 
		rate = 0.08;
	
	total = User.amt + User.amt * rate * User.tenure;
	cout << "Total Amount = Rs." << total << endl;
	return 0;
}				
