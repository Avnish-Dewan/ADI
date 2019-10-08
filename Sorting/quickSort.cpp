#include<bits/stdc++.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}


/*
 * Partiton The Array
 */

int partition(int *A,int low,int high)
{
    int pivot=A[high];
    int i=low-1;
    int j;
    for (j = 0; i < high; i++)
    {
        if(A[j]<=pivot)
        {
            i++;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[j]);
    return i+1;    
}

void quickSort(int *A,int low,int high)
{
    if(low<high)
    {
        int pivot_index=partition(A,low,high);
        quickSort(A,low,pivot_index-1);
        quickSort(A,pivot_index+1,high);
    }
}

int main()
{
	int n;
	std::cin>>n;
	int *a=new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin>>a[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		std::cout<<a[i]<<" ";
	}
    
	quickSort(a,0,n-1);

	for (int i = 0; i < n; i++)
	{
		std::cout<<a[i]<<" ";
	}
}