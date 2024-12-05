#include <bits/stdc++.h>
using namespace std;

// Function to count pairs with a given sum
int pairSum(vector<int> &arr, int n, int target) {
    int count = 0; // Initialize counter for valid pairs

    // Iterate through all pairs of elements in the array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // Ensure j > i to avoid duplicate pairs
            // Check if the sum of the current pair equals the target
            if (arr[i] + arr[j] == target) {
                count++; // Increment counter
                break; // Break inner loop to avoid counting duplicates
            }
        }
    }

    // If no valid pairs are found, return -1
    if (count == 0) 
        return -1;

    // Return the total count of valid pairs
    return count;
}

// Main function to test the pairSum function
int main() {
    // Test case 1
    vector<int> arr1 = {1, 5, 7, -1, 5};
    int target1 = 6;
    cout << "Test case 1: " << pairSum(arr1, arr1.size(), target1) << endl;
    // Expected Output: 2 (pairs: (1, 5), (7, -1))

    // Test case 2
    vector<int> arr2 = {2, 2, 2, 2};
    int target2 = 4;
    cout << "Test case 2: " << pairSum(arr2, arr2.size(), target2) << endl;
    // Expected Output: 1 (pair: (2, 2))

    // Test case 3
    vector<int> arr3 = {1, 2, 3, 4, 5};
    int target3 = 10;
    cout << "Test case 3: " << pairSum(arr3, arr3.size(), target3) << endl;
    // Expected Output: -1 (no valid pairs)

    // Test case 4
    vector<int> arr4 = {0};
    int target4 = 0;
    cout << "Test case 4: " << pairSum(arr4, arr4.size(), target4) << endl;
    // Expected Output: -1 (no pairs possible)

    return 0;
}

/*
Time Complexity:
The time complexity of the brute force approach is O(n²) because it uses two nested loops to check all possible pairs in the array. For each element, the inner loop runs through the remaining elements, resulting in a quadratic number of comparisons.

Space Complexity:
The space complexity is O(1) as no additional data structures are used, and the space required is constant irrespective of the input size.
*/