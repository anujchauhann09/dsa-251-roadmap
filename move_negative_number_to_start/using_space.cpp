#include <bits/stdc++.h>
using namespace std;

// Function to separate negative and positive numbers
vector<int> separateNegativeAndPositive(vector<int> &nums) {
    int n = nums.size(); // Size of the input vector
    vector<int> answer(n, 0); // New vector to store the result, initialized with zeros
    int left = 0, right = n - 1; // Pointers for the left and right ends

    // Loop through the input vector
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0) {
            // If the number is negative, place it at the left pointer and increment
            answer[left++] = nums[i];
            continue; // Skip the rest of the loop for this iteration
        }
        // If the number is positive, place it at the right pointer and decrement
        answer[right--] = nums[i];
    }

    // Return the result vector with separated negative and positive numbers
    return answer;
}

// Main function to test the separateNegativeAndPositive function
int main() {
    // Test case 1: Mixed negative and positive numbers
    vector<int> nums1 = {-1, 2, -3, 4, 5, -6};
    vector<int> result1 = separateNegativeAndPositive(nums1);
    cout << "Test case 1: ";
    for (int num : result1) cout << num << " ";
    cout << endl;
    // Expected output: -1 -3 -6 5 4 2 (negative on the left, positive on the right)

    // Test case 2: All negative numbers
    vector<int> nums2 = {-4, -5, -6};
    vector<int> result2 = separateNegativeAndPositive(nums2);
    cout << "Test case 2: ";
    for (int num : result2) cout << num << " ";
    cout << endl;
    // Expected output: -4 -5 -6 (all negatives on the left)

    // Test case 3: All positive numbers
    vector<int> nums3 = {3, 6, 9};
    vector<int> result3 = separateNegativeAndPositive(nums3);
    cout << "Test case 3: ";
    for (int num : result3) cout << num << " ";
    cout << endl;
    // Expected output: 9 6 3 (all positives on the right)

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
    // Expected output: -7

    // Test case 6: Single element (positive)
    vector<int> nums6 = {7};
    vector<int> result6 = separateNegativeAndPositive(nums6);
    cout << "Test case 6: ";
    for (int num : result6) cout << num << " ";
    cout << endl;
    // Expected output: 7

    return 0;
}

/*
Time Complexity:
The time complexity of this approach is O(n) because the algorithm iterates through the entire input vector once, processing each element in constant time. 

Space Complexity:
The space complexity is O(n) due to the additional answer vector created to store the separated negative and positive numbers, where n is the size of the input vector.
*/