#include<bits/stdc++.h>

using namespace std;

void printArray(int **board,int n)
{
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<board[i][j]<<" ";   
        }
        cout<<endl;
    }
}

string s;

bool calculateWays(int **board,int n,int i,int j)
{
    if(i==n-1 && j==n-1)
    {
        s="";
        return true;
    }
    else if((i>=n) ||(j>=n))
    {
        return false;
    }
    else if(board[i][j]==0)
    {
        return 0;
    }
    else
    {
        bool x=calculateWays(board,n,i+1,j);
        bool y=calculateWays(board,n,i,j+1);
        if(x)
        {
            s+="r";
            return true;
        }
        if(y)
        {
            s+="d";
            return true;
        }
        return false;

    }
}

int main()
{
    int N;
    cin>>N;
    int **board=new int*[N];
    for(int i=0;i<N;i++)
    {
        board[i]=new int[N];
    }

    for(int i=0;i<N;i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>board[i][j];  
        }
    }
    if(calculateWays(board,N,0,0))
    {
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
    return 0;
    //printArray(board,N);
}