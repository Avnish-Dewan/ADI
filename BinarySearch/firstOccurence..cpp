#include<bits/stdc++.h>

using namespace std;

int getFirstOccurrence(int *arr,int n,int k)
{
  int left=0;
  int right=n-1;
  int pos=-1;
  while(left<=right)
  {
    int mid=(left+right)/2;
    if(arr[mid]==k)
    {
      pos=mid;
      right=mid-1;
    }
    else if(arr[mid]>k)
    {
      right=mid-1;
    }
    else
      left=mid+1;
  }
  return pos;
}


int main() {
    int n, k;
    cin >> n >> k;
    int * arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);


    cout << getFirstOccurrence(arr,n,k);
}