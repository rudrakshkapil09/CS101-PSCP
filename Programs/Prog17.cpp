#include<iostream>
using namespace std;

int main()
{
    cout << "\n\n[This is a program to solve a user defined maze]\n\n";
    
    int dim, start, stop, i, j;
    bool cells[20][20];
    bool before[2][2];
    cout << "Enter the order of the square maze:\n";
    cin >> dim;
    for(i=0;i<dim;i++)
        for(j=0;j<dim;j++)
        {
            cout<<"Enter the condition of "<<i+1<<"th row and "<<j+1<<"th column";
            cin>>cells[i][j];
        }
    
    cout<<"Enter the start position in the 1st row: ";
    cin>>start;
    cout<<"Enter the stop position on the last row: \n";
    cin>>stop;
    i=0;j=start;
    while(i!=dim-1||j!=stop)
    {
        if(cells[i+1][j]==1)
        {
            cout<<"DOWN one space \n";
            i++;
            continue;
        }
        if(cells[i][j-1]==1)
        {
            cout<<"LEFT one space \n";
            j--;
            continue;
        }
        if(cells[i][j+1]==1)
        {
            cout<<"RIGHT one space \n";
            j++;
            continue;
        }
    }
    
    cout<<"Congratulations! You made it.";
    
    return 0;
}

