#include <bits/stdc++.h> 
using namespace std;

// Function to perform selection sort on a vector
void selectionSort(vector<int>& arr, int n) {
    // Iterate through the array, treating each position from i to n-1 as a subarray
    for(int i = 0; i < n-1; i++) {
        // Inner loop finds the smallest element in the unsorted part of the array
        for(int j = i + 1; j < n; j++) {
            // Compare the current element arr[i] with arr[j]
            if(arr[i] > arr[j]) {
                // Swap arr[i] with arr[j] to move the smaller element to the correct position
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    // Test case 1: Unsorted array
    vector<int> arr1 = {64, 25, 12, 22, 11};
    selectionSort(arr1, arr1.size());
    cout << "Sorted array 1: ";
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2: Array already sorted
    vector<int> arr2 = {1, 2, 3, 4, 5};
    selectionSort(arr2, arr2.size());
    cout << "Sorted array 2: ";
    for (int num : arr2) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 3: Array with duplicates
    vector<int> arr3 = {5, 1, 4, 2, 2};
    selectionSort(arr3, arr3.size());
    cout << "Sorted array 3: ";
    for (int num : arr3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of the selection sort algorithm is O(n^2) because it involves two nested loops: the outer loop runs n−1 times, and for each iteration, the inner loop compares elements in the unsorted part of the array, leading to a total of n(n−1)comparisons. 

Space Complexity: 
The space complexity is O(1) because the sorting is performed in-place without requiring any additional storage except for a few variables.
*/