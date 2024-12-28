#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum sum of a subarray
// This uses a brute-force approach with nested loops
long long maxSubarraySum(vector<int> arr, int n) {
    int maxi = INT_MIN; // Initialize the maximum sum as the smallest possible integer

    // Outer loop to fix the starting point of the subarray
    for (int i = 0; i < n; i++) {
        int sum = 0; // Initialize the sum for the current subarray

        // Inner loop to explore all subarrays starting from index i
        for (int j = i; j < n; j++) {
            sum += arr[j]; // Add the current element to the sum
            maxi = max(sum, maxi); // Update the maximum sum if the current sum is greater
        }
    }

    maxi = max(maxi, 0); // Ensure that the maximum sum is at least 0 (for empty subarrays)

    return maxi; // Return the maximum subarray sum
}

int main() {
    // Test case 1: Array with mixed positive and negative numbers
    vector<int> arr1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Test case 1: Maximum subarray sum = " << maxSubarraySum(arr1, arr1.size()) << endl;

    // Test case 2: Array with all negative numbers
    vector<int> arr2 = {-1, -2, -3, -4};
    cout << "Test case 2: Maximum subarray sum = " << maxSubarraySum(arr2, arr2.size()) << endl;

    // Test case 3: Array with all positive numbers
    vector<int> arr3 = {1, 2, 3, 4, 5};
    cout << "Test case 3: Maximum subarray sum = " << maxSubarraySum(arr3, arr3.size()) << endl;

    return 0;
}

/*
Time Complexity: 
O(n^2), as the nested loops explore all possible subarrays.

Space Complexity:
O(1), as no extra memory is used apart from variables for storing sums.
*/