#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum number of elements to remove
// such that all remaining elements are unique
int minElementsToRemove(vector<int> &arr) {
    int n = arr.size(); // Total number of elements in the array

    // Map to store the frequency of each element
    map<int, int> arrMap;

    // Traverse the array
    for (int i = 0; i < n; i++) {
        // If the element is not already in the map, add it with frequency 1
        if (!arrMap.count(arr[i])) {
            arrMap[arr[i]] = 1;
        } else {
            // If the element exists, increment its frequency
            arrMap[arr[i]]++;
        }
    }

    // Total elements to remove is the total count minus unique elements
    return n - arrMap.size();
}

int main() {
    // Test Case 1: Array with duplicates
    vector<int> arr1 = {1, 2, 2, 3, 1, 1};
    cout << "Test Case 1: " << minElementsToRemove(arr1) << endl; // Output should be 3

    // Test Case 2: Array with all unique elements
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Test Case 2: " << minElementsToRemove(arr2) << endl; // Output should be 0

    // Test Case 3: Array with all identical elements
    vector<int> arr3 = {5, 5, 5, 5};
    cout << "Test Case 3: " << minElementsToRemove(arr3) << endl; // Output should be 3

    return 0;
}

/*
Time Complexity:
The time complexity of this code is O(n) because the loop iterates through the array of size n, and each insertion or update operation in the map has an average time complexity of O(1). Therefore, the entire process of counting frequencies using a map takes linear time.

Space Complexity:
The space complexity is also O(n) because the map may store up to n key-value pairs in the worst case, where all elements in the array are distinct. This requires additional memory proportional to the number of unique elements in the input array.
*/