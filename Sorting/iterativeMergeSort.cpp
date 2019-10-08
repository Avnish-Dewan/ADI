#include<bits/stdc++.h>

using namespace std;



void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	\i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 


void mergeSort(int arr[], int n) 
{ 
    int curr;  
                    
    int st;

    for (curr=1; curr<=n-1; curr = 2*curr) 
    { 
        for (st=0; st<n-1; st += 2*curr) 
        { 
            int mid = min(st + curr - 1, n-1); 

            int right_end = min(st + 2*curr - 1, n-1); 

            merge(arr, st, mid, right_end); 
        } 
    } 
} 

void printArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 

int main() 
{ 
	int n; 
    cin>>n;

    int *arr= new int[n];

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    

	mergeSort(arr, n); 

	printArray(arr, n); 
	return 0; 
} 
