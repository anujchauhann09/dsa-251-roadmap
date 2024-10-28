#include<iostream> // Include the iostream library for input and output operations.
using namespace std; // Use the standard namespace to avoid prefixing standard functions and objects with 'std::'.
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

int main() {
    // Initialize a vector 'arr' with all elements being 10.
    // This tests the function's ability to handle cases where all elements are identical.
    vector<int> arr = {10, 10, 10, 10};

    // Initialize another vector 'arr2' with a mix of values, including duplicates.
    // This tests the function's handling of duplicates and its ability to find the second largest unique element.
    vector<int> arr2 = {7, 8, 8, 1, 4, 3};

    // Call the findSecondLargest function on 'arr' and print the result.
    // Since all elements are the same, the expected output is -1, as there is no unique second largest value.
    cout << findSecondLargest(arr.size(), arr) << endl;

    // Call the findSecondLargest function on 'arr2' and print the result.
    // The expected output is 7, which is the second largest unique element in the array.
    cout << findSecondLargest(arr2.size(), arr2) << endl;

    return 1; // Return 1 to indicate successful execution, although returning 0 is standard in `main`.
}

/*
Time Complexity:
The time complexity is O(n), where n is the number of elements in the input array. This is because the algorithm requires a single pass through the array to determine the largest and second largest values. In each iteration, it performs a constant amount of work (comparing values and updating variables), which results in linear time complexity.

Space Complexity:
The space complexity is O(1), meaning it uses a constant amount of additional space regardless of the input size. The function only utilizes a few integer variables (maxValue, secMaxValue, and isAllValuesSame) to store state information during its execution, which does not grow with the size of the input array. Therefore, the space remains constant, making the overall space complexity O(1). This efficiency allows the function to operate optimally in terms of both time and space, effectively finding the second largest element in the array.
*/