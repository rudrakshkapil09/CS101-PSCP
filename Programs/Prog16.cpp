#include <iostream>
#include <cstring>
using namespace std;

//function & array definitions
int c[1000];
int Add(int c[], int a[], int na, int b[], int nb);
int Sub(int c[], int a[], int na, int b[], int nb);
int Mult(int c[], int a[], int na, int b[], int nb);
void Shift(int a[], int n);
int Mult_1(int c[], int a[], int na, int x);
void Input(int a[], int na, int num);
void Output(int a[], int n);

//MAIN
int main()
{
    cout << "\n\n[This is a program for big number arithmetic]\n\n";
    char choice;
    int num, *arrayA, na, *arrayB, nb, nc;
    while (1) {
        cout << "A - addition\nS - subtraction\nM - multiplication\nQ - quit\nEnter choice: ";
        cin >> choice;
        choice = toupper(choice);
        
        if (choice == 'Q')
            break;
        
        cout << "Enter digits of first number: ";
        cin >> na;
        cout << "Enter first number: ";
        cin >> num;
        arrayA = new int[na];
        Input(arrayA, na, num);
        
        cout << "Enter digits of second number: ";
        cin >> nb;
        cout << "Enter second number: ";
        cin >> num;
        arrayB = new int[nb];
        Input(arrayB, nb, num);
        
        switch (choice) {
            case 'A':
                nc = Add(c, arrayA, na, arrayB, nb);
                break;
            case 'S':
                nc = Sub(c, arrayA, na, arrayB, nb);
                break;
            case 'M':
                nc = Mult(c, arrayA, na, arrayB, nb);
                break;
        }
        
        cout << "Answer:\n";
        for (int i = 0; i < nc; i++)
            cout << c[i];
    }
    return 0;
}

//Functions
int Add(int c[], int a[], int na, int b[], int nb)
{
    int nc, carry = 0, val;
    int i;
    
    nc = (na > nb) ? na : nb;
    
    for(i = 0; i < nc; i++)
    {
        val = (a[i] + b[i] + carry);
        c[i] = val % 10;
        carry = val / 10;
    }
    
    if (carry = 0)
    {
        c[i] = carry;
        nc++;
    }
    
    return nc;
}

int Sub(int c[], int a[], int na, int b[], int nb)
{
    for(int i = 0; i < 513; i++) {
        c[512 - i] = a[512 - i] - b[512 - i];
        
        if (a[512 - i] > b[512 - i]) {
          		a[512 - i - 1] = a[512 - i - 1] - 1;
          		a[512 - i] = a[512 - i] + 10;
        }
    }
    
    
}

void Shift(int a[], int na)
{
    int i;
    
    for (i = na; i > 0; i--)
        a[i] = a[i-1];
    
    a[0] = 0;
}

int Mult_1(int c[], int a[], int na, int x)
{
    int i, carry = 0, val;
    
    for (i = 0; i < na; i++)
    {
        val = a[i] * x + carry;
        c[i] = val % 10;
        carry = val / 10;
    }
    
    while (carry > 0)
    {
        c[i++] = carry % 10;
        carry = carry / 10;
    }
    
    return i;
}

int Mult(int c[], int a[], int na, int b[], int nb)
{
    int t[1000];
    int nc = 0, nt;
    int i, j;
    
    for (i = 0; i < 1000; i++)
        c[i] = 0;
    
    for (i = nb-1; i > 0; i++)
    {
        nt = Mult_1(t, a, na, b[i]);
        Shift(c, nc);
        nc++;
        nc = Add(c, c, nc, t, nt);
    }
    
    return nc;
}

void Input(int a[],int na,int num)
{
    for(int i=na-1;i>=0;i--)
    {
        a[i]=num%10;
        num=num/10;
    }
}

void Output(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i]
        cout << endl;
}
