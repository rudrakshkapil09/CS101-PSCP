//Program that sorts an unsorted list of elements and displays how many steps each of the 3 methods takes.
//Rudraksh Kapil - 951775 - M - 12/3/2018

#include <iostream>
using namespace std;

//Function & array declarations
int numberBS[30];
int numberSS[30];
int numberIS[30];       //3 arrays so that after sorting by one method the original values are retained for the other methods

int bubbleSort(int a[], int n);
int selectionSort(int a[], int n);
int insertionSort(int a[], int n);              //return the number of steps in each case
void readArrays(int a[], int b[], int c[], int n);
void displayArray(int a[], int n);

//[MAIN]
int main()
{
    cout << "\n[This is a program to sort an unsorted list of elements and print number of steps]\n\n";
    
    //getting size of list and calling function to read elements of list
    int size;
    cout << "Enter number of elements in list (<30): ";
    cin >> size;
    readArrays(numberBS,numberSS, numberIS, size);
    
    //declaring variables and calling functions to get number of steps in each case
    int bubble, select, insert;
    bubble = bubbleSort(numberBS, size);
    select = selectionSort(numberSS, size);
    insert = insertionSort(numberIS, size);
    
    //displaying results
    displayArray(numberIS, size);               //any of the arrays can be used here
    cout << "\n===========+===========\n";
    cout << "   METHOD  |   STEPS   \n";
    cout << "-----------+-----------\n";
    cout << "   Bubble  |\t" << bubble << endl;
    cout << " Selection |\t" << select << endl;
    cout << " Insertion |\t" << insert << endl;
    cout << "===========+===========\n";        //displaying steps taken in table format
    
    return 0;
}

//Function definitions
//1.Function to get elements of array
void readArrays(int a[], int b[], int c[], int n)
{
    
    cout << "Enter the elements of the list:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
        c[i] = a[i];        //make two copies of the list
    }
    
    return;
}

//2.Function to display the elements of an array (sorted)
void displayArray(int a[], int n)
{
    cout << "The ordered list is:\n";
    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    
    cout << endl;
    
    return;
}

//3.Function to carry out bubble sort
int bubbleSort(int a[], int n)
{
    int temp, steps = 0;

    //loop to carry out sorting
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-1-i; j++)
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;      //swapping
                steps++;
            }
    
    return steps;
}

//4.Function to carry out selection sort
int selectionSort(int a[], int n)
{
    int pos, temp, steps = 0;
    
    for (int i = 0; i < n-1; i++)
    {
        pos = i;
        
        //loop to determine number to swap with
        for (int j = i+1; j <= n-1; j++)
            if (a[pos] > a[j])
                pos = j;
        
        temp = a[i];
        a[i] = a[pos];
        a[pos] = temp;
        steps++;        //increase count each time swapping is done
    }
    
    return steps;
}

//5.Function to carry out insertion sort
int insertionSort(int a[], int n)
{
    int i, j, temp, steps = 0;      //temp is to be inserted
    
    for(i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        
        while (j >= 0 && a[j] > temp)
        {
            a[j+1] = a[j];      //shift array to the right while temp is less than sorted list
            j--;
        }
        
        a[j+1] = temp;
        steps++;            //increase count each time an insertion is done
    }
    
    return steps;
}

