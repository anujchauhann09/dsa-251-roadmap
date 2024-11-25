#include <bits/stdc++.h>  // Includes all standard libraries in one go
using namespace std;

int minElementsToRemove(vector<int> &arr) {
    int n = arr.size();         // Get the size of the input array
    int count = 0;              // Initialize the counter for elements to remove
    int leastValue = INT_MIN;   // Initialize a very small value to mark removed elements

    // Outer loop to iterate through the array
    for (int i = 0; i < n - 1; i++) {  // Traverse each element except the last
        for (int j = i + 1; j < n; j++) {  // Traverse elements after the current element
            if (arr[i] == arr[j]) {  // If a duplicate is found
                count++;             // Increment the count of elements to be removed
                arr[j] = leastValue++;  // Replace the duplicate with a unique small value
            }
        }
    }

    // Return the total number of duplicates (minimum elements to remove)
    return count;
}

int main() {
    // Test case 1
    vector<int> arr1 = {1, 2, 1, 2};
    cout << "Minimum elements to remove (Test 1): " << minElementsToRemove(arr1) << endl;

    // Test case 2
    vector<int> arr2 = {4, 5, 6, 7, 8};
    cout << "Minimum elements to remove (Test 2): " << minElementsToRemove(arr2) << endl;

    // Test case 3
    vector<int> arr3 = {1, 1, 1, 1};
    cout << "Minimum elements to remove (Test 3): " << minElementsToRemove(arr3) << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of this code is O(n²) because it uses nested loops where the outer loop runs for n-1 iterations and the inner loop runs for decreasing lengths (n-1, n-2, ..., 1). For every element in the array, it checks all subsequent elements to find duplicates, leading to a quadratic number of comparisons.

Space Complexity:
The space complexity is O(1) because no additional data structures are used, and all operations are performed in place using the input array and a few integer variables.
*/