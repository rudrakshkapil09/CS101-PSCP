//Program that uses recursive function to solve towers of hanoi problem.
//Rudraksh Kapil - 951775 - M - 12/3/2018

#include <iostream>
using namespace std;

//Function declaration
void hanoiTower(int n, int source, int destination, int temporary);

//[MAIN]
int main()
{
    cout << "\n[This is a program to solve hanoi towers problem]\n\n";
    
    //declaring variables and getting input
    int n, src = 65, dest = 67, temp = 66;      //A,C and B respectively when printed
    cout << "Enter number of discs: ";
    cin >> n;
    
    //calling recursive function to display output
    cout << "The solution for " << n << " discs and 3 poles is as follows:\n";
    hanoiTower(n, src, dest, temp);
    
    return 0;
}

//Function definitions
//1. Function that solves hanoi tower problem for n discs
void hanoiTower(int n, int src, int dest, int temp)
{
    if (n > 1)
    {
        hanoiTower(n-1, src, temp, dest);
        cout << (char)src << " to " << (char)dest << endl;
        hanoiTower(n-1, temp, dest, src);
    }
    
    
    else
        cout << (char)src << " to " << char(dest) << endl;
    
    return;
}

