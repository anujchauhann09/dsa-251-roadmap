#include <bits/stdc++.h>
using namespace std;

// Function to sort the array containing only 0s, 1s, and 2s
void sort012(int *arr, int n) {
    // Initialize counters for 0s, 1s, and 2s
    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;

    // Count the number of 0s, 1s, and 2s
    for(int i = 0; i < n; i++) {
        switch(arr[i]) {
            case 0: countZero++; break;
            case 1: countOne++; break;
            case 2: countTwo++; break;
        }
    }

    // Fill the array with 0s, 1s, and 2s based on the counts
    for(int i = 0; i < countZero; i++) { 
        arr[i] = 0; 
    }

    for(int i = countZero; i < (countZero + countOne); i++) { 
        arr[i] = 1;
    }

    for(int i = (countZero + countOne); i < (countZero + countOne + countTwo); i++) { 
        arr[i] = 2;
    }
}

int main() {
    // Test case 1: Array with mixed 0s, 1s, and 2s
    int arr1[] = {0, 1, 2, 1, 0, 2, 1, 0};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    sort012(arr1, n1);
    cout << "Sorted array 1: ";
    for(int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    // Test case 2: Array with only 0s
    int arr2[] = {0, 0, 0, 0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    sort012(arr2, n2);
    cout << "Sorted array 2: ";
    for(int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // Test case 3: Array with only 2s
    int arr3[] = {2, 2, 2, 2};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    sort012(arr3, n3);
    cout << "Sorted array 3: ";
    for(int i = 0; i < n3; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity: 
O(n), where n is the size of the array.

Space Complexity: 
O(1). The algorithm uses a constant amount of extra space (just three integer variables to count the occurrences of 0s, 1s, and 2s), regardless of the size of the input array.
*/