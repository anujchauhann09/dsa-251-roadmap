#include <bits/stdc++.h>
using namespace std;

int firstMissing(int arr[], int n) {
    int number = 1;            // Initialize the 'number' to start checking from 1
    set<int> arrSet;            // Declare a set to store unique positive elements from 'arr'

    // Traverse the array and add only positive elements to the set
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {       // Consider only positive numbers for missing positive check
            arrSet.insert(arr[i]); // Insert positive elements into the set
        }
    }

    // The set 'arrSet' now contains all unique positive elements in sorted order
    // Iterate through each element in the set to find the smallest missing positive integer
    for (auto ele : arrSet) {
        if (number != ele) {    // If current number does not match 'ele', it's the missing integer
            return number;      // Return the smallest missing positive integer
        }
        number++;               // Increment 'number' to check the next integer
    }

    // If all numbers from 1 to the largest element in the set are present, return the next number
    return number;
}

// Main function to test the firstMissing function with a few test cases
int main() {
    int arr1[] = {3, 4, -1, 1};
    int arr2[] = {1, 2, 0};
    int arr3[] = {7, 8, 9, 11, 12};
    
    cout << "First missing positive in arr1: " << firstMissing(arr1, 4) << endl;  // Expected output: 2
    cout << "First missing positive in arr2: " << firstMissing(arr2, 3) << endl;  // Expected output: 3
    cout << "First missing positive in arr3: " << firstMissing(arr3, 5) << endl;  // Expected output: 1

    return 0;
}

/*
Time Complexity:
The time complexity of this code is O(n log n) in the worst case. This results from inserting up to n elements into a set, where each insertion operation takes O(log n) due to the need to maintain the sorted order in the set. The final loop that checks for the missing integer iterates through the set, which is O(m), where m is the number of unique positive integers in the array, but m is bounded by n, so it does not increase the overall complexity beyond O(n log n).

Space Complexity:
The space complexity is O(n) because, in the worst case, all elements in the input array are positive and unique, so they all get added to the set, requiring storage for up to n elements. Thus, the code’s time complexity is driven by the set insertion operations, while its space complexity depends on the storage of unique positive integers in the set.
*/