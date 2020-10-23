//Program to simulate coin tossing and displaying number of heads and tails
//Rudraksh Kapil - 951775 - M - 19/3/2018

#include <iostream>
using namespace std;

//Function declaration
int flip();

//[MAIN]
int main()
{
    cout << "\n[This is a program that simulates coin tossing]\n\n";
    srand(static_cast<unsigned>(time(nullptr)));        //seeding random generator
    
    //declaring variables
    int res, count = 0;
    
    //loop to flip the coin & display each result
    cout << "The obtained results are:\n";
    for (int i = 1; i <= 10; i++)
    {
        cout << i << ") ";
        res = flip();
        
        if (res == 1)
            count++;
    }
    
    //displaying total counts
    cout << "The number of heads is " << count << endl;
    cout << "The number of tails is " << 10 - count << endl;
    
    return 0;
}

//Function definition
//1. Function that prints result and returns 1 for heads, 0 for tails.
int flip()
{
    int flip;
    flip = rand() % 2;
    
    if (flip == 1)    //heads
    {
        cout << "Heads." << endl;
        return 1;
    }
    
    else                    //tails
    {
        cout << "Tails." << endl;
        return 0;
    }
}
