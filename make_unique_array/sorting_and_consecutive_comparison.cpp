#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of elements to remove 
// from the array to make all elements unique.
int minElementsToRemove(vector<int> &arr) {
    int n = arr.size(); // Get the size of the array.
    int count = 0;      // Variable to store the count of elements to remove.

    // Sort the array in ascending order to group duplicate elements together.
    sort(arr.begin(), arr.end());

    // Traverse the array to check for duplicate elements.
    for (int i = 0; i < n - 1; i++) {
        // If the current element is equal to the next element,
        // increment the count as this element needs to be removed.
        if (arr[i] == arr[i + 1]) {
            count++;
        }
    }

    // Return the total count of elements that need to be removed.
    return count;
}

int main() {
    // Test case 1: Simple case with duplicates
    vector<int> arr1 = {1, 2, 2, 3, 4, 4};
    cout << "Minimum elements to remove: " << minElementsToRemove(arr1) << endl;
    // Output: 2 (remove one '2' and one '4')

    // Test case 2: No duplicates
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Minimum elements to remove: " << minElementsToRemove(arr2) << endl;
    // Output: 0 (no elements need to be removed)

    // Test case 3: All elements are duplicates
    vector<int> arr3 = {5, 5, 5, 5, 5};
    cout << "Minimum elements to remove: " << minElementsToRemove(arr3) << endl;
    // Output: 4 (remove four '5's)

    // Test case 4: Large array with mixed values
    vector<int> arr4 = {3, 1, 2, 2, 3, 1, 4, 4, 5, 5};
    cout << "Minimum elements to remove: " << minElementsToRemove(arr4) << endl;
    // Output: 5 (remove one '1', one '2', one '3', one '4', and one '5')

    return 0;
}

/*
Time Complexity: Sorting the array takes O(nlogn), where n is the size of the array. Traversing the array once to count duplicates takes O(n). Thus, the overall complexity is O(nlogn).

Space Complexity: The sorting operation may use O(n) space depending on the sorting algorithm, but in-place sorting (like quicksort) requires O(1) extra space. Hence, the space complexity is O(1) excluding the input.
*/