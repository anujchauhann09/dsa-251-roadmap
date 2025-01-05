#include <bits/stdc++.h>
using namespace std;

pair<int, int> missingAndRepeating(vector<int> &arr, int n) {
    int missing = -1, repeating = -1;

    // Traverse the array and mark visited elements
    for (int i = 0; i < n; i++) {
        int index = abs(arr[i]) - 1; // Map value to index (1-based to 0-based)
        if (arr[index] < 0) {
            // If already marked, it's the repeating number
            repeating = abs(arr[i]);
        } else {
            // Mark as visited
            arr[index] = -arr[index];
        }
    }

    // Find the missing number
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            // The index + 1 is the missing number
            missing = i + 1;
            break;
        }
    }

    return {missing, repeating};
}

int main() {
    // Test Case 1: Missing = 3, Repeating = 2
    vector<int> arr1 = {4, 3, 6, 2, 1, 1};
    pair<int, int> result1 = missingAndRepeating(arr1, 6);
    cout << "Missing: " << result1.first << ", Repeating: " << result1.second << endl;

    // Test Case 2: Missing = 4, Repeating = 5
    vector<int> arr2 = {5, 5, 3, 2, 1};
    pair<int, int> result2 = missingAndRepeating(arr2, 5);
    cout << "Missing: " << result2.first << ", Repeating: " << result2.second << endl;

    // Test Case 3: Missing = 2, Repeating = 4
    vector<int> arr3 = {4, 3, 4, 1};
    pair<int, int> result3 = missingAndRepeating(arr3, 4);
    cout << "Missing: " << result3.first << ", Repeating: " << result3.second << endl;

    return 0;
}

/*
Time Complexity: O(n)
The algorithm traverses the array twice—once to mark elements and once to find the missing number—resulting in linear time complexity.

Space Complexity: O(1)
The solution operates in constant space as it modifies the input array directly without using any extra data structures.
*/