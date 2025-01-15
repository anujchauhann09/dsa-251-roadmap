#include <bits/stdc++.h>
using namespace std;

// Function to find the k-th smallest element in the merged sorted array of two sorted arrays
int findKthElement(vector<int> &arr1, vector<int> &arr2, int k) {
    int m = arr1.size(); // Size of the first array
    int n = arr2.size(); // Size of the second array

    // Create a new vector to store the merged result of arr1 and arr2
    vector<int> answer((m + n), 0);
    int index = 0; // Index for the merged array
    int i = 0, j = 0; // Pointers for arr1 and arr2

    // Merge both arrays into the `answer` vector
    while (i < m && j < n) {
        if (arr1[i] == arr2[j]) {
            // If elements are equal, add both to the merged array
            answer[index++] = arr1[i];
            answer[index++] = arr2[j];
            i++;
            j++;
        } else if (arr1[i] > arr2[j]) {
            // If arr1[i] > arr2[j], add arr2[j] to the merged array and move pointer j
            answer[index++] = arr2[j];
            j++;
        } else {
            // If arr1[i] < arr2[j], add arr1[i] to the merged array and move pointer i
            answer[index++] = arr1[i];
            i++;
        }
    }

    // Add remaining elements of arr1 (if any)
    while (i < m) {
        answer[index++] = arr1[i];
        i++;
    }

    // Add remaining elements of arr2 (if any)
    while (j < n) {
        answer[index++] = arr2[j];
        j++;
    }

    // Calculate the k-th index from the back in the merged array
    int kThIndexFromBack = (index + 1) - k; 

    // Return the k-th smallest element
    return answer[index - kThIndexFromBack];
}

int main() {
    // Test case 1
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    int k = 5;
    cout << "Test Case 1: The " << k << "-th smallest element is " << findKthElement(arr1, arr2, k) << endl;
    // Expected output: 5

    // Test case 2
    vector<int> arr1 = {10, 20, 30, 40};
    vector<int> arr2 = {15, 25, 35, 45};
    k = 6;
    cout << "Test Case 2: The " << k << "-th smallest element is " << findKthElement(arr1, arr2, k) << endl;
    // Expected output: 35

    // Test case 3
    vector<int> arr1 = {1, 1, 1, 1};
    vector<int> arr2 = {2, 2, 2, 2};
    k = 7;
    cout << "Test Case 3: The " << k << "-th smallest element is " << findKthElement(arr1, arr2, k) << endl;
    // Expected output: 2

    return 0;
}

/*
Time Complexity:
The time complexity of the findKthElement function is determined by the process of merging the two sorted arrays into a single sorted array. During this process, we iterate through both arrays in their entirety. Specifically, each element of the first array (arr1) and the second array (arr2) is compared and added to the answer array exactly once. This results in a time complexity of O(m+n), where m is the size of arr1 and n is the size of arr2.

Additionally, once the arrays are merged, the operation to find the k-th smallest element involves only a direct index lookup in the merged array, which takes O(1) time. Therefore, the dominant factor in the time complexity is the merging process, making the overall time complexity O(m+n).

Space Complexity:
For the space complexity, the answer vector is used to store the merged elements of the two input arrays. Since the size of answer is equal to the combined size of the input arrays (m + n), the space complexity is 
O(m+n). Apart from this, a few integer variables (i, j, index, and kThIndexFromBack) are used, but their memory usage is constant and does not depend on the input size, which means their contribution to the space complexity is negligible.

Thus, the overall time complexity of the function is O(m+n), and the overall space complexity is O(m+n).
*/