#include <bits/stdc++.h>
using namespace std;

// Function to find the equilibrium index of an array
int findEquilibriumIndex(vector<int> &arr) {
    int n = arr.size(); // Get the size of the array
    vector<int> prefixSumArr(n, 0); // Initialize prefix sum array
    vector<int> suffixSumArr(n, 0); // Initialize suffix sum array
    int prefixSum = 0; // Variable to keep track of the prefix sum
    int suffixSum = 0; // Variable to keep track of the suffix sum

    // Compute prefix sums
    for(int i = 0; i < n; i++) {
        prefixSum += arr[i]; // Accumulate sum from the start of the array
        prefixSumArr[i] = prefixSum; // Store the current prefix sum in the array
    }

    // Compute suffix sums
    for(int i = n - 1; i >= 0; i--) {
        suffixSum += arr[i]; // Accumulate sum from the end of the array
        suffixSumArr[i] = suffixSum; // Store the current suffix sum in the array
    }

    // Check for the equilibrium index
    for(int i = 0; i < n; i++) {
        if(prefixSumArr[i] == suffixSumArr[i]) { // Compare prefix and suffix sums
            return i; // Return the equilibrium index if found
        }
    }

    return -1; // Return -1 if no equilibrium index exists
}

// Main function to test the findEquilibriumIndex function
int main() {
    // Test cases
    vector<int> arr1 = {1, 7, 3, 6, 5, 6}; // Expected equilibrium index: 3
    vector<int> arr2 = {1, 2, 3}; // Expected equilibrium index: -1 (no equilibrium)
    vector<int> arr3 = {0, 0, 0, 0}; // Expected equilibrium index: 0 (multiple valid indices)
    vector<int> arr4 = {2, 3, -1, 8, 4}; // Expected equilibrium index: 3

    // Running tests
    cout << "Equilibrium index for arr1: " << findEquilibriumIndex(arr1) << endl;
    cout << "Equilibrium index for arr2: " << findEquilibriumIndex(arr2) << endl;
    cout << "Equilibrium index for arr3: " << findEquilibriumIndex(arr3) << endl;
    cout << "Equilibrium index for arr4: " << findEquilibriumIndex(arr4) << endl;

    return 0; // Indicate successful execution
}

/*
Time Complexity:
The time complexity of the provided code is O(n), where n is the number of elements in the input array. This is because the algorithm involves three separate loops that each iterate through the array a maximum of two times: the first loop calculates the prefix sums, the second loop computes the suffix sums, and the final loop checks for the equilibrium index. Each loop runs in linear time, resulting in an overall time complexity of O(n).

Space Complexity:
The space complexity is also O(n) due to the additional storage required for the two vectors, prefixSumArr and suffixSumArr, which both hold n elements. This means that the space used by these vectors grows linearly with the size of the input array. In conclusion, the solution is efficient in terms of time but uses extra space proportional to the size of the input array to maintain the prefix and suffix sums, making it a trade-off between time efficiency and space usage.
*/