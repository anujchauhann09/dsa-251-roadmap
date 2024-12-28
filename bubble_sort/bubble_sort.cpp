#include <bits/stdc++.h>
using namespace std;

// Function to perform Bubble Sort on an array
void bubbleSort(vector<int>& arr, int n) {
    // Outer loop: Controls the number of passes through the array
    for (int i = 0; i < n - 1; i++) {
        // Inner loop: Iterates through the unsorted part of the array
        // Elements at the end of the array are already sorted after each pass
        for (int j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements and swap if they are in the wrong order
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    // Test case 1: Unsorted array
    vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    cout << "Test case 1: Unsorted array" << endl;
    bubbleSort(arr1, arr1.size());
    cout << "Sorted array: ";
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2: Already sorted array
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Test case 2: Already sorted array" << endl;
    bubbleSort(arr2, arr2.size());
    cout << "Sorted array: ";
    for (int num : arr2) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 3: Array with duplicate elements
    vector<int> arr3 = {5, 1, 4, 2, 8, 2, 1};
    cout << "Test case 3: Array with duplicates" << endl;
    bubbleSort(arr3, arr3.size());
    cout << "Sorted array: ";
    for (int num : arr3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of Bubble Sort is O(n^2) in the worst and average cases due to nested loops comparing and swapping elements, and O(n) in the best case when the array is already sorted.

Space Complexity:
The space complexity is O(1) as it sorts the array in-place without using extra memory.
*/