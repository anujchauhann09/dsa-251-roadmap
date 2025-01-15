#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the k-th element in the merged sorted array formed by combining two sorted arrays.
 * 
 * @param arr1 First sorted array.
 * @param arr2 Second sorted array.
 * @param k Position of the desired element in the merged array (1-based index).
 * @return The k-th element in the merged sorted array, or -1 if k is out of bounds.
 */
int findKthElement(vector<int> &arr1, vector<int> &arr2, int k) {
    int m = arr1.size(); // Size of the first array
    int n = arr2.size(); // Size of the second array

    int i = 0, j = 0;    // Pointers for arr1 and arr2
    int count = 0;       // Counter to track the number of merged elements

    // Merge the two arrays until the k-th element is found
    while (i < m && j < n) {
        if (arr1[i] <= arr2[j]) {
            count++; // Increment the count of merged elements
            if (count == k) return arr1[i]; // Return the k-th element if found
            i++; // Move the pointer in arr1
        } else {
            count++; // Increment the count of merged elements
            if (count == k) return arr2[j]; // Return the k-th element if found
            j++; // Move the pointer in arr2
        }
    }

    // If there are remaining elements in arr1
    while (i < m) {
        count++; // Increment the count of merged elements
        if (count == k) return arr1[i]; // Return the k-th element if found
        i++; // Move the pointer in arr1
    }

    // If there are remaining elements in arr2
    while (j < n) {
        count++; // Increment the count of merged elements
        if (count == k) return arr2[j]; // Return the k-th element if found
        j++; // Move the pointer in arr2
    }

    // If k is larger than the total number of elements in the merged array
    return -1;
}

int main() {
    // Test case 1
    vector<int> arr1_1 = {1, 3, 5, 7};
    vector<int> arr2_1 = {2, 4, 6, 8};
    int k1 = 5; // The 5th element in the merged array should be 5
    cout << "Test Case 1: " << findKthElement(arr1_1, arr2_1, k1) << endl;

    // Test case 2
    vector<int> arr1_2 = {1, 2, 3};
    vector<int> arr2_2 = {4, 5, 6};
    int k2 = 4; // The 4th element in the merged array should be 4
    cout << "Test Case 2: " << findKthElement(arr1_2, arr2_2, k2) << endl;

    // Test case 3
    vector<int> arr1_3 = {10, 20, 30};
    vector<int> arr2_3 = {5, 15, 25};
    int k3 = 6; // The 6th element in the merged array should be 30
    cout << "Test Case 3: " << findKthElement(arr1_3, arr2_3, k3) << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of the function depends on the value of k, which is the position of the desired element in the merged array. Since the function iteratively compares elements from the two input arrays (arr1 and arr2) and stops as soon as the k-th element is found, the number of iterations is directly proportional to k. In the worst case, the function traverses up to the first k elements of the combined arrays, making the time complexity O(k).

Space Complexity:
Regarding space complexity, the function does not utilize any additional data structures to store intermediate results. Instead, it uses a few integer variables, such as i, j, and count, to manage the traversal and counting. Since these variables occupy constant space irrespective of the input size, the space complexity of the function is O(1). Thus, the function is both time-efficient for small values of k and space-efficient, as it operates in-place without requiring extra memory.
*/