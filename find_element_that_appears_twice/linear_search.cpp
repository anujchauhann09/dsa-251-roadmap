#include <iostream>
#include <vector>
using namespace std;

// Function to find the single non-duplicate element in a sorted array using a linear search with pairs.
int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); // Size of the array.

    // Iterate through the array in steps of 2 (since duplicates appear in pairs).
    for (int i = 0; i < n - 1; i += 2) {
        // Check if the current element and the next element are not equal.
        if (arr[i] != arr[i + 1]) {
            // If they are not equal, the current element is the single non-duplicate.
            return arr[i];
        }
    }

    // If no mismatch is found in the loop, the last element is the single non-duplicate.
    return arr[n - 1];
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
The algorithm iterates through the array in steps of 2, so it performs n/2 comparisons in the worst case. Therefore, the time complexity is O(n), where n is the size of the array.

Space Complexity:
The algorithm uses only a constant amount of extra space for variables like i and n. Therefore, the space complexity is O(1).
*/