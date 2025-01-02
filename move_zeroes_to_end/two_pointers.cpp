#include <iostream>
#include <vector>
using namespace std;

void pushZerosAtEnd(vector<int>& nums) {
    int n = nums.size();
    int zeroPointer = 0; // Points to the first zero encountered

    // Traverse the array with the non-zero pointer
    for (int nonZeroPointer = 0; nonZeroPointer < n; nonZeroPointer++) {
        // If a non-zero element is found, swap it with the zeroPointer
        if (nums[nonZeroPointer] != 0) {
            swap(nums[zeroPointer], nums[nonZeroPointer]);
            zeroPointer++; // Move the zeroPointer ahead
        }
    }
}

int main() {
    // Example test cases
    vector<int> nums1 = {0, 1, 0, 3, 12};
    vector<int> nums2 = {0, 0, 0, 0};
    vector<int> nums3 = {1, 2, 3, 4};

    cout << "Before moving zeroes:\n";
    for (auto num : nums1) cout << num << " ";
    cout << endl;

    pushZerosAtEnd(nums1);

    cout << "After moving zeroes:\n";
    for (auto num : nums1) cout << num << " ";
    cout << endl;

    // Additional test cases
    cout << "\nTest case 2: ";
    for (auto num : nums2) cout << num << " ";
    cout << endl;
    pushZerosAtEnd(nums2);
    cout << "After: ";
    for (auto num : nums2) cout << num << " ";
    cout << endl;

    cout << "\nTest case 3: ";
    for (auto num : nums3) cout << num << " ";
    cout << endl;
    pushZerosAtEnd(nums3);
    cout << "After: ";
    for (auto num : nums3) cout << num << " ";
    cout << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of the given algorithm is O(n), where n is the size of the input array. This is because we iterate through the array once using the nonZeroPointer, and the operations performed during each iteration (like swapping elements) are constant time O(1). Therefore, the overall time complexity is linear.

Space Complexity:
The space complexity of the algorithm is O(1), as no additional data structures are used to store information. The swaps and modifications are performed directly on the input array, making it an in-place algorithm that does not require extra space proportional to the input size.
*/