#include <iostream>
#include <cstring>
using namespace std;

//function definition
int isPalindrome(char str[], int si, int ei);

//MAIN
int main()
{
    cout << "\n\n[This is a program to check if a given string is a palindrome]\n";
    
    char s[50];
    cout << "Enter string: ";
    cin >> s;
    
    if (isPalindrome(s, 0, strlen(s) - 1) == 1)
        cout << s << " is a Palindrome." << endl;
    else
        cout << s << " is not a Palindrome." << endl;
}

int isPalindrome(char str[], int si, int ei){
    if (si < ei)
        return ((str[si] == str[ei]) && isPalindrome(str, si + 1, ei - 1));
    else
        return 1;
}
