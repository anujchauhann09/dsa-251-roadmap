#include <bits/stdc++.h>  
using namespace std;

// Function to perform insertion sort on a vector
void insertionSort(int n, vector<int> &arr) {
    // Iterate through the array starting from the second element
    for(int i = 0; i < n; i++) {
        int key = arr[i]; // Current element to be placed in the sorted portion
        int j = i - 1;    // Index of the last sorted element

        // Shift elements of the sorted portion that are greater than `key` one position to the right
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Move larger element to the next position
            j--;                 // Move to the previous element in the sorted portion
        }

        // Place `key` in its correct position in the sorted portion
        arr[j + 1] = key;
    }
}

int main() {
    // Test case 1: Unsorted array
    vector<int> arr1 = {12, 11, 13, 5, 6};
    insertionSort(arr1.size(), arr1);
    cout << "Sorted array 1: ";
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2: Already sorted array
    vector<int> arr2 = {1, 2, 3, 4, 5};
    insertionSort(arr2.size(), arr2);
    cout << "Sorted array 2: ";
    for (int num : arr2) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 3: Array with duplicates
    vector<int> arr3 = {4, 2, 2, 8, 1};
    insertionSort(arr3.size(), arr3);
    cout << "Sorted array 3: ";
    for (int num : arr3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of insertion sort is O(n^2) in the worst and average cases due to nested loops for shifting elements, and O(n) in the best case when the array is already sorted.

Space Complexity:
The space complexity is O(1) because it sorts the array in-place without using extra memory.
*/