#include <iostream>
#include <vector>
using namespace std;

// Helper function to find the single non-duplicate element in a sorted array using binary search (recursive approach).
int singleNonDuplicateHelper(vector<int>& arr, int start, int end) {
    // Base case: When the search space is reduced to a single element, return that element.
    if (start >= end) {
        return arr[start];
    }

    // Calculate the middle index to divide the array into two halves.
    int mid = start + (end - start) / 2;

    // Check if the middle element is part of a pair:
    // - If mid is odd, compare it with the previous element.
    // - If mid is even, compare it with the next element.
    if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
        // If the middle element is part of a pair, the single element must be in the right half.
        return singleNonDuplicateHelper(arr, mid + 1, end);
    } else {
        // Otherwise, the single element must be in the left half.
        return singleNonDuplicateHelper(arr, start, mid);
    }
}

// Main function to find the single non-duplicate element in a sorted array.
int singleNonDuplicate(vector<int>& arr) {
    // Call the helper function with the full range of the array.
    return singleNonDuplicateHelper(arr, 0, arr.size() - 1);
}

int main() {
    // Test Case 1: Single element is in the middle.
    vector<int> arr1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Test Case 1: " << singleNonDuplicate(arr1) << endl; // Expected output: 2

    // Test Case 2: Single element is at the beginning.
    vector<int> arr2 = {3, 7, 7, 10, 10, 11, 11};
    cout << "Test Case 2: " << singleNonDuplicate(arr2) << endl; // Expected output: 3

    // Test Case 3: Single element is at the end.
    vector<int> arr3 = {1, 1, 2, 2, 3, 3, 4};
    cout << "Test Case 3: " << singleNonDuplicate(arr3) << endl; // Expected output: 4

    return 0;
}

/*
Time Complexity:
The algorithm uses a binary search approach, which reduces the search space by half in each recursive call. Therefore, the time complexity is O(log n), where n is the size of the array.

Space Complexity:
The recursive implementation uses additional space on the call stack for each recursive call. In the worst case, the depth of recursion is O(log n), so the space complexity is O(log n).
*/