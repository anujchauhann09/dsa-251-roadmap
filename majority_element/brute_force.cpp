#include <bits/stdc++.h> 
using namespace std;

int findMajorityElement(int arr[], int n) {
    // Calculate the limit, which is floor(n/2)
    int limit = floor(n / 2);
    int answer = -1; // Default value if no majority element is found

    // Loop through every element in the array
    for (int i = 0; i < n; i++) {
        int count = 0;

        // Count how many times arr[i] appears in the array
        for (int j = i; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        // If count exceeds the limit, update the answer
        if (count > limit) {
            answer = arr[i];
        }
    }

    return answer; // Return the majority element or -1 if no majority element exists
}

int main() {
    // Test case 1: Majority element is present
    int arr1[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Majority Element in arr1: " << findMajorityElement(arr1, n1) << endl; // Expected: 4

    // Test case 2: Majority element is present
    int arr2[] = {1, 1, 1, 3, 3, 2, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Majority Element in arr2: " << findMajorityElement(arr2, n2) << endl; // Expected: 1

    // Test case 3: No majority element present
    int arr3[] = {1, 2, 3, 4, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Majority Element in arr3: " << findMajorityElement(arr3, n3) << endl; // Expected: -1

    return 0;
}

/*
Time Complexity:
The time complexity of this solution is O(n²) because for each element, it counts how many times it appears in the array using a nested loop.

Space Complexity:
The space complexity is O(1) because only a few variables are used, regardless of the size of the input array.
*/