//Program that allows user to insert, delete, replace or search for an element in a list of elements.
//Rudraksh Kapil - 951775 - M - 12/3/2018

#include <iostream>
using namespace std;

int list[100];
void getChoice(char &c);
void doOperation(char c, int a[], int &n);
void inputArray(int a[], int n);
void showArray(int a[], int n);
void addElement(int a[], int &n);
void deleteElement(int a[], int &n);
void replaceElement(int a[], int n);
void lookForElement(int a[], int n);


int main()
{
    cout << "\n[This is a program that edits a list of elements according to the user]\n\n";
    
    int size;
    char choice = 'o';
    

    cout << "Enter number of elements: ";
    cin >> size;
    

    while (choice != 'q' && choice != 'Q')
    {
        getChoice(choice);
        doOperation(choice, list, size);
    }
    
    return 0;
    
}

void getChoice (char &c)
{
    cout << "What would you like to do?\n";
    cout << "I -> Enter a new array\n";
    cout << "A -> Add a new element to the array\n";
    cout << "R -> Replace a pre-existing element from the array\n";
    cout << "D -> Delete a pre-existing element from the array\n";
    cout << "L -> Search for an element in the array\n";
    cout << "S -> Show the elements of the array\n";
    cout << "\nEnter choice: ";
    cin >> c;
    
    return;
}


void doOperation(char c, int a[], int &n)
{
    switch (c) {
        case 'i':
        case 'I':
            inputArray(a, n);
            break;
            
        case 's':
        case 'S':
            showArray(a, n);
            break;
            
        case 'a':
        case 'A':
            addElement(a, n);
            break;
            
        case 'r':
        case 'R':
            replaceElement(a, n);
            break;
            
        case 'd':
        case 'D':
            deleteElement(a, n);
            break;
            
        case 'l':
        case 'L':
            lookForElement(a, n);
            break;
            
        case 'q':
        case 'Q':
            return;
            
        default:
            cout << "Please enter a valid choice.\n";
    }
    
    return;
}


void inputArray(int a[], int n)
{
    cout << "Enter the elements of the new array:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    return;
}

void showArray(int a[], int n)
{
    cout << "The elements of the new array are:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    
    cout << endl;
    return;
}

void addElement(int a[], int &n)
{
    int key, pos;
    cout << "Enter integer to insert: ";
    cin >> key;
    cout << "Enter position to insert the integer: ";
    cin >> pos;

    for (int i = n; i >= pos-1; i--)
        a[i+1] = a[i];
    a[pos-1] = key;
    n++;
    
    return;
}

void deleteElement(int a[], int &n)
{
    int pos;
    cout << "Enter postion of element to delete: ";
    cin >> pos;
    
    for (int i = pos-1; i <= n; i++)
        a[i] = a[i+1];
    a[n] = 0;
    n--;
    
    return;
}


void replaceElement(int a[], int n)
{
    int key, pos;
    cout << "Enter position of integer to replace: ";
    cin >> pos;
    cout << "Enter new integer: ";
    cin >> key;
    
    a[pos-1] = key;
    
    return;
}

void lookForElement(int a[], int n)
{
    int key, left, mid, right, pos = -1;
    cout << "Enter integer to search for: ";
    cin >> key;
    
    left = 0;
    right = n - 1;
    
    while(left <= right)
    {
        mid = (left + right) / 2;
        
        if (a[mid] == key)
        {
            pos = mid;
            break;
        }
        else if(a[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
 
    if (pos > 0)
        cout << key << " was found at position " << pos+1 << endl;
    else
        cout << key << " is not in the list." << endl;
    
    return;
}
