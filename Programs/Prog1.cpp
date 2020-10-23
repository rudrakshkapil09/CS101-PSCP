//Program to raise input a to the power of input b
//Rudraksh Kapil - 951775 - M - 19/3/18

#include <iostream>
using namespace std;

//function declaration
int power(int a, int b);

//[MAIN]
int main()
{
    cout << "\n[This is a program to raise a to the power of b]\n\n";

    //declaring variables and getting input
    int a, b, res;
    cout << "Enter the values a^b:\n";
    cin >> a >> b;
    
    //displaying output
    res = power(a, b);
    cout << "Answer = " << res << endl;
    
    return 0;
}

//Function definition:
//1. Function to return a ^ b
int power(int a, int b)
{
    int x = a;
    for (int i = 1; i < b; i++)
        x *= a;
    
    return x;
}
