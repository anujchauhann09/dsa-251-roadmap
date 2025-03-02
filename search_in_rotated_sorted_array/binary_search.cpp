#include <stdio.h>

// Function to perform binary search in a sorted array
int searchKey(int *arr, int start, int end, int key) {
    // Base case: If the search range is invalid, the key is not found
    if (start > end) {
        return -1;
    }

    // Calculate the middle index to divide the array into two halves
    int mid = start + (end - start) / 2;

    // If the middle element is the key, return its index
    if (*(arr + mid) == key) {
        return mid;
    }
    // If the middle element is greater than the key, search the left half
    else if (*(arr + mid) > key) {
        return searchKey(arr, start, mid - 1, key);
    }
    // If the middle element is smaller than the key, search the right half
    else {
        return searchKey(arr, mid + 1, end, key);
    }
}

// Function to find the index of the peak element in a rotated sorted array
int findPeakIndex(int *arr, int start, int end) {
    int mid;

    // Perform binary search to find the peak index
    while (start < end) {
        mid = start + (end - start) / 2;

        // If the middle element is greater than the next element, it is the peak
        if (*(arr + mid) > *(arr + (mid + 1))) {
            return mid;
        }
        // If the middle element is smaller than the first element, the peak is in the left half
        else if (*(arr + mid) < *(arr + start)) {
            end = mid - 1;
        }
        // Otherwise, the peak is in the right half
        else {
            start = mid + 1;
        }
    }

    // When the loop ends, start (or end) is the peak index
    return start;
}

// Function to search for a key in a rotated sorted array
int search(int *arr, int n, int key) {
    // Find the index of the peak element in the array
    int peakIndex = findPeakIndex(arr, 0, n - 1);

    // Search for the key in the left half (ascending part) of the array
    int leftHalf = searchKey(arr, 0, peakIndex, key);
    if (leftHalf != -1) {
        return leftHalf; // Key found in the left half
    }

    // Search for the key in the right half (ascending part) of the array
    int rightHalf = searchKey(arr, peakIndex + 1, n - 1, key);
    return rightHalf; // Return the result of the right half search
}

// Main function to test the search function
int main() {
    // Test Case 1: Rotated sorted array with key present
    int arr1[] = {4, 5, 6, 7, 0, 1, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int key1 = 0;
    printf("Test Case 1: Index of %d is %d\n", key1, search(arr1, n1, key1)); // Expected Output: 4

    // Test Case 2: Rotated sorted array with key not present
    int arr2[] = {4, 5, 6, 7, 0, 1, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int key2 = 3;
    printf("Test Case 2: Index of %d is %d\n", key2, search(arr2, n2, key2)); // Expected Output: -1

    // Test Case 3: Non-rotated sorted array with key present
    int arr3[] = {1, 2, 3, 4, 5, 6, 7};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int key3 = 5;
    printf("Test Case 3: Index of %d is %d\n", key3, search(arr3, n3, key3)); // Expected Output: 4

    return 0;
}

/*
Time and Complexity:
The time complexity of the search function is O(log n), where n is the size of the array. This is because both the findPeakIndex and searchKey functions use binary search, which divides the search space in half at each step. The findPeakIndex function performs a binary search to locate the peak element, and the searchKey function performs another binary search on either the left or right half of the array. Since both operations are logarithmic, the overall time complexity remains O(log n).

Space Complexity:
The space complexity of the search function is O(log n) due to the recursive nature of the searchKey function. Each recursive call consumes space on the call stack, and the maximum depth of recursion is proportional to the logarithm of the array size. However, if the searchKey function is implemented iteratively, the space complexity can be reduced to O(1).
*/