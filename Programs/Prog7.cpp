//Program to find all prime factors of a given number along with their exponents
//Rudraksh Kapil - 951775 - M - 12/3/2018

#include <iostream>
using namespace std;

//Function & array declarations
int countArray[100] = {0};     //stores exponents of each position value
void primeFactors(int n, int d, int a[]);
void displayOutput(int n, int a[]);

//[MAIN]
int main()
{
    cout << "\n[This is a program to find all prime factors of a given number and their exponents]\n\n";
    
    //declaring variables
    int num, div;
    cout << "Enter the number: ";
    cin >> num;
    
    //initialising div & calling function to increase exponent
    div = 2;
    primeFactors(num, div, countArray);
    displayOutput(num, countArray);
    
}

//Function definitions
//1.Recursive function to find prime factors and increase their count in count array
void primeFactors(int n, int d, int a[])
{
    if (n % d == 0)
    {
        primeFactors(n/d, d, a);
        a[d]++;
    }
    else if (d <= n)
        primeFactors(n, d + 1, a);
    
    return;
}

//2.Function to display output. Prints x^y where y is value at count[x]
void displayOutput(int n, int a[])
{
    //start of output
    cout << "Prime factorisation of " << n << ":\n";
    
    //loop to check value at each position and print accordingly
    for (int i = 2; i <= 100; i++)
    {
        if (a[i] > 0)
        {
            cout << i << "^" << a[i] << " ";
        }
    }
    
    cout << endl;
    return;
}
