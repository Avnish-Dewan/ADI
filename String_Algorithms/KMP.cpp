#include<bits/stdc++.h>

using namespace std;

int* computeArray(char* pattern)
{
    int *arr=new int[strlen(pattern)];
    arr[0]=0;

    int i=0;
    int count=0;
    int j=0;

    for ( i = 1; pattern[i]!='\0' ; i++)
    {
        if(pattern[i]==pattern[j])
        {
            count++;
            arr[i]=count;
            j++;
        }
        else
        {
            j=0;
            count=0;
        }
    }
    return arr;
}

void KNM(char *txt,char *pattern)
{
    int *arr=computeArray(pattern);
    // for(int i=0;i<strlen(pattern);i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    int i=0;
    int j=0;

    while(i<strlen(txt))
    {
        if(txt[i]==pattern[j])
        {
            i++;
            j++;
        }
        if(j==strlen(pattern))
        {
            cout<<"Found At Index :"<<i-j<<endl;
            j=arr[j-1];
        }
        else if(i<strlen(txt) && pattern[j]!=txt[i])
        {
            if(j!=0)
            {
                j=arr[j-1];
            }
            else
            {
                i++;
            }
            
        }
    }
}

int main()
{
    char pattern[50];
    char txt[50];
    cin>>txt>>pattern;
    KNM(txt,pattern);
}