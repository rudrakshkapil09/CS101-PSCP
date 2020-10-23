//Program to calculate the number of steps required to reduce a number to 1
//Rudraksh Kapil - 951775 - M - 19/3/2018

#include <iostream>
using namespace std;

//Function declaration
void doProcess(int &input);

//[MAIN]
int main()
{
    cout << "\n[This is a program to calculate the number of steps required to reduce an integer to 1.]\n\n";
    
    //getting input
    int input, steps = 0;
    cout << "Enter the integer: ";
    cin >> input;
    
    //loop to calculate no. of steps
    cout << "The steps are:\n" << input << " ";
    while (input != 1)
    {
        doProcess(input);
        steps++;
    }
    
    //displaying output
    cout << "\nThe number of steps required is: " << steps << endl;
        
    return 0;
}

//Function definition
//1. Function that changes input according to nature and increases count for each step. returns count
void doProcess(int &input)
{
    //if/else to determine nature
    if (input % 2 == 0)     //even
        input /= 2;
    else
        input = (input * 3) + 1;
    
    cout << input << " ";
}

