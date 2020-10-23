
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int main()
{
    cout << "\n\n[This is a program to calculate the frequency of words and characters in a series of inputs]\n";
    
    //char lines[20][100];
    char words[100][20];
    //int arr[256];
    int frequency[100];
    int i,j,num,c = 0;
    //int k;
    char *tok;
    char tword[20];
    
    /*for(i=0;i<255;i++)
        arr[i]=0;*/
    
    cout<<"Enter the number of lines of text to enter: \n";
    cin>>num;
    num++;
    
    //getting line inputs
    cout << "Enter the text:\n";
    for(i=0;i<num;i++)
        cin.getline(lines[i],100);
    
    //splitting up lines into words
    for(i=0;i<num;i++)
    {
        tok=strtok(lines[i]," .,");
        while(tok!=NULL)
        {
            strcpy(tword,tok);
            /*k=0;
            while(tword[k]!='\0')
            {
                arr[(int)tword[k]]++;
                k++;
            }*/
            for(j=0;j<strlen(tword);j++)
                tword[j]=toupper(tword[j]);
            for(j=0;j<c;j++)
                if(strcmp(words[j],tword)==0)
                {
                    frequency[j]++;
                    break;
                }
            if(j>=c)
            {
                strcpy(words[c],tword);
                frequency[c]=1;
                c++;
            }
            tok=strtok(NULL," .,");
        }
    }
    
    //displaying output
    cout<<"\nWORD\t|\tFREQUENCY\n";
    for(i=0;i<c;i++)
    {
        cout<<words[i]<<"\t|\t"<<frequency[i]<<endl;
    }
    /*
    cout<<"\nCHARACTER\t|\tFREQUENCY\n";
    for(i=0;i<255;i++)
    {
        if(arr[i]!=0)
        {
            cout<<(char) i<<"\t\t|\t"<<arr[i]<<endl;
        }
    }
    return 0;
     */
}
