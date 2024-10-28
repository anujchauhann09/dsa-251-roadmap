#include<iostream> // Include the iostream library for input and output operations.
using namespace std; // Use the standard namespace to avoid prefixing standard functions and objects with 'std::'.
#include <bits/stdc++.h> // This includes all standard libraries in C++ and is generally used in competitive programming for convenience.

int findSecondLargest(int n, vector<int> &arr) {
    // Sort the array in non-decreasing order (smallest to largest).
    sort(arr.begin(), arr.end());

    // Traverse the array from the last element to the first (right to left).
    for(int i = arr.size() - 1; i > 0; i--) {
        // Check if the current element is different from the previous one.
        // This helps skip any duplicate largest values and find the second largest unique value.
        if(arr[i] != arr[i - 1]) {
            return arr[i - 1]; // Return the second largest element when found.
        }
    }

    // If no second largest element is found (all elements are identical),
    // return -1 as a signal that there isn't a valid second largest value.
    return -1;
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
The time complexity is O(n log n) due to the sorting operation performed by the sort function, which typically runs in O(n log n) time. After sorting, the code iterates through the array in a single pass to find the second largest unique element, which contributes an additional O(n) to the overall complexity. However, the dominating factor is the sorting step, so the total time complexity remains O(n log n).

Space Complexity:
The space complexity is O(1) because the sorting is done in place, meaning it does not require any additional data structures that grow with the input size. Although the sorting algorithm may use some temporary space internally, it does not increase with the size of the input array. Hence, the space used is constant, making the space complexity O(1). Overall, the function efficiently identifies the second largest element while maintaining optimal space usage.
*/