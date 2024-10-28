#include<iostream>
using namespace std;
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
    vector<int> arr = {10, 10, 10, 10};
    vector<int> arr2 = {7, 8, 8, 1, 4, 3};

    cout<< findSecondLargest(arr.size(), arr)<< endl;
    cout<< findSecondLargest(arr2.size(), arr2)<< endl; 

    return 1;
}