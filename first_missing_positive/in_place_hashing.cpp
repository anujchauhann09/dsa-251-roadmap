#include <bits/stdc++.h>
using namespace std;

// Function to find the smallest missing positive integer in an unsorted array
int firstMissing(int arr[], int n) {
    // First loop: place each element in its correct index position if possible
    for (int i = 0; i < n; i++) {
        // While the current element is positive, less than or equal to n, and not in its correct position
        // (i.e., arr[i] should be at index arr[i] - 1), keep swapping it to the correct position.
        while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) { // if can also be used
            swap(arr[i], arr[arr[i] - 1]);
        }
    }

    // Second loop: find the first index where the element is not in its expected position
    for (int i = 0; i < n; i++) {
        // If arr[i] is not equal to i + 1, then i + 1 is the smallest missing positive integer
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }

    // If all elements from 1 to n are present in the correct positions, then the smallest missing
    // positive integer is n + 1
    return n + 1;
}

int main() {
    int arr1[] = {3, 4, -1, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "First missing positive for arr1: " << firstMissing(arr1, n1) << endl; // Output: 2

    int arr2[] = {1, 2, 0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "First missing positive for arr2: " << firstMissing(arr2, n2) << endl; // Output: 3

    int arr3[] = {7, 8, 9, 11, 12};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "First missing positive for arr3: " << firstMissing(arr3, n3) << endl; // Output: 1

    return 0;
}

/*
Time Complexity:
The time complexity of this code is O(n) because each element is moved to its correct position at most once, making the sorting process efficient. Although there is a nested while loop, each swap operation places an element closer to its correct index, ensuring that each element is processed a constant number of times. This results in a linear time complexity. 

Space Complexity:
The space complexity is O(1) since the solution rearranges the elements within the input array itself and does not use any additional data structures that scale with the input size. Only a few integer variables are used for indexing and swapping, making the algorithm in-place and space-efficient.
*/