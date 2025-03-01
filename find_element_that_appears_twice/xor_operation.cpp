#include <iostream>
#include <vector>
using namespace std;

// Function to find the single non-duplicate element in a sorted or unsorted array using XOR.
int singleNonDuplicate(vector<int>& arr) {
    int answer = 0; // Initialize the answer to 0.

    // Iterate through all elements in the array.
    for (int i = 0; i < arr.size(); i++) {
        // XOR the current element with the answer.
        // XOR of a number with itself is 0, and XOR of a number with 0 is the number itself.
        // This cancels out all duplicate pairs, leaving only the single non-duplicate element.
        answer = answer ^ arr[i];
    }

    // Return the single non-duplicate element.
    return answer;
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
The algorithm iterates through the array once, performing a constant-time XOR operation for each element. Therefore, the time complexity is O(n), where n is the size of the array.

Space Complexity:
The algorithm uses only a single variable (answer) to store the result, so the space complexity is O(1).
*/