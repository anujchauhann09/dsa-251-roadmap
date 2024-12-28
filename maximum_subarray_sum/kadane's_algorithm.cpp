#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum subarray sum using Kadane's Algorithm
long long maxSubarraySum(vector<int> arr, int n) {
    long long currentSum = 0; // Tracks the sum of the current subarray
    long long maxSum = 0;     // Stores the maximum subarray sum found so far

    // Iterate through the array
    for (int i = 0; i < n; i++) {
        currentSum += arr[i]; // Add the current element to the running sum
        maxSum = max(maxSum, currentSum); // Update the maximum sum if currentSum is greater

        // Reset currentSum to 0 if it becomes negative
        if (currentSum < 0) {
            currentSum = 0;
        }
    }

    return maxSum; // Return the maximum subarray sum
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
O(n), as the algorithm makes a single pass through the array.

Space Complexity:
O(1), as it only uses variables to store sums and the maximum value.
*/