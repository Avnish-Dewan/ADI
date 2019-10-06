#include<bits/stdc++.h>

using namespace std;

void printBoard(int ** board,int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<board[i][j];
            if(j!=n-1)
            {
                cout<<" ";
            }
            else
            {
                cout<<endl;
            }    
        }
    }
}

bool isSafe(int **board,int row,int col,int n)
{
    int i,j;
    for (i = 0; i < col; i++)
    {
        if(board[row][i])
            return false;
    }
    
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
		if (board[i][j]) 
			return false; 

	for (i = row, j = col; j >= 0 && i < n; i++, j--) 
		if (board[i][j]) 
			return false;
    
    return true;
}

bool solveNqueens(int **board,int n,int col)
{
    //Base Condition indicating all queens are placed
    if(col>=n)
        return true;

    for(int i=0;i<n;i++)
    {
        if(isSafe(board,i,col,n))
        {
            board[i][col]=1;
            if(solveNqueens(board,n,col+1))
            {
                printBoard(board,n);
                cout<<endl<<endl;
            }
            board[i][col]=0; // BackTracking 
        }
    }
    return false;
}

void solveNQueens(int **board,int n)
{
    solveNqueens(board,n,0);   
}


int main()
{
    int n;
    cin>>n;
    int **board=new int*[n];
    for (int i = 0; i < n; i++)
    {
        board[i]=new int[n];
    }
    // printBoard(board,n);
    solveNQueens(board,n);
}