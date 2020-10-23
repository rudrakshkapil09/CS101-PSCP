//Program that tests the next day function into the next month and the next year
//Rudraksh Kapil - 951775 - M - 12/4/2018

#include <iostream>
using namespace std;

//function declarration
int checkLeap(int yr);

//class definition
class Date {
    int day;
    int month;
    int year;
    
public:
    //member functions
    void setDate()
    {
        cout << "Enter the date (DD MM YYYY): \n";
        cin >> day >> month >> year;
    }
    void printDate(){
        cout << day << " - " << month << " - "<< year;
    }
    Date nextday()
    {
        Date date1;
        date1.day = day;
        date1.month = month;
        date1.year = year;
        
        if( day == 31 || (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11)) || (day == 29 && month == 2) || (day == 28 && (month == 2 && checkLeap(year) == 0)))
        {
            date1.day=1;
            if(month!=12)
                date1.month=month+1;
            if(month==12) {
                date1.month=1;
                date1.year=year+1;
            }
        }
        else
            date1.day=day+1;
        return date1;
    }
    
};

//function definition. returns 0 if not a leap year
int checkLeap(int yr)
{
    if(yr % 4 == 0 && yr % 100 != 0)
        return 1;
    if(yr % 400 == 0)
        return 1;
    else
        return 0;
}

//[MAIN]
int main()
{
    cout << "\n[This is a program that tests the next day function into the next month and the next year]\n\n";
    
    Date date2[365], date3;
    int n;
    
    //getting input
    cout << "Enter the starting date: \n";
    date3.setDate();
    cout << endl;
    
    cout << "How may days forward do you want to go: \n";
    cin >> n;
    
    //printing first next date
    date2[0] = date3.nextday();
    cout << "\nThe next day is: ";
    date2[0].printDate();
    cout << endl;
    
    //loop to carry out next date function
    for(int i = 1; i < n; i++) {
        cout << "The next day is: ";
        date2[i] = date2[i-1].nextday();
        date2[i].printDate();
        cout << endl;
    }
    
    return 0;
}
