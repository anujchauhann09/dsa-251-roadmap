#include <bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n) {
    int low = 0, mid = 0, high = n - 1;

    // Iterate over the array
    while (mid <= high) {
        if (arr[mid] == 0) {
            // Swap arr[low] and arr[mid], increment low and mid
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            // Move mid ahead for 1
            mid++;
        } else {
            // Swap arr[mid] and arr[high], decrement high
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    // Test case 1: Array with mixed 0s, 1s, and 2s
    int arr1[] = {0, 1, 2, 1, 0, 2, 1, 0};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    sort012(arr1, n1);
    cout << "Sorted array 1: ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    // Test case 2: Array with only 0s
    int arr2[] = {0, 0, 0, 0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    sort012(arr2, n2);
    cout << "Sorted array 2: ";
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // Test case 3: Array with only 2s
    int arr3[] = {2, 2, 2, 2};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    sort012(arr3, n3);
    cout << "Sorted array 3: ";
    for (int i = 0; i < n3; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity: 
O(n), as we only iterate over the array once.

Space Complexity: 
O(1), since the sorting is done in-place and we don't require any extra space.
*/