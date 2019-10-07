#include<bits/stdc++.h>

using namespace std;

int getPairsCount(int * arr, int n, int sum) {
    int count = 0;
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int s = arr[left] + arr[right];
        if (s == sum) {
            if (arr[left] == arr[left + 1]) {
                int temp = 0;
                while (temp < right) {
                    if (arr[temp] + arr[right] == sum) {
                        count++;
                    }
                    temp++;
                }
                right--;
            } else {
                left++;
                count++;
            }
        } else if (s < sum) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int main() {
    int n, sum;
    cin >> n >> sum;
    int * arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);


    cout << getPairsCount(arr, n, sum);
}
