//Program to multiply 2 complex numbers
//Rudraksh Kapil - 951775 - M - 19/3/2018

#include <iostream>
using namespace std;

//Function declarations
void getProd(int real1, int imag1, int real2, int imag2, int &realpart, int &imagpart);

//[MAIN]
int main()
{
    cout << "\n[This is a program to multiply two complex numbers (a+ib) & (c+id)]\n\n";
    
    //declaring variables
    int a, b;
    int c, d;
    int realpart, imagpart;
    
    //getting input
    cout << "Enter the coefficients of first complex number (a+ib):\n";
    cin >> a >> b;
    
    cout << "Enter the coefficients of second complex number (c+id):\n";
    cin >> c >> d;
    
    //function to set values of realpart & imagpart
    getProd(a, b, c, d, realpart, imagpart);
    
    //displaying output
    cout << "\nProduct = " << realpart << " + i(" << imagpart << ")" << endl;
    
    return 0;
}

//Function definitions
//1.Function that multiplies the numbers and changes values of realpart & imagpart
void getProd(int real1, int imag1, int real2, int imag2, int &realpart, int &imagpart)
{
    realpart = real1 * real2 - imag1 * imag2;
    imagpart = real2 * imag1 + imag2 * real1;
    
    return;
}
