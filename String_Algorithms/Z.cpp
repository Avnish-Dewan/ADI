
#include<bits/stdc++.h>

using namespace std;

int* computeArray(char *pattern)
{
    cout<<pattern<<endl;
    int *arr=new int[strlen(pattern)];
    int i;
    for(i=0;pattern[i]!='$';i++)
    {
        arr[i]=0;
    }

    arr[i++]=0;
    int j=0,count=0;
    for(;i<=strlen(pattern);i++)
    {
        if(pattern[i]==pattern[j])
        {
            count++;
            j++;
        }
        else
        {
            arr[i-j]=count;
            i=i-j+1;
            j=0;
            count=0;
        }
        
    }

    return arr;
}

void Z(char *txt,char* pattern)
{
    int size=strlen(txt)+strlen(pattern)+1;
    char *str=new char[size];
    strcpy(str,pattern);
    strcat(str,"$");
    strcat(str,txt);
    //cout<<arr;
    int *arr=computeArray(str);

    int len=strlen(pattern);

    for (int i = 0; i < size; i++)
    {
        if(arr[i]==len)
        {
            cout<<"Found At index:"<<i-len-1<<endl;
        }
    }
    
}

int main()
{
    char pattern[50];
    char txt[50];
    cin>>txt>>pattern;
    Z(txt,pattern);
}
