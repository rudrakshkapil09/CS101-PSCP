//Program to create an array using alternate elements from 2 arrays, starting with the first array
//Rudraksh Kapil - 951775 - 19/03/2018

#include <iostream>
using namespace std;

//Function & array declarations
int A[100];
int B[100];
int C[200];                             //New Array to consist of elements from both A and B
void readArray(int x[], int n);
void showArray(int x[], int n);
void joinArrays(int x[], int n, int y[], int m, int z[]);

//[MAIN]
int main()
{
    cout << "\n[This is a program to create an array using alternate elements from 2 arrays]\n\n";
    
    //declaring variables & getting size inputs
    int sizeA, sizeB;
    
    cout << "Enter size of first array: ";
    cin >> sizeA;
    readArray(A, sizeA);    //read first array
    
    cout << "Enter size of second array: ";
    cin >> sizeB;
    readArray(B, sizeB);    //read second array
    
    //function call to get C array & then display it
    joinArrays(A, sizeA, B, sizeB, C);
    showArray(C, sizeA+sizeB);
    
    return 0;
}

//Function definitions
//1.Function to read inputs and store them in an array
void readArray(int x[], int n)
{
    cout << "Enter the elements of the array:\n";
    
    for (int i = 0; i < n; i++)
        cin >> x[i];
    
    cout << endl;
    return;
}

//2.Function to display the elements of an array
void showArray(int x[], int n)
{
    cout << "The elements of the new array are:\n";
    
    for (int i = 0; i < n ; i++)
        cout << *(x + i) << " " <<endl;
    
    cout << endl;
    return;
}

//3.Function to merge two arrays using alternate elements
void joinArrays(int x[], int m, int y[], int n, int z[])
{
    int i=0, j=0, k=0;              //counter variables
    int t = 1;                      //checking even or odd. first is odd, so when odd, store A element into C
    
    //loop to add elements to C alternately
    while (i < m && j < n)
    {
        if (t % 2 != 0)
            z[k++] = x[i++];
        else //if even
            z[k++] = y[j++];
        
        t++;
    }
    
    //loops to deal with leftovers
    while (i < m)
        z[k++] = x[i++];
    while (j < n)
        z[k++] = y[j++];
    
    return;
}

