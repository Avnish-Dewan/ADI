#include<bits/stdc++.h>

using namespace std;

void print(int *array, int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void merge(int *array, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int Left[n1], Right[n2];

    for (i = 0; i < n1; i++)
        Left[i] = array[left + i];
    for (j = 0; j < n2; j++)
        Right[j] = array[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j])
            array[k++] = Left[i++];
        else
            array[k++] = Right[j++];
    }

    while (i < n1)
        array[k++] = Left[i++];

    while (j < n2)
        array[k++] = Right[j++];
}

void mergeSort(int array[], int left, int right) {
    int i;
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}


int main() {
    int n;
    cin>>n;
    int *arr=new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    mergeSort(arr, 0, n-1);

    print(arr, n );
    return 0;
}
