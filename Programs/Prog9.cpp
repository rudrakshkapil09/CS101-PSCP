//Program to calculate nth term in Newman-Conway sequence
//Rudraksh Kapil - 951775 - 19/3/2018

#include <iostream>
using namespace std;

//Function declaration
int seqNC(int n);

//[MAIN]
int main()
{
    cout << "\n[This is a program to calculate nth number in Newman-Conway Sequence]\n\n";
    
    //declaring variables & getting input
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    
    //displaying output via function call
    cout << "Number " << n << " in the sequence is " << seqNC(n) << endl;
    
    return 0;
}

//Function definition
//1.Recursive function to find nth number
int seqNC(int n)
{
    if (n < 3)
        return 1;
    else
        return seqNC(seqNC(n-1)) + seqNC(n-seqNC(n-1));
}
