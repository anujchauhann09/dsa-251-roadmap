#include <bits/stdc++.h>
using namespace std;

pair<int, int> missingAndRepeating(vector<int> &arr, int n) {
    pair<int, int> answer;

    // Sort the array
    sort(arr.begin(), arr.end());

    // Find the repeating number and the missing number
    int missing = 1; // Start checking from 1
    for (int i = 1; i < n; i++) {
        // If two consecutive elements are the same, it's the repeating number
        if (arr[i] == arr[i - 1]) {
            answer.second = arr[i];
        }
        // Check for the missing number in the sorted order
        else if (arr[i] > arr[i - 1] + 1) {
            answer.first = arr[i - 1] + 1;
        }
    }

    // Handle the edge case for missing number being `n`
    if (arr[n - 1] != n) {
        answer.first = n;
    }
    // Handle the edge case for missing number being `1`
    else if (arr[0] != 1) {
        answer.first = 1;
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
Time Complexity: O(nlogn)
Sorting the array dominates the time complexity, taking O(nlogn). Post-sorting, a single traversal to find the missing and repeating numbers takes O(n), but this is overshadowed by the sorting step.

Space Complexity:
-In-place Sorting:- 
O(1) (if the sorting algorithm modifies the input array directly, e.g., quicksort or heapsort).
-Using Extra Space:- 
O(n) (if a sorting algorithm like mergesort requiring auxiliary space is used).
*/