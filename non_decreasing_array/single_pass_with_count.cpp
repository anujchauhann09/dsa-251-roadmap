#include <bits/stdc++.h> // Include standard libraries for I/O and general utilities
using namespace std;

// Function to determine if an array can be modified at most once to become non-decreasing
bool isPossible(int *arr, int n) {
    int count = 0; // Counter to track the number of modifications needed

    // Traverse the array from the start to the second-to-last element
    for(int i = 0; i < n - 1; i++) {
        // Check if the current element is greater than the next element (indicating an out-of-order pair)
        if(arr[i] > arr[i + 1]) {
            count++; // Increment the modification counter

            // If more than one modification is needed, return false immediately
            if(count > 1) {
                return false;
            }

            // Determine if modifying arr[i] or arr[i+1] could help fix the order
            if(i == 0 || arr[i - 1] <= arr[i + 1]) {
                // Modify arr[i] to make it equal to arr[i+1] if:
                // - we’re at the beginning of the array (no arr[i-1] to check), or
                // - arr[i-1] <= arr[i+1] so this modification preserves non-decreasing order
                arr[i] = arr[i + 1];
            } else {
                // If neither condition above holds, modify arr[i+1] to make it equal to arr[i]
                arr[i + 1] = arr[i];
            }
        }
    }

    // Return true if we’ve gone through the loop with no more than one modification needed
    return true;
}

int main() {
    // Define an array with some elements, which will be checked for non-decreasing order
    int arr[] = {-71, -46, -41, -8, 7, 35, 219, -150, 57, 59};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Call the isPossible function and output whether the array can be made non-decreasing
    if (isPossible(arr, n)) {
        cout << "Yes, it can become non-decreasing by modifying at most one element." << endl;
    } else {
        cout << "No, it cannot become non-decreasing by modifying at most one element." << endl;
    }

    return 0; // Return 0 to indicate successful program execution
}

/*
Time Complexity:
The time complexity of this code is O(n) because the function iterates through the array once in a single loop. During each iteration, it checks if the current element is greater than the next element to determine if the array is out of order. For each out-of-order occurrence, a maximum of one comparison and one modification operation are performed, but these are constant time operations, making the entire loop proportional to n where n is the size of the array.

Space Complexity:
The space complexity of this code is O(1) since no additional space is required that grows with the input size. Only a few integer variables (count, i) are used for tracking and control, which occupy constant space regardless of the array size. Modifications are made in place within the input array, so no additional arrays or data structures are created, resulting in a constant space usage. Thus, the function efficiently checks for and enforces the non-decreasing condition with at most one modification needed, while maintaining minimal memory usage.
*/
