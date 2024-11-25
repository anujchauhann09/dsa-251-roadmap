#include <bits/stdc++.h>  // Include all standard library headers
using namespace std;

// Function to find the minimum number of elements to remove
int minElementsToRemove(vector<int> &arr) {
    // Get the size of the input array
    int n = arr.size();

    // Declare a set to store unique elements
    set<int> arrSet;

    // Iterate over the array and insert each element into the set
    for (int i = 0; i < n; i++) {
        arrSet.insert(arr[i]);  // Duplicates are automatically handled by the set
    }

    // The size of the set represents the count of unique elements.
    // Subtract the size of the set from the total number of elements in the array
    // to get the count of duplicate elements (i.e., elements to remove).
    return n - arrSet.size();
}

int main() {
    // Test case 1
    vector<int> arr1 = {1, 2, 1, 3, 2};
    cout << "Test Case 1: " << minElementsToRemove(arr1) << endl; // Output: 2

    // Test case 2
    vector<int> arr2 = {4, 5, 6, 7};
    cout << "Test Case 2: " << minElementsToRemove(arr2) << endl; // Output: 0

    // Test case 3
    vector<int> arr3 = {8, 8, 8, 8};
    cout << "Test Case 3: " << minElementsToRemove(arr3) << endl; // Output: 3

    // Test case 4
    vector<int> arr4 = {};
    cout << "Test Case 4: " << minElementsToRemove(arr4) << endl; // Output: 0

    return 0;
}

/*
Time Complexity:
The time complexity of this code is O(n log n) because inserting each element into the set takes O(log n) time, and for n elements, it becomes O(n log n). 

Space Complexity:
The space complexity is O(u), where u is the number of unique elements in the input array. This is because the set data structure stores only unique elements, requiring space proportional to the number of distinct values in the array.
*/