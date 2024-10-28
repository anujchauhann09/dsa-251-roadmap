#include <bits/stdc++.h> // Includes all standard libraries in C++, convenient for competitive programming.

int findSecondLargest(int n, vector<int> &arr) {
    int maxValue = INT_MIN;       // Initialize to the smallest possible integer, representing the largest value found so far.
    int secMaxValue = INT_MIN;     // Initialize to the smallest possible integer, representing the second largest value found so far.
    bool isAllValuesSame = true;   // Boolean flag to check if all values in the array are the same.

    // Iterate through each element of the array
    for(int i = 0; i < n; i++) {
        // Check if all values are the same by comparing adjacent elements, but only if we’re not at the last index
        if(i < n - 1 && arr[i] != arr[i + 1]) {
            isAllValuesSame = false; // If any adjacent elements differ, set the flag to false
        }

        // Update the largest and second largest values
        if(arr[i] > maxValue) {
            // Current element is larger than maxValue, so update both secMaxValue and maxValue.
            secMaxValue = maxValue; // The current max becomes the second largest
            maxValue = arr[i];      // Update maxValue to the new largest element
        }
        // Update secMaxValue only if arr[i] is less than maxValue but greater than the current secMaxValue
        else if(arr[i] > secMaxValue && arr[i] < maxValue) {
            secMaxValue = arr[i];   // Update secMaxValue if the current element qualifies
        }
    }
    
    // If all values are the same, no valid second largest exists, so return -1
    if(isAllValuesSame) {
        return -1;
    }

    // Return the second largest value found
    return secMaxValue;
}
