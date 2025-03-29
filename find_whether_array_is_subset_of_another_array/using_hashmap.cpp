#include <bits/stdc++.h>
using namespace std;

bool checkSubset(vector<int> &arr1, vector<int> &arr2, int n, int m) {
    // If arr2 is larger than arr1, it cannot be a subset.
    if (m > n) {
        return false;
    }

    unordered_map<int, int> arr1Map; // Stores frequency of elements in arr1.

    // Count occurrences of each element in arr1.
    for (int i = 0; i < n; i++) {
        arr1Map[arr1[i]]++;
    }

    // Check if each element of arr2 exists in arr1Map with required frequency.
    for (int i = 0; i < m; i++) {
        // If element is not found in arr1, return false.
        if (arr1Map.find(arr2[i]) == arr1Map.end()) {
            return false;
        }

        // Decrease the frequency of the element in arr1.
        arr1Map[arr2[i]]--;

        // If frequency becomes negative, arr2 has more occurrences than arr1.
        if (arr1Map[arr2[i]] < 0) {
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
The function efficiently checks if arr2 is a subset of arr1 using an unordered map for frequency counting. First, it iterates through arr1 to build a frequency map in O(n) time. Then, it checks each element in arr2, looking up and modifying the frequency in O(1) time per operation, leading to a total time complexity of O(n + m). 

Space Complexity:
The space complexity is O(n) due to the hash map storing arr1's elements and their counts. 
*/