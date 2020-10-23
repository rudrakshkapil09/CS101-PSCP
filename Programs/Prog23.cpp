//Program to count different characters in input file and display in output file
//Rudraksh Kapil - 951775 - 9/4/2018

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    cout << "\n[This is a program to count different characters in input file and display the result in the output file]\n\n";
    
    string infile = "in23.txt";
    string outfile = "out23.txt";
    
    ifstream f1;
    ofstream f2;
    
    f1.open(infile.c_str());
    char ch;
    int alpha_count = 0, digit_count = 0, punct_count = 0;
    
    while (f1 >> ch)
    {
        f1.get(ch);
        if (isalpha(ch))
            alpha_count++;
        else if (isdigit(ch))
            digit_count++;
        else
            punct_count++;
    }
    
    f1.close();
    
    f2.open(outfile.c_str());
    f2 << "Alphabets = " << alpha_count << endl;
    f2 << "Digits = " << digit_count << endl;
    f2 << "Special = " << punct_count << endl;
    
    f2.close();
    cout << "Program successfully executed." << endl;
    return 0;
}
