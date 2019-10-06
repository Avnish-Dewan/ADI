#include<bits/stdc++.h>
using namespace std;

void generateBinaryStrings(string str,int n)
{
    if(str.length()==n)
    {
            cout<<str<<endl;
    }
    else if(str.length()>1)
    {
        if(str.at(1)=='1')
        {
            generateBinaryStrings(str+"0",n);
            generateBinaryStrings(str+"1",n);    
        }
    }
    else
    {
        generateBinaryStrings(str+"0",n);
        generateBinaryStrings(str+"1",n);
    }
}

int main()
{
    int n;
    cin>>n;

    string str;

    generateBinaryStrings(str,n); 
}
