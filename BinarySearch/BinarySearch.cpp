#include<bits/stdc++.h>

using namespace std;

//Recursive Binary Search
int binarySearch(int *arr, int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (arr[mid] == x) 
            return mid; 
  
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
    return binarySearch(arr, mid + 1, r, x); 
    }  
    return -1; 
} 


//Iterative Binary Search
int binarySearch(int *arr,int n,int key)
{
    int left=0,right = n-1;

    while (left<right)
    {
        int mid = left + (right-left)/2;
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid +1;
        }
    }
    return -1;
}

int main()
{
    int n,key;
    cin>>n>>key;
    int *arr= new int[n];

    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    sort(arr,arr+n);

    int index=binarySearch(arr,n,key);
    if(index!=-1)
    {
        cout<<"Element Found At index : "<<index<<endl;
    }
    else
    {
        cout<<"Element Not Found"<<endl;
    }
    
}