#include <bits/stdc++.h>
using namespace std;

// Function to find the single non-duplicate element in an array using a hash map.
int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); // Size of the array.
    unordered_map<int, int> mp; // Hash map to store the frequency of each element.

    // Iterate through the array and count the frequency of each element.
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++; // Increment the count for the current element.
    }

    // Iterate through the hash map to find the element with a frequency of 1.
    for (auto m : mp) {
        if (m.second == 1) {
            return m.first; // Return the element that appears only once.
        }
    }

    // If no such element is found, return -1 (though the problem guarantees one unique element).
    return -1;
}

int main() {
    // Test Case 1: Single element is in the middle.
    vector<int> arr1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Test Case 1: " << singleNonDuplicate(arr1) << endl; // Expected output: 2

    // Test Case 2: Single element is at the beginning.
    vector<int> arr2 = {3, 7, 7, 10, 10, 11, 11};
    cout << "Test Case 2: " << singleNonDuplicate(arr2) << endl; // Expected output: 3

    // Test Case 3: Single element is at the end.
    vector<int> arr3 = {1, 1, 2, 2, 3, 3, 4};
    cout << "Test Case 3: " << singleNonDuplicate(arr3) << endl; // Expected output: 4

    return 0;
}

/*
Time Complexity:
The first loop iterates through the array once to count frequencies, taking O(n) time.
The second loop iterates through the hash map, which in the worst case has O(n) unique elements (if all elements are unique).
Therefore, the overall time complexity is O(n).

Space Complexity:
The hash map stores the frequency of each element, which in the worst case requires O(n) space (if all elements are unique).
Therefore, the space complexity is O(n).
*/