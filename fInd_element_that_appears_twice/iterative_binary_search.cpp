#include <iostream>
#include <vector>
using namespace std;

// Function to find the single non-duplicate element in a sorted array using binary search (iterative approach).
int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); // Size of the array.
    int start = 0, end = n - 1, mid; // Initialize start and end pointers for binary search.

    // Perform binary search until the search space is reduced to a single element.
    while (start < end) {
        // Calculate the middle index to divide the array into two halves.
        mid = start + (end - start) / 2;

        // Check if the middle element is part of a pair:
        // - If mid is odd, compare it with the previous element.
        // - If mid is even, compare it with the next element.
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            // If the middle element is part of a pair, the single element must be in the right half.
            start = mid + 1;
        } else {
            // Otherwise, the single element must be in the left half.
            end = mid;
        }
    }

    // When the search space is reduced to a single element, return that element.
    return arr[start];
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
The algorithm uses a binary search approach, which reduces the search space by half in each iteration. Therefore, the time complexity is O(log n), where n is the size of the array.

Space Complexity:
The iterative implementation uses only a constant amount of extra space for variables like start, end, and mid. Therefore, the space complexity is O(1).
*/