#include<iostream> // Include the iostream library for input and output operations.
using namespace std; // Use the standard namespace to avoid prefixing standard functions and objects with 'std::'.
#include <bits/stdc++.h> // Include all standard libraries in C++. Commonly used in competitive programming for convenience.

int findSecondLargest(int n, vector<int> &arr) {
    int maxValue = INT_MIN; // Initialize maxValue to the smallest possible integer value.
    int secMaxValue = INT_MIN; // Initialize secMaxValue to the smallest possible integer value.
    set<int> arrSet; // Create a set to store unique elements from the array.

    // Loop through the input array to populate the set with unique values.
    for (int i = 0; i < n; i++) {
        arrSet.insert(arr[i]); // Insert each element of arr into the set, automatically handling duplicates.
    }

    // Check if the set contains only one unique value.
    if (arrSet.size() == 1) // If there is only one unique element, return -1 as there is no second largest.
        return -1;

    // Iterate through the set to determine the largest and second largest values.
    for (auto value : arrSet) {
        secMaxValue = maxValue; // Update secMaxValue to the current maxValue before updating maxValue.
        maxValue = value; // Update maxValue to the current value from the set.
    }

    // Return the second largest unique value found.
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
The time complexity is O(n), where n is the number of elements in the input array. This complexity arises because the algorithm requires a single pass through the array to insert all elements into a set, which inherently handles duplicates and stores only unique values. Inserting each element into the set takes average constant time, leading to a linear time complexity for this operation. After populating the set, the algorithm then iterates through the unique elements, which, in the worst case, can also be O(n) if all elements are distinct. Thus, the overall time complexity remains O(n).

Space Complexity:
The space complexity is O(u), where u is the number of unique elements in the array. This is because the set is used to store these unique elements, and the amount of space required is directly proportional to the number of unique values. In the worst case, where all elements are unique, the space complexity would be O(n). However, since the space used is dependent on the distinct elements, we represent the space complexity in terms of u. Therefore, the algorithm is efficient in terms of both time and space, effectively finding the second largest unique element in the input array.
*/