#include <stdio.h>

// Function to search for a key in an array using linear search
int search(int *arr, int n, int key) {
    // Iterate through each element of the array
    for (int i = 0; i < n; i++) {
        // If the current element matches the key, return its index
        if (*(arr + i) == key) {
            return i;
        }
    }

    // If the key is not found after traversing the array, return -1
    return -1;
}

// Main function to test the search function
int main() {
    // Test Case 1: Key present in the array
    int arr1[] = {4, 5, 6, 7, 0, 1, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int key1 = 0;
    printf("Test Case 1: Index of %d is %d\n", key1, search(arr1, n1, key1)); // Expected Output: 4

    // Test Case 2: Key not present in the array
    int arr2[] = {4, 5, 6, 7, 0, 1, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int key2 = 3;
    printf("Test Case 2: Index of %d is %d\n", key2, search(arr2, n2, key2)); // Expected Output: -1

    // Test Case 3: Key present at the first index
    int arr3[] = {1, 2, 3, 4, 5, 6, 7};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int key3 = 1;
    printf("Test Case 3: Index of %d is %d\n", key3, search(arr3, n3, key3)); // Expected Output: 0

    return 0;
}

/*
Time Complexity:
The time complexity of the search function is O(n), where n is the size of the array. This is because the function uses a linear search algorithm, which iterates through each element of the array one by one until it finds the key or reaches the end of the array. In the worst case, the key may be at the end of the array or not present at all, requiring the function to check all n elements.

Space Complexity: 
The space complexity of the search function is O(1). This is because the function uses a constant amount of extra space, regardless of the size of the input array. The only variables used are i (loop counter) and the function parameters (arr, n, and key), which do not depend on the size of the array.
*/