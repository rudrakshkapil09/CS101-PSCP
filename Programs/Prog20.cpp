//Program to find a sub-string inside a string
//Rudraksh Kapil - 951775 - M - 9/4/2018

#include<iostream>
#include<string>
using namespace std;

int main()
{
    cout << "\n\n[This is a program to look for a specified sub-string inside a given string]\n";
    
    string s1,s2;
    int i,j,k,f;
    
    cout<<"Enter main string: "<<endl;
    getline(cin,s1);
    cout<<"Enter sub string to be located: "<<endl;
    getline(cin,s2);
    
    for(i=0;i<s1.length();i++)
    {
        j = 1;
        k = i;
        f = 1;
        
        while(j!=s2.length())
        {
            if(s1[k++]==s2[j++])
                f++;
            else
                break;
        }
        
        if(f==s2.length())
            cout<<"Sub string "<<s2<<" is found at "<<i<<"th position"<<endl;
    }
    
    return 0;
}
