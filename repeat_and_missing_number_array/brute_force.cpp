#include <bits/stdc++.h>
using namespace std;

// Function to find the missing and repeating numbers in an array
pair<int, int> missingAndRepeating(vector<int> &arr, int n) {
    pair<int, int> answer; // Pair to store the missing and repeating numbers

    // Loop through numbers from 1 to n to check their frequency in the array
    for (int i = 1; i <= n; i++) {
        int countFreq = 0; // To track frequency of the current number
        int eleIndex = 0;  // To store the last index where the current number is found

        // Check occurrences of the number `i` in the array
        for (int j = 0; j < n; j++) {
            if (i == arr[j]) {
                countFreq++;
                eleIndex = j; // Update the index when the number is found
            }
        }

        // Determine the missing and repeating numbers
        if (countFreq == 0) {
            // If the number is not found, it is the missing number
            answer.first = i;
        } else if (countFreq > 1) {
            // If the number appears more than once, it is the repeating number
            answer.second = arr[eleIndex];
        }
    }

    return answer;
}

int main() {
    // Test Case 1: Missing = 3, Repeating = 2
    vector<int> arr1 = {4, 3, 6, 2, 1, 1};
    pair<int, int> result1 = missingAndRepeating(arr1, 6);
    cout << "Test Case 1 - Missing: " << result1.first << ", Repeating: " << result1.second << endl;

    // Test Case 2: Missing = 4, Repeating = 5
    vector<int> arr2 = {5, 5, 3, 2, 1};
    pair<int, int> result2 = missingAndRepeating(arr2, 5);
    cout << "Test Case 2 - Missing: " << result2.first << ", Repeating: " << result2.second << endl;

    // Test Case 3: Missing = 2, Repeating = 4
    vector<int> arr3 = {4, 3, 4, 1};
    pair<int, int> result3 = missingAndRepeating(arr3, 4);
    cout << "Test Case 3 - Missing: " << result3.first << ", Repeating: " << result3.second << endl;

    return 0;
}

/*
Time Complexity: O(n^2)
- Outer loop iterates over numbers from 1 to n → O(n).
- Inner loop checks the frequency of each number in the array → O(n).
- Overall TC = O(n) * O(n) = O(n^2).

Space Complexity: O(1)
- No additional space is used apart from a few variables for tracking indices and counts.
- Thus, SC = O(1).
*/
