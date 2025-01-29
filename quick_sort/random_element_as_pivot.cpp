#include <bits/stdc++.h>
using namespace std;

// Helper function to perform QuickSort recursively.
void quickSortHelper(vector<int> &arr, int left, int right) {
    // Base case: If the subarray has 0 or 1 elements, return.
    if (left >= right) {
        return;
    }

    // Choose a random pivot index between left and right (inclusive).
    int randomIndex = left + rand() % (right - left + 1);
    // Move the pivot element to the end of the subarray.
    swap(arr[randomIndex], arr[right]);

    // Set the pivot element.
    int pivot = arr[right];

    // Initialize two pointers: i for traversal, j for partitioning.
    int i = left, j = left;

    // Partition the array around the pivot.
    while (i < right) {
        // If the current element is less than or equal to the pivot, move it to the left.
        if (arr[i] <= pivot) {
            swap(arr[i], arr[j]);
            j++;
        }
        i++;
    }

    // Place the pivot in its correct position.
    swap(arr[right], arr[j]);

    // Recursively sort the left and right partitions.
    quickSortHelper(arr, left, j - 1); // Left partition: elements < pivot.
    quickSortHelper(arr, j + 1, right); // Right partition: elements > pivot.
}

// Main QuickSort function.
vector<int> quickSort(vector<int> arr) {
    // Seed the random number generator for random pivot selection.
    srand(time(0));
    // Call the helper function to sort the array.
    quickSortHelper(arr, 0, arr.size() - 1);
    return arr;
}

int main() {
    // Test Case 1: Random array.
    vector<int> arr1 = {3, 6, 8, 10, 1, 2, 1};
    cout << "Original Array 1: ";
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;
    vector<int> sortedArr1 = quickSort(arr1);
    cout << "Sorted Array 1: ";
    for (int num : sortedArr1) {
        cout << num << " ";
    }
    cout << endl;

    // Test Case 2: Already sorted array.
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Original Array 2: ";
    for (int num : arr2) {
        cout << num << " ";
    }
    cout << endl;
    vector<int> sortedArr2 = quickSort(arr2);
    cout << "Sorted Array 2: ";
    for (int num : sortedArr2) {
        cout << num << " ";
    }
    cout << endl;

    // Test Case 3: Array with duplicate elements.
    vector<int> arr3 = {5, 2, 9, 1, 5, 6}; 
    cout << "Original Array 3: ";
    for (int num : arr3) {
        cout << num << " ";
    }
    cout << endl;
    vector<int> sortedArr3 = quickSort(arr3);
    cout << "Sorted Array 3: ";
    for (int num : sortedArr3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:
The average-case time complexity of QuickSort is O(N log N), where N is the size of the array. This occurs because the array is divided into roughly equal halves in each recursive call. However, in the worst case (e.g., when the pivot is always the smallest or largest element), the time complexity degrades to O(N²). The use of random pivot selection helps avoid the worst-case scenario in most practical cases.

Space Complexity:
The space complexity is O(log N) due to the recursion stack. In the best case, the recursion depth is logarithmic because the array is divided into roughly equal halves. In the worst case, the recursion depth can be O(N).
*/