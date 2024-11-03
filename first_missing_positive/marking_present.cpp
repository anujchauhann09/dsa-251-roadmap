#include <bits/stdc++.h>
using namespace std;

// Function to find the smallest missing positive integer in the array
int firstMissing(int arr[], int n) {
    int i = 0;

    // Loop through numbers starting from 1 up to n
    for (i = 1; i <= n; i++) {
        bool isPresent = false; // Flag to check if the current number i is in the array

        // Inner loop to search for the current number i in the array
        for (int j = 0; j < n; j++) {
            if (i == arr[j]) { // If i is found in the array
                isPresent = true; // Mark it as present
                break; // Exit the inner loop since we found the number
            }
        }

        // If the current number i is not present in the array, return it as the answer
        if (!isPresent) {
            return i;
        }
    }

    // If all numbers from 1 to n are found, return n + 1
    return i;
}

int main() {
    // Test cases to check the function
    int arr1[] = {3, 4, -1, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "First missing positive integer in arr1: " << firstMissing(arr1, n1) << endl; // Expected output: 2

    int arr2[] = {1, 2, 0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "First missing positive integer in arr2: " << firstMissing(arr2, n2) << endl; // Expected output: 3

    int arr3[] = {7, 8, 9, 11, 12};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "First missing positive integer in arr3: " << firstMissing(arr3, n3) << endl; // Expected output: 1

    return 0;
}

/*
Time Complexity:
The time complexity of this code is O(n²) because, for each integer from 1 up to n, it iterates through the array to check if that integer exists. This results in a nested loop structure, where the outer loop runs n times (once for each integer to be checked), and the inner loop also runs up to n times (to search through the array). As a result, the two nested loops yield a time complexity of O(n * n) or O(n²), which becomes inefficient for large arrays.

Space Complexity:
The space complexity is O(1), as the function uses only a constant amount of extra memory (a boolean flag and a few integer variables), with no additional data structures that grow with input size. Thus, the code is memory-efficient but may be slow for larger inputs due to its quadratic time complexity.
*/