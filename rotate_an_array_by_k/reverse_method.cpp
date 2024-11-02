#include<iostream>
#include<bits/stdc++.h>  // Includes all standard libraries, useful for competitive programming.
using namespace std;

vector<int> rotateArray(vector<int> arr, int k) {
    int n = arr.size(); // Store the size of the array in 'n'
    int startPointer = 0, endPointer = n - 1;

    // Step 1: Reverse the entire array
    // We swap elements from start to end until the pointers meet in the middle.
    // This reverses the whole array.
    while(startPointer < endPointer) {
        swap(arr[startPointer++], arr[endPointer--]);
    }

    // Step 2: Reverse the first 'n - k' elements to restore the original order of the non-rotated part
    // Set pointers to the beginning of the array and to the (n - k - 1)th element.
    startPointer = 0, endPointer = n - k - 1;
    while(startPointer < endPointer) {
        swap(arr[startPointer++], arr[endPointer--]);
    }

    // Step 3: Reverse the last 'k' elements to restore their original order
    // Set pointers to the (n - k)th element and to the last element of the array.
    startPointer = n - k, endPointer = n - 1;
    while(startPointer < endPointer) {
        swap(arr[startPointer++], arr[endPointer--]);
    }

    // Return the rotated array after all three reversal steps.
    return arr;
}

int main() {
    vector<int> arr = {7, 5, 2, 11, 2, 43, 1, 1};  // Define an initial array.
    vector<int> arr2 = {1, 2, 3, 4, 5};            // Define another array for testing.

    // Rotate 'arr' by 2 positions and 'arr2' by 3 positions.
    vector<int> result = rotateArray(arr, 2);
    vector<int> result2 = rotateArray(arr2, 3);

    // Print the original array before rotation.
    cout << "Before rotation: " << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";  // Display each element of the original array.
    } 
    cout << endl;

    // Print the rotated array result.
    cout << "After rotation: " << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";  // Display each element of the rotated array.
    } 
    cout << endl;

    return 0;  // Return 0 to indicate successful execution.
}

/*
Time Complexity:
The time complexity of this approach is O(n), where n is the size of the array. Each reversal operation involves a single pass through parts of the array, resulting in a linear time complexity.

Space Complexity:
The space complexity is O(1), as all operations are performed in place, requiring no additional memory allocation for a copy of the array. Only a few integer variables are used to track indices.
*/