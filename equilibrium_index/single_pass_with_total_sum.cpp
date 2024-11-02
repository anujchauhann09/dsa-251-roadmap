#include <bits/stdc++.h>
using namespace std;

// Function to find the equilibrium index in the array
// An equilibrium index is where the sum of elements to the left
// equals the sum of elements to the right.
int findEquilibriumIndex(vector<int> &arr) {
    int n = arr.size(); // Get the size of the array
    int totalSum = 0;   // Variable to store the total sum of array elements
    int leftSum = 0;    // Variable to store the left sum for each index

    // Calculate the total sum of all elements in the array
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    // Iterate through the array to find the equilibrium index
    for (int i = 0; i < n; i++) {
        // Right sum is calculated by subtracting the leftSum and current element (arr[i]) from totalSum
        // This is because rightSum + leftSum + arr[i] = totalSum, so rightSum = totalSum - leftSum - arr[i]
        int rightSum = totalSum - leftSum - arr[i];

        // Check if the left sum equals the right sum
        if (leftSum == rightSum) {
            return i; // Return the current index as the equilibrium index
        }

        // Update the left sum by adding the current element to it for the next iteration
        leftSum += arr[i];
    }

    // If no equilibrium index is found, return -1
    return -1;
}

// Main function to test the findEquilibriumIndex function with different test cases
int main() {
    vector<int> test1 = {1, 3, 5, 2, 2}; // Expected equilibrium index: 2
    vector<int> test2 = {1, 2, 3};       // Expected equilibrium index: -1 (no equilibrium)
    vector<int> test3 = {2, 3, -1, 8, 4, 3, 2}; // Expected equilibrium index: 3
    vector<int> test4 = {0, 0, 0, 0};    // Expected equilibrium index: 0 (first index)
    vector<int> test5 = {10, -5, 5};     // Expected equilibrium index: 0 (first index)

    cout << "Equilibrium index in test1: " << findEquilibriumIndex(test1) << endl;
    cout << "Equilibrium index in test2: " << findEquilibriumIndex(test2) << endl;
    cout << "Equilibrium index in test3: " << findEquilibriumIndex(test3) << endl;
    cout << "Equilibrium index in test4: " << findEquilibriumIndex(test4) << endl;
    cout << "Equilibrium index in test5: " << findEquilibriumIndex(test5) << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of this code is O(n) because we iterate through the array twice: once to calculate the totalSum and once to find the equilibrium index. Each of these loops is independent, so they contribute to a linear time complexity, making this approach efficient for large arrays.

Space Complexity:
The space complexity is O(1) because we use only a constant amount of extra space for variables like totalSum, leftSum, and rightSum. This means the algorithm does not require additional memory that grows with the size of the input array, allowing it to work within a fixed amount of space regardless of array size.
*/