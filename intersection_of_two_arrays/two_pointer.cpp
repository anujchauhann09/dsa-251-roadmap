#include <bits/stdc++.h>
using namespace std;

// Function to find the intersection of two sorted arrays
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m) {
    vector<int> result; // Vector to store the intersection elements
    int i = 0, j = 0;   // Two pointers for traversing arr1 and arr2

    // Traverse both arrays until one of them is exhausted
    while(i < n && j < m) {
        if(arr1[i] == arr2[j]) {
            // If elements match, add to result and move both pointers forward
            result.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] > arr2[j]) {
            // If arr1[i] is greater, move pointer j to the next element in arr2
            j++;
        }
        else {
            // If arr1[i] is smaller, move pointer i to the next element in arr1
            i++;
        }
    }

    // Return the vector containing common elements
    return result;
}

int main() {
    // Test Case 1
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 4, 6, 8};
    vector<int> result = findArrayIntersection(arr1, arr1.size(), arr2, arr2.size());
    cout << "Intersection: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    // Test Case 2
    vector<int> arr1_2 = {1, 1, 2, 3};
    vector<int> arr2_2 = {1, 1, 3, 5};
    result = findArrayIntersection(arr1_2, arr1_2.size(), arr2_2, arr2_2.size());
    cout << "Intersection: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    // Test Case 3
    vector<int> arr1_3 = {10, 20, 30};
    vector<int> arr2_3 = {15, 20, 25, 30, 35};
    result = findArrayIntersection(arr1_3, arr1_3.size(), arr2_3, arr2_3.size());
    cout << "Intersection: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of the given algorithm is O(n+m), where n and m are the sizes of the input arrays arr1 and arr2, respectively. This is because the two-pointer approach ensures that we traverse each array exactly once. The loop compares elements in both arrays and advances one or both pointers depending on the comparison. Since each pointer moves forward in its respective array without revisiting elements, the overall time taken is proportional to the combined lengths of the two arrays.

Space Complexity:
The space complexity is O(k), where k is the number of elements in the intersection. The algorithm uses a vector, result, to store the common elements between the two arrays. No additional memory is used for operations since the algorithm processes the input arrays in-place without creating extra data structures. Thus, the space complexity depends only on the number of intersection elements stored in the result vector.
*/