#include<iostream>
#include<string>
using namespace std;

int main()
{
    cout << "\n\n[Program to sort in lexographical order]\n";
    
    int n;
    string s[20];
    string t;
    
    cout << "Enter the total number of words to be entered" << endl;
    cin >> n;
    cout << endl;
    for(int i = 0; i <= n; i++)
        getline(cin,s[i]);
    
    for(int i = 0; i <= n-1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(s[i] > s[j])
            {
                t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }
    }
    cout << "In lexicographic order: " << endl;
    for(int i=0;i<=n;i++)
        cout<<s[i]<<endl;
}
