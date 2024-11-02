#include<iostream>
#include<bits/stdc++.h>  // Includes all standard libraries, useful for competitive programming.
using namespace std;

vector<int> rotateArray(vector<int> arr, int k) {
    // Outer loop to rotate the array 'k' times.
    // This means each rotation will shift all elements in 'arr' one position to the left.
    for(int i = 0; i < k; i++) {
        // Store the first element temporarily as it will be "rotated out" in this rotation step.
        int temp = arr[0];

        // Inner loop to shift elements to the left by one position.
        // This loop starts from the first element and moves each element one position left.
        for(int j = 0; j < arr.size() - 1; j++) {
            // Move each element one position to the left.
            arr[j] = arr[j + 1];
        }

        // Place the initially saved first element (temp) at the last position of the array.
        arr[arr.size() - 1] = temp;
    }

    // Return the modified array after k rotations.
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
The time complexity of this code is O(n * k), where n is the size of the array and k is the number of rotations to perform. This complexity arises because, for each rotation (which we do k times), we must shift all n elements one position to the left. Therefore, the time complexity is k times n, resulting in O(n * k) overall.

Space Complexity:
The space complexity is O(1) because the algorithm performs the rotation in place without using extra memory proportional to the input size. It only uses a single temporary variable temp to store a single element during each rotation. Consequently, the space complexity remains constant, or O(1).
*/