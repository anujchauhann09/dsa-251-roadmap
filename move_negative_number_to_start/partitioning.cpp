#include <bits/stdc++.h>
using namespace std;

// Function to separate negative and positive numbers
vector<int> separateNegativeAndPositive(vector<int> &nums) {
    int n = nums.size();  // Get the size of the vector

    // Use two pointers: i for iteration, j for position of next negative number
    for (int i = 0, j = 0; i < n; i++) {
        // Check if the current element is negative
        if (nums[i] < 0) {
            // Swap the current element with the element at position j
            swap(nums[i], nums[j++]); // Increment j after swapping
        }
    }

    return nums; // Return the modified vector
}

// Main function to test the separateNegativeAndPositive function
int main() {
    // Test case 1: Mixed negative and positive numbers
    vector<int> nums1 = {-1, 2, -3, 4, 5, -6};
    vector<int> result1 = separateNegativeAndPositive(nums1);
    cout << "Test case 1: ";
    for (int num : result1) cout << num << " ";
    cout << endl;
    // Expected output: -1 -3 -6 4 5 2 (order may vary)

    // Test case 2: All negative numbers
    vector<int> nums2 = {-4, -5, -6};
    vector<int> result2 = separateNegativeAndPositive(nums2);
    cout << "Test case 2: ";
    for (int num : result2) cout << num << " ";
    cout << endl;
    // Expected output: -4 -5 -6 (unchanged)

    // Test case 3: All positive numbers
    vector<int> nums3 = {3, 6, 9};
    vector<int> result3 = separateNegativeAndPositive(nums3);
    cout << "Test case 3: ";
    for (int num : result3) cout << num << " ";
    cout << endl;
    // Expected output: 3 6 9 (unchanged)

    // Test case 4: Empty vector
    vector<int> nums4 = {};
    vector<int> result4 = separateNegativeAndPositive(nums4);
    cout << "Test case 4: ";
    for (int num : result4) cout << num << " ";
    cout << endl;
    // Expected output: (empty output)

    // Test case 5: Single element (negative)
    vector<int> nums5 = {-7};
    vector<int> result5 = separateNegativeAndPositive(nums5);
    cout << "Test case 5: ";
    for (int num : result5) cout << num << " ";
    cout << endl;
    // Expected output: -7 (unchanged)

    // Test case 6: Single element (positive)
    vector<int> nums6 = {7};
    vector<int> result6 = separateNegativeAndPositive(nums6);
    cout << "Test case 6: ";
    for (int num : result6) cout << num << " ";
    cout << endl;
    // Expected output: 7 (unchanged)

    return 0;
}

/*
Time Complexity:
The time complexity of this approach is O(n) because the function iterates through the vector once using a single loop. Each element is processed at most once, and the swap operation takes constant time, O(1). 

Space Complexity:
The space complexity is O(1) as the rearrangement is done in-place without using any additional data structures.
*/