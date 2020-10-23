#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    cout << "\n[This is a program that reads input from a file and copies it to a different file with only single spaces]\n\n";
    
    int i;
    ifstream f1;
    ofstream f2;
    
    string infile = "in24.txt";
    string outfile = "out24.txt";
    string s1;
    
    f1.open(infile.c_str());
    f2.open(outfile.c_str());
    
    while (!f1.eof())
    {
        f1 >> s1;
        if (!f1.eof())
            f2 << s1 << " ";
    }
    
    f1.close();
    f2.close();
    cout << "Program successfully executed." << endl;	
    
    return 0;
}
