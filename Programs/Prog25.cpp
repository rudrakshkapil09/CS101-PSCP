#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    cout << "\n\n[This is a program that takes integer input from 2 different files and sorts them in a third file]\n";
    
    int i, j, k, a, b, m, n, f;
    int *file1, *file2;
    ifstream f1;
    ifstream f2;
    ofstream f3;
    string infile1="FILE1_25.txt";
    string infile2="FILE2_25.txt";
    string outfile="DATA_25.txt";
    
    f1.open(infile1.c_str());
    f2.open(infile2.c_str());
    f3.open(outfile.c_str());
    //size of lists input
    f1 >> m;
    f2 >> n;
    
    //new dynamic arrays
    file1 = new int [m];
    file2 = new int [n];
    
    for (i = 0; i < m; i++)
        f1 >> file1[i];
    for (j = 0; j < n; j++)
        f2 >> file2[j];
    
    i = j = 0;
    while((i<n)&&(j<n))
    {
        if(file1[i]<file2[j])
            f3<<file1[i++]<<" ";
        else
            f3<<file2[j++]<<" ";
    }
    while(j<n)
        f3<<file2[j++]<<" ";
    while(i<m)
        f3 << file1[i++] <<" ";
    
    f1.close();
    f2.close();
    f3.close();
    cout << "Program executed successfully." << endl;
    return 0;
}
