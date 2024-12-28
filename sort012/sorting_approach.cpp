#include <bits/stdc++.h>
using namespace std;

// Function to sort the array containing only 0s, 1s, and 2s using Bubble Sort
void sort012(int *arr, int n)
{
   // Loop through each element except the last one
   for(int i = 0; i < n-1; i++) {
      // Inner loop compares each element with the next one
      for(int j = 0; j < n-i-1; j++) {
         // Swap if elements are out of order
         if(arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
         }
      }
   }
}

int main() {
    // Test case 1: Array with mixed 0s, 1s, and 2s
    int arr1[] = {0, 1, 2, 1, 0, 2, 1, 0};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    sort012(arr1, n1);
    cout << "Sorted array 1: ";
    for(int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    // Test case 2: Array with only 0s
    int arr2[] = {0, 0, 0, 0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    sort012(arr2, n2);
    cout << "Sorted array 2: ";
    for(int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // Test case 3: Array with only 2s
    int arr3[] = {2, 2, 2, 2};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    sort012(arr3, n3);
    cout << "Sorted array 3: ";
    for(int i = 0; i < n3; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:
The algorithm uses two nested loops, each of which can iterate up to n. Therefore, the time complexity of Bubble Sort is O(n^2), where n is the size of the array.

Space Complexity:
The space complexity is O(1) because Bubble Sort works in place and does not require additional space for sorting, except for a few temporary variables used for swapping.
*/