//Program to find the next day and previous day given a current date.
//Rudraksh Kapil - 951775 - M - 19/3/2018

#include <iostream>
using namespace std;

//Function & array declarations
int days_of_months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
void nextDay(int d, int m, int y);
void prevDay(int d, int m, int y);
void isLeap(int y, int a[]);


//[MAIN]
int main()
{
    cout << "\n[This is a program that transforms a given day to the next & previous day]\n\n";
    
    //declaring variables & getting input
    int day, month, year;
    cout << "Enter date to transform (DD/MM/YYYY):\n";
    cin >> day >> month >> year;
    
    //function calls
    cout << endl;
    isLeap(year, days_of_months);
    nextDay(day, month, year);
    prevDay(day, month, year);
    
    return 0;
}

//Function definitions
//1.Function to change input day into next day
void nextDay(int d, int m, int y)
{
    //increase day
    d += 1;
    
    if (d > days_of_months[m])
    {
        m += 1;         //increase month
        d = 1;
        
        if (m >= 12)
        {
            y += 1;     //increase year
            m = 1;
        }
    }
    
    //display output
    cout << "The next day is " << d << "/" << m << "/" << y << endl;
    
    return;
}

//2.Function to change input day into previous day
void prevDay(int d, int m, int y)
{
    //decrease day
    d -= 1;
    
    if (d <= 0)
    {
        m -= 1;         //decrease month
        
        if (m <= 0)
        {
            y -= 1;     //decrease year
            m = 12;
        }
        
        d = days_of_months[m];
    }
    
    //display output
    cout << "The previous day is " << d << "/" << m << "/" << y << endl;
    
    return;
}

//3.Function to check if a year is a leap year. if yes, set feb days to 29. else leave 28
void isLeap(int y, int a[])
{
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        days_of_months[2] = 29;
    
    return;
}
