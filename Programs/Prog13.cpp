
#include <iostream>
using namespace std;

//Function & array declarations
int poly1[10];
int poly2[10];
int poly_res[10];		//position indicates power - (x^pos)
void getChoice(int a[], int b[], int c[], int hp1, int hp2);
void readPoly(int a[], int hp);
void addPoly(int a[], int b[], int c[], int hp1, int hp2);
void subPoly(int a[], int b[], int c[], int hp1, int hp2);
void multPoly(int a[], int b[], int c[], int hp1, int hp2);
void showAns(int c[]);

//[MAIN]
int main()
{
    cout << "\n[This is a program to carry out polynomial addition, subtraction or multiplication]\n\n";
    
    //getting size inputs & calling function to read coefficients
    int hp1, hp2, choice;
    
    cout << "Enter highest power of first polynomial: ";
    cin >> hp1;
    readPoly(poly1, hp1);
    
    cout << "Enter highest power of second polynomial: ";
    cin >> hp2;
    readPoly(poly2, hp2);
    
    //function to get choice and answer & display output
    getChoice(poly1, poly2, poly_res, hp1, hp2);
    return 0;
}

//Function definitions
//1.Function to display a menu that lets the user indicate which operation is needed
void getChoice(int a[], int b[], int c[], int hp1, int hp2)
{
    //getting choice
    char choice;
    cout << "Choose which operation to carry nut (A/S/M): ";
    cin >> choice;
    
    //switch statement to carry out proper operation function call
    switch (choice) {
        case 'A':
        case 'b':
            addPoly(a, b, c, hp1, hp2);
            showAns(c);
            break;
        case 'S':
        case 's':
            subPoly(a, b, c, hp1, hp2);
            showAns(c);
            break;
        case 'M':
        case 'm':
            multPoly(a, b, c, hp1, hp2);
            showAns(c);
            break;
    }
    
    return;
    
void ShowArray(int x[], int n)
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
                else                                                                                                                         z[k++] = y[j++];
                
                t++;                                                                                                                                                }
            //loops to deal with leftovers
            while (i < m)
                z[k++] = x[i++];
            while (j < n)                                                                                                                                                                                                                                                                                 z[k++] = y[j++];
            
            return;
        }
        
        //2.Function to read polynomial in reverse order
        void readPoly(int a[], int hp)
        {
            cout << "Enter the coefficiencts of the polynomial starting with the highest power:\n";
            
            for (int i = hp; i >= 0; i--)
                cin >> a[i];
            
            return;
        }
        
        //3.Function to display the answer as a polynomial
        void showAns(int a[])
        {
            cout << "The resulting polynomial is: \n";
            
            //print only non 0 values
            for (int i = 100; i >= 0; i--)		//pos <- i
                if (a[i] != 0)
                    cout << a[i] << "x^" << i << " + ";
            
            cout << "\b\b\b" << endl;
            
            return;
        }
        
        //4.Function to add two polynomials
        void addPoly(int a[], int b[], int c[], int hp1, int hp2)
        {
            int res_hp;			//size of resultant highest power
            hp1 > hp2 ? res_hp = hp1 : hp2;
            
            //loop to add each of the terms to c
            for (int i = 0; i <= res_hp; i++)
                c[i] = a[i] + b[i];
            
            return;
        }
        
        //5.Function to subtract two polynomials
        void subPoly(int a[], int b[], int c[], int hp1, int hp2)
        {
            int res_hp;
            hp1 > hp2 ? res_hp = hp1 : hp2;
            
            for (int i = 0; i <= res_hp; i++)
            {
                if (a[res_hp] > b[res_hp])		//sign is dependent on the new highest power
                    c[i] = a[i] - b[i];
                else
                    c[i] = b[i] - a[i];
            }
            
            return;
        }
        
        //6.Function to multiply two polynomials
        void multPoly(int a[], int b[], int c[], int hp1, int hp2)
        {
            int res_hp;
            hp1 > hp2 ? res_hp = hp1 : hp2;
            
            int i, j;
            c[i+j] = 0;
            
            for(i = 0; i < res_hp; i++)
                for(j = 0; j <res_hp ;j++)
                    c[i+j] += a[i]*b[j];
        }
