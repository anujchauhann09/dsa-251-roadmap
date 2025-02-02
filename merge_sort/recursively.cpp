#include <iostream>
#include <vector>
using namespace std;

// Merge function to combine two sorted subarrays into a single sorted array
void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray

    vector<int> leftArr(n1); // Temporary array for the left subarray
    vector<int> rightArr(n2); // Temporary array for the right subarray

    // Copy data to temporary leftArr
    for(int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }

    // Copy data to temporary rightArr
    for(int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left; // Indices for leftArr, rightArr, and merged array

    // Merge the two subarrays back into the original array
    while(i < n1 && j < n2) {
        if(leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr, if any
    while(i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr, if any
    while(j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Helper function to recursively divide the array and sort it using merge
void mergeSortHelper(vector<int> &arr, int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2; // Find the middle point
        mergeSortHelper(arr, left, mid); // Sort the left half
        mergeSortHelper(arr, mid + 1, right); // Sort the right half
        merge(arr, left, mid, right); // Merge the sorted halves
    }
}

// Main mergeSort function to initiate the sorting process
void mergeSort(vector<int> &arr, int n) {
    mergeSortHelper(arr, 0, n - 1);
}

// Main function to test the mergeSort implementation
int main() {
    // Test Case 1
    vector<int> arr1 = {38, 27, 43, 3, 9, 82, 10};
    int n1 = arr1.size();
    cout << "Original array 1: ";
    for(int num : arr1) cout << num << " ";
    cout << endl;
    mergeSort(arr1, n1);
    cout << "Sorted array 1: ";
    for(int num : arr1) cout << num << " ";
    cout << endl << endl;

    // Test Case 2
    vector<int> arr2 = {5, 2, 9, 1, 5, 6};
    int n2 = arr2.size();
    cout << "Original array 2: ";
    for(int num : arr2) cout << num << " ";
    cout << endl;
    mergeSort(arr2, n2);
    cout << "Sorted array 2: ";
    for(int num : arr2) cout << num << " ";
    cout << endl << endl;

    // Test Case 3
    vector<int> arr3 = {100, 20, 50, 30, 80, 40};
    int n3 = arr3.size();
    cout << "Original array 3: ";
    for(int num : arr3) cout << num << " ";
    cout << endl;
    mergeSort(arr3, n3);
    cout << "Sorted array 3: ";
    for(int num : arr3) cout << num << " ";
    cout << endl << endl;

    return 0;
}

/*
Time Complexity: 
The time complexity of merge sort is O(n log n), where n is the number of elements in the array. This is because the array is repeatedly divided into halves (log n divisions), and each merge operation takes O(n) time.

Space Complexity: 
The space complexity is O(n) due to the additional temporary arrays used during the merge process. This is because we need to store the left and right subarrays during the merging step.
*/