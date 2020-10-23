//Program to find sum of diagonal elements of a square matrix and determine if it is upper triangular
//Rudraksh Kapil - 951775 - M - 10/4/2018

#include<iostream>
using namespace std;

int main()
{
    cout << "\n\n[Program to find sum of diagonal elements of a square matrix and determine if it is upper triangular]\n";
    
    int a[10][10];
    int i, j, order, sum=0, d=0;
    
    cout << "Enter the order of the matrix: ";
    cin >> order;
    
    cout<<"enter elements of matrix"<<endl;
    
    for(i = 0; i < order ; i++)
    {
        for(j = 0; j < order; j++)
            cin >> a[i][j];
        cout << endl;
    }
    
    for(i = 0;i < order; i++)
        sum += a[i][i];
    
    cout << "Sum = " << sum << endl;
    
    for(i = 1; i < order; i++)
        for(j = 0; j < order-1; j++)
            if(i > j && a[i][j] == 0)
                d++;
    
  	 if( d == (order*(order-1))/2)
         cout << "Yes, the matrix is upper triangular" << endl;
     else
        	cout << "No, the matrix is not upper triangular" <<endl;
    
    return 0;
}
