#include <bits/stdc++.h>
using namespace std;
#define DUMMY_VAL INT_MIN // A dummy value to mark used elements in arr1

bool checkSubset(vector<int> &arr1, vector<int> &arr2, int n, int m) {
    // If arr2 has more elements than arr1, it cannot be a subset.
    if (m > n) {
        return false;
    }

    // Iterate over each element in arr2 and try to find it in arr1
    for (int i = 0; i < m; i++) {
        bool isPresent = false;

        for (int j = 0; j < n; j++) {
            // If element is found, mark it as used and break
            if (arr2[i] == arr1[j]) {
                isPresent = true;
                arr1[j] = DUMMY_VAL; // Mark as used to prevent duplicate counting
                break;
            }
        }

        // If an element of arr2 is missing in arr1, return false
        if (!isPresent) {
            return false;
        }
    }

    return true;
}

int main() {
    // Test Case 1: True (arr2 is a subset of arr1)
    vector<int> arr1_1 = {1, 2, 3, 1};
    vector<int> arr2_1 = {1, 1};
    cout << (checkSubset(arr1_1, arr2_1, arr1_1.size(), arr2_1.size()) ? "True" : "False") << endl;

    // Test Case 2: False (arr2 contains 4, which is not in arr1)
    vector<int> arr1_2 = {1, 2, 3, 1};
    vector<int> arr2_2 = {1, 4};
    cout << (checkSubset(arr1_2, arr2_2, arr1_2.size(), arr2_2.size()) ? "True" : "False") << endl;

    // Test Case 3: False (arr2 contains more occurrences of 1 than arr1 has)
    vector<int> arr1_3 = {1, 2, 3, 1};
    vector<int> arr2_3 = {1, 1, 1};
    cout << (checkSubset(arr1_3, arr2_3, arr1_3.size(), arr2_3.size()) ? "True" : "False") << endl;

    return 0;
}

/*
Time Complexity:
This approach uses a brute-force method to check if arr2 is a subset of arr1. The outer loop iterates over arr2 (size m), and for each element, the inner loop searches for it in arr1 (size n). If found, the matched element in arr1 is marked with a dummy value to prevent it from being reused. This results in a worst-case time complexity of O(m * n), which occurs when every element of arr2 is checked against every element of arr1.

Space Complexity:
The algorithm operates in-place, modifying arr1 directly, and does not use any extra data structures. Thus, the space complexity is O(1).
*/