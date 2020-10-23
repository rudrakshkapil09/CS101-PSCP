//Program to convert 24-hour notation to 12-hour notation
//Rudraksh Kapil - 951775 - M - 19/3/2018

#include <iostream>
using namespace std;

//Function declarations
void getInput(int &hr, int &min);
void timeConversion(int &hr, char &x);
void displayOutput(int hr, int min, char x);

//[MAIN]
int main()
{
    cout << "\n[This is a program to convert 24-hour time to 12-hour time]\n\n";
    
    //declaring variables
    char x;         //indicates AM or PM
    int hours, minutes;
    
    //function calls:
    getInput(hours, minutes);
    timeConversion(hours, x);
    displayOutput(hours, minutes, x);
    
    return 0;
}

//Function definitions
//1.Function to get input as two integers - hours and minutes
void getInput(int &hr, int &min)
{
    //setting the input values into the function parameters
    cout << "Enter the 24-hour time (HH/MM):\n";
    cin >> hr >> min;
    cout << endl;
    
    return;
}

//2.Function to carry out the actual conversion and change the char value of x accordingly.
void timeConversion(int &hr, char &x)
{
    //P for PM, A for AM -- Also changes value of hr if PM
    if (hr >= 12)
    {
        x = 'P';
    }
    else //(hr < 12)
        x = 'A';
    
    if (hr > 12)
        hr -= 12;   //reduce hour by 12
    else if (hr == 0)
        hr += 12;
    
    return;
}

//3.Function to display the 12-hour notation time
void displayOutput(int hr, int min, char x)
{
    cout << "The converted time is:\n";
    cout << hr << ":" << min << " ";
    
    if (min == 0)
        cout << "\b0 ";        //add an extra 0 if output is eg. 7:00
    
    if (x == 'P')
        cout << "PM" << endl;
    else
        cout << "AM" << endl;
    
    return;
}
