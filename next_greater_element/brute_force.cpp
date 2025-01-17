#include <bits/stdc++.h>
using namespace std;

// Function to find the next greater element for each element in the array
vector<int> nextGreater(vector<int> &arr, int n) {
    // Vector to store the results
    vector<int> answer;

    // Outer loop iterates over each element in the array
    for (int i = 0; i < n; i++) {
        // Variable to check if a next greater element is found
        bool isNgePresent = false;

        // Inner loop finds the next greater element for arr[i]
        for (int j = i + 1; j < n; j++) {
            // If a greater element is found, break and mark its presence
            if (arr[j] > arr[i]) {
                isNgePresent = true;
                // Add the next greater element to the result vector
                answer.push_back(arr[j]);
                break;
            }
        }

        // If no greater element is found, append -1 to the result
        if (!isNgePresent) {
            answer.push_back(-1);
        }
    }

    return answer;
}

// Main function to test the nextGreater function
int main() {
    // Test Case 1
    vector<int> arr1 = {4, 5, 2, 10, 8};
    vector<int> result1 = nextGreater(arr1, arr1.size());
    cout << "Next greater elements for Test Case 1: ";
    for (int x : result1) cout << x << " ";
    cout << endl;

    // Test Case 2
    vector<int> arr2 = {3, 7, 1, 0, 6};
    vector<int> result2 = nextGreater(arr2, arr2.size());
    cout << "Next greater elements for Test Case 2: ";
    for (int x : result2) cout << x << " ";
    cout << endl;

    // Test Case 3
    vector<int> arr3 = {10, 9, 8, 7, 6};
    vector<int> result3 = nextGreater(arr3, arr3.size());
    cout << "Next greater elements for Test Case 3: ";
    for (int x : result3) cout << x << " ";
    cout << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of this approach is O(n²) because, for each element in the array (outer loop), we traverse the remaining elements (inner loop) to find the next greater element, leading to quadratic iterations in the worst case.

Space Complexity:
The space complexity is O(n) as we use an additional vector to store the results, which requires linear space proportional to the size of the input array. This brute-force approach is straightforward and easy to implement but is inefficient for larger input sizes due to its nested loop structure.
*/