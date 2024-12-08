#include <bits/stdc++.h>
using namespace std;

// Function to separate negative and positive numbers
vector<int> separateNegativeAndPositive(vector<int> &nums) {
    int n = nums.size();       // Size of the vector
    int left = 0, right = n - 1; // Initialize two pointers

    // Loop until the two pointers meet
    while (left < right) {
        // Case 1: Both left and right elements are negative
        if (nums[left] < 0 && nums[right] < 0) {
            left++; // Move the left pointer forward
        }
        // Case 2: Both left and right elements are positive
        else if (nums[left] >= 0 && nums[right] >= 0) {
            right--; // Move the right pointer backward
        }
        // Case 3: Left is positive, right is negative
        else if (nums[left] >= 0 && nums[right] <= 0) {
            swap(nums[left++], nums[right--]); // Swap and move both pointers inward
        }
        // Case 4: Left is negative, right is positive
        else if (nums[left] <= 0 && nums[right] >= 0) {
            left++;  // Move the left pointer forward
            right--; // Move the right pointer backward
        }
    }

    return nums; // Return the rearranged vector
}

// Main function to test the separateNegativeAndPositive function
int main() {
    // Test case 1: Mixed positive and negative numbers
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

    // Test case 5: Single element
    vector<int> nums5 = {-7};
    vector<int> result5 = separateNegativeAndPositive(nums5);
    cout << "Test case 5: ";
    for (int num : result5) cout << num << " ";
    cout << endl;
    // Expected output: -7 (unchanged)

    return 0;
}

/*
Time Complexity:
The time complexity of the two-pointer approach is O(n) because each element in the array is processed at most once as the two pointers move from the ends towards the center. 

Space Complexity:
The space complexity is O(1) as no additional data structures are used, and the operations are performed in-place using only a constant amount of extra space.
*/