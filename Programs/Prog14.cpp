#include<iostream>
using namespace std;

int a[50][50],b[50][50],c[50][50];
int i,j,m,n,o,p,l=1,r;

void doAddition();
void doTranspose();
void doInverse();
void doMultiplication();
void doTriangleForm();

int main()
{
    cout << "\n\n[This is a program to perform matrix operations]\n";
    
    char choice;
    
    while(1){
        cout << "Enter choice (A/M/T/I/J-triangle/S/Q-uit): ";
        cin >> choice;
        
        choice = toupper(choice);
        
        switch (choice) {
            case 'A':
                doAddition();
                break;
            case 'M':
                doMultiplication();
                break;
            case 'T':
                doTranspose();
                break;
            case 'I':
                doInverse();
                break;
            case 'J':
                doTriangleForm();
                break;
        }
        
        if (choice == 'Q')
            break;
    }
    
    return 0;
}


void doAddition()
{
    cout << "\nEnter the order of matrix a (must be m*n): "<<endl;
    cin >> m;
    
    cout << "* \n";
    cin >> n;
    
    cout << "Enter the order of matrix b (must be o*p): "<<endl;
    cin >> o;
    
    cout << "* \n";
    cin >> p;
    
    if( m == o && n == p){
        cout<<"Addition possible."<<endl;
        l = 1;
    }
    
    else{
        cout << "Addition not possible.";
        l = 0;
    }
    
    if (l){
        cout<<"\n\nEnter the elements of matrix 1: "<<endl;
        for (i=1;i<=m;i++)
            for (j=1;j<=n;j++)
                cin>>a[i][j];
        
        cout<<"\nEnter the elements of matrix 2: "<<endl;
        for (i=1;i<=o;i++)
            for (j=1;j<=p;j++)
                cin>>b[i][j];
        
        for (i=1;i<=m;i++)
            for (j=1;j<=n;j++)
                c[i][j]=a[i][j]+b[i][j];
        
        cout << "Addition:\n";
        for (i=1;i<=m;i++){
            cout<<endl;
            for (j=1;j<=p;j++)
                cout<<c[i][j]<<" ";
        }
        
    }
}

void doMultiplication()
{
    cout<<"\nEnter the order of matrix a (must be m*n): "<<endl;
    cin>>m;
    cout<<"* \n";
    cin>>n;
    cout<<"Enter the order of matrix b (must be o*p): "<<endl;
    cin>>o;
    cout<<"* \n";
    cin>>p;
    
    if (n==o){
        cout<<"Multiplication possible "<<endl;
    }
    
    else{
        cout<<"Multiplication not possible ";
        l=0;
    }
    
    if (l){
        cout<<"\n\nEnter the elements of matrix 1: "<<endl;
        for (i=1;i<=m;i++){
            for (j=1;j<=n;j++)
                cin>>a[i][j];
        }
        
        cout<<"\nEnter the elements of matrix 2: "<<endl;
        for (i=1;i<=o;i++){
            for (j=1;j<=p;j++)
                cin>>b[i][j];
        }
        
        cout<<"\n\n\nMultiplication:\n";
        for (i=1;i<=m;i++){
            for (j=1;j<=p;j++){
                c[i][j]=0;
                for (int k=1;k<=n;k++){
                    c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
                }
            }
        }
        
        for (i=1;i<=m;i++){
            cout<<endl;
            for (j=1;j<=p;j++)
                cout<<c[i][j]<<" ";
        }
    }
}

void doTranspose()
{
    cout<<"\nEnter the order of the matrix (must be m*n): "<<endl;
    cin>>m;
    cout<<"* \n";
    cin>>n;
    
    if (l){
        cout<<"\n\nEnter the elements of matrix: "<<endl;
        for (i=1;i<=m;i++)
            for (j=1;j<=n;j++)
                cin>>a[i][j];
        
        for(i=1; i<=m; i++)
            for(j=1; j<=n; j++)
                b[i][j]=a[j][i];
        
        cout<<"Transpose of the Matrix is :\n";
        for(i=1; i<=m; i++)
        {
            for(j=1; j<=n; j++)
                cout << b[i][j];
            cout<<"\n";
        }
    }
}

void doInverse()
{
    float determinant = 0;
    
    if (m == n)
        cout<<"Inverse possible."<<endl;
    else{
        cout<<"Inverse not possible.\n";
        l=0;
    }
    
    if (l){
        cout<<"\n\nEnter the elements of 3 x 3 matrix: "<<endl;
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
                cin>>a[i][j];
        
        for(i = 0; i < 3; i++)
            determinant = determinant + (a[0][i] * (a[1][(i+1)%3] * a[2][(i+2)%3] - a[1][(i+2)%3] * a[2][(i+1)%3]));
        
        cout<<"\n\nDeterminant: "<<determinant;
        
        cout<<"\n\nInverse of matrix is: \n";
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++)
                cout<<((a[(j+1)%3][(i+1)%3] * a[(j+2)%3][(i+2)%3]) - (a[(j+1)%3][(i+2)%3] * a[(j+2)%3][(i+1)%3]))/ determinant<<"\t";
            
            cout<<"\n";
        }
    }
}

void doTriangleForm()
{
    cout << "Enter order of matrix (m*n):\n";
    cin >> m >> n;
    
    cout<<"\n\nEnter the elements of matrix: "<<endl;
    
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            cin>>b[i][j];
    
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            c[i][j] = b[i][j];
    
    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++){
            if (i < j)
                b[i][j] = 0;
            if (i > j)
                c[i][j] = 0;
        }
    
    
    cout<<"Lower Triangle of the Matrix is :\n";
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
            cout << b[i][j];
        cout<<"\n";
    }
    
    cout<<"Upper Triangle of the Matrix is :\n";
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
            cout << c[i][j];
        cout<<"\n";
    }
}
