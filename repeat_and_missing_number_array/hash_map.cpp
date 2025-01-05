#include <bits/stdc++.h>
using namespace std;

// Function to find the missing and repeating numbers in an array
pair<int, int> missingAndRepeating(vector<int> &arr, int n) {
    unordered_map<int, int> mp; // Hash map to store the frequency of each number
    pair<int, int> answer;     // To store the missing and repeating numbers

    // Initialize the hash map with keys from 1 to n and values set to 0
    for (int i = 1; i <= n; i++) {
        mp[i] = 0;
    }

    // Count the frequency of each number in the array
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    // Identify the missing and repeating numbers
    for (auto pair : mp) {
        if (pair.second == 0) {
            // Missing number is the one with zero frequency
            answer.first = pair.first;
        }
        if (pair.second > 1) {
            // Repeating number is the one with frequency > 1
            answer.second = pair.first;
        }
    }

    return answer;
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
- Initializing the hash map takes O(n).
- Counting frequencies in the array takes O(n).
- Traversing the hash map to find missing and repeating numbers takes O(n).
- Overall TC = O(n).

Space Complexity: O(n)
- The hash map requires O(n) extra space to store the frequency of numbers from 1 to n.
*/
