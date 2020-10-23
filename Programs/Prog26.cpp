//Program that reads input from a file and prints words beginning with small case vowels into a different file
//Rudraksh Kapil - 951775 - M - 10/4/2018

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    cout << "\n\n[This is a program that reads input from a file and prints words beginning with small case vowels into a different file]\n";
    
    ifstream f1;
    ofstream f2;
    string s;
    
    string infile = "FIRST_26.txt";
    string outfile = "SECOND_26.txt";
    f1.open(infile.c_str());
    f2.open(outfile.c_str());
    
    while(!f1.eof())
    {
        f1 >> s;
        if (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u')
            f2 << s << " ";
    }
    
    f1.close();
    f2.close();
    cout << "Program executed successfully." << endl;
    return 0;
}
