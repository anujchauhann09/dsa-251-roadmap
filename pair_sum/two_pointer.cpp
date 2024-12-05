#include <bits/stdc++.h> 
using namespace std;

/**
 * Function to count pairs in a sorted array whose sum equals a given target.
 * 
 * @param arr The input array (assumed to be sorted).
 * @param n The size of the array.
 * @param target The target sum we want to find pairs for.
 * @return The count of such pairs if found, or -1 if no pairs exist.
 */
int pairSum(vector<int> &arr, int n, int target) {
    int count = 0;    // Variable to keep track of the number of valid pairs.
    int left = 0;     // Left pointer starts at the beginning of the array.
    int right = n - 1; // Right pointer starts at the end of the array.

    // Loop until the two pointers cross.
    while (left < right) {
        // Case 1: If the sum of elements at the two pointers equals the target.
        if (arr[left] + arr[right] == target) {
            count++;   // Increment the count for a valid pair.
            left++;    // Move the left pointer to the right.
            right--;   // Move the right pointer to the left.
        }
        // Case 2: If the sum is greater than the target.
        else if (arr[left] + arr[right] > target) {
            right--;   // Decrease the sum by moving the right pointer left.
        }
        // Case 3: If the sum is less than the target.
        else {
            left++;    // Increase the sum by moving the left pointer right.
        }
    }

    // If no valid pairs were found, return -1.
    if (count == 0) 
        return -1;

    // Return the count of valid pairs.
    return count;
}

/**
 * Main function to test the pairSum function with various test cases.
 */
int main() {
    // Test case 1: Positive numbers with valid pairs.
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7};
    int target1 = 8;
    cout << "Test Case 1: " << pairSum(arr1, arr1.size(), target1) << endl; // Expected output: 3 (Pairs: [1,7], [2,6], [3,5])

    // Test case 2: Array with no valid pairs.
    vector<int> arr2 = {1, 2, 3, 4, 5};
    int target2 = 10;
    cout << "Test Case 2: " << pairSum(arr2, arr2.size(), target2) << endl; // Expected output: -1

    // Test case 3: Edge case with only two elements.
    vector<int> arr3 = {2, 7};
    int target3 = 9;
    cout << "Test Case 3: " << pairSum(arr3, arr3.size(), target3) << endl; // Expected output: 1 (Pair: [2,7])

    // Test case 4: Negative numbers and zero.
    vector<int> arr4 = {-10, -5, 0, 5, 10};
    int target4 = 0;
    cout << "Test Case 4: " << pairSum(arr4, arr4.size(), target4) << endl; // Expected output: 2 (Pairs: [-10,10], [-5,5])

    // Test case 5: Large array with multiple pairs.
    vector<int> arr5 = {1, 1, 2, 3, 4, 4, 5, 6, 6, 7, 8};
    int target5 = 10;
    cout << "Test Case 5: " << pairSum(arr5, arr5.size(), target5) << endl; // Expected output: 4 (Pairs: [2,8], [3,7], [4,6], [4,6])

    return 0;
}

/*
Time Complexity:
The time complexity of the two-pointer approach is O(n) because the array is traversed only once. The left and right pointers move towards each other, and in each step, at least one of the pointers moves. This ensures a single traversal of the array.

Space Complexity:
The space complexity is O(1) as the two-pointer technique does not require any additional data structures. It only uses a constant amount of extra space for the two pointers and a few variables.
*/