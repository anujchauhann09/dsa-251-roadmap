#include <iostream>
#include <vector>
using namespace std;

void pushZerosAtEnd(vector<int> &arr)  
{
    int n = arr.size();
    vector<int> answer;

    // Collect all non-zero elements
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            answer.push_back(arr[i]);
        }
    }

    // Collect all zero elements
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            answer.push_back(arr[i]);
        }
    }

    // Copy the elements back to the original array
    for(int i = 0; i < n; i++) {
        arr[i] = answer[i];
    }
}

int main() {
    // Test case 1
    vector<int> arr1 = {0, 1, 2, 0, 3, 4};
    pushZerosAtEnd(arr1);
    cout << "Test Case 1: ";
    for(int num : arr1) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> arr2 = {1, 2, 3, 4};
    pushZerosAtEnd(arr2);
    cout << "Test Case 2: ";
    for(int num : arr2) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 3
    vector<int> arr3 = {0, 0, 0, 0};
    pushZerosAtEnd(arr3);
    cout << "Test Case 3: ";
    for(int num : arr3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of the provided algorithm is O(n), where n is the size of the input array. This is because the algorithm iterates over the array three times: the first loop collects non-zero elements, the second loop collects zeros, and the third loop copies elements back to the original array. Although there are three iterations, the time complexity remains linear, as constants are ignored in Big-O notation.

Space Complexity:
The space complexity is O(n), as the algorithm uses an additional vector, answer, to store all elements (both non-zero and zero). This auxiliary vector requires memory proportional to the size of the input array, resulting in linear space usage.
Thus, the algorithm is efficient in terms of time but requires extra memory due to the use of the auxiliary vector.
*/