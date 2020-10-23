#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    cout << "\n[This is a program to print out a complete telephone number]\n\n";
    
    char num[17];		//taken as (8760)9760-113113
    char ar[4],p1[4],p2[6];
    char *tok1,*tok2,*tok3;
    
    cout << "Enter the phone number (17 characters):\n";
    for(int i = 0; i < 17; i++)
        cin >> num[i];
    
    //seperating tokens
    tok1 = strtok(num+1,")");
    strcpy(ar, tok1);
    
    tok2 = strtok(num + 6,"-");
    strcpy(p1,tok2);
    
    tok3 = strtok(num + 11, "\0");
    strcpy(p2, tok3);
    
    //showing parts
    cout << "Area code\t\t\t=>\t";
    for(int i = 0; i < 4; i++)
        cout << ar[i];
    cout << endl;
    
    cout << "First part of phone number\t=>\t";
    for(int i = 0; i < 4; i++)
        cout << p1[i];
    cout << endl;
    
    cout << "Second part of phone number\t=>\t";
    for(int i = 0; i < 6; i++)
        cout << p2[i];
    cout << endl;
    
    //displaying full number
    cout<<"\nComplete Number\t=>\t";
    for(int i = 0; i < 4; i++)
        cout << ar[i];
    for(int i = 0; i < 4; i++)
        cout << p1[i];
    for(int i = 0; i < 6; i++)
        cout << p2[i];
    
    cout << endl;
    return 0;
}
