#include <bits/stdc++.h>
using namespace std;

// Function to separate negative and positive numbers using sorting
vector<int> separateNegativeAndPositive(vector<int> &nums) {
    // Sort the entire vector in ascending order
    sort(nums.begin(), nums.end());

    // Return the sorted vector where negative numbers are on the left
    return nums;
}

// Main function to test the separateNegativeAndPositive function
int main() {
    // Test case 1: Mixed negative and positive numbers
    vector<int> nums1 = {-1, 2, -3, 4, 5, -6};
    vector<int> result1 = separateNegativeAndPositive(nums1);
    cout << "Test case 1: ";
    for (int num : result1) cout << num << " ";
    cout << endl;
    // Expected output: -6 -3 -1 2 4 5

    // Test case 2: All negative numbers
    vector<int> nums2 = {-4, -5, -6};
    vector<int> result2 = separateNegativeAndPositive(nums2);
    cout << "Test case 2: ";
    for (int num : result2) cout << num << " ";
    cout << endl;
    // Expected output: -6 -5 -4

    // Test case 3: All positive numbers
    vector<int> nums3 = {3, 6, 9};
    vector<int> result3 = separateNegativeAndPositive(nums3);
    cout << "Test case 3: ";
    for (int num : result3) cout << num << " ";
    cout << endl;
    // Expected output: 3 6 9

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
The time complexity of this approach is O(n log n) because the sort function is used, which has a time complexity of O(n log n) for sorting a vector of size n. 

Space Complexity:
The space complexity is O(1) if an in-place sorting algorithm is used, as no additional data structures are required to store intermediate results. However, if the sorting algorithm requires auxiliary space (e.g., for recursion), the space complexity may increase to O(log n).
*/