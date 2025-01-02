#include <iostream>
#include <vector>
using namespace std;

// Function to push zeros to the end
void pushZerosAtEnd(vector<int> &arr)  
{
    int start = 0, end = arr.size() - 1;

    while (start <= end) {
        if (arr[end] == 0) {
            end--;
            continue;
        }
        
        if (arr[start] == 0) {
            for (int i = start; i < end; i++) {
                arr[i] = arr[i + 1];
            }
            arr[end] = 0;
            end--;
        }
        else {
            start++;
        }
    }
}

// Main function
int main() {
    // Test case 1
    vector<int> arr1 = {1, 0, 2, 0, 3, 4, 0};
    pushZerosAtEnd(arr1);
    for (int num : arr1) cout << num << " ";
    cout << endl; // Output: 1 2 3 4 0 0 0

    // Test case 2
    vector<int> arr2 = {0, 0, 0, 5, 6, 7};
    pushZerosAtEnd(arr2);
    for (int num : arr2) cout << num << " ";
    cout << endl; // Output: 5 6 7 0 0 0

    // Test case 3
    vector<int> arr3 = {10, 0, 0, 20, 30, 0};
    pushZerosAtEnd(arr3);
    for (int num : arr3) cout << num << " ";
    cout << endl; // Output: 10 20 30 0 0 0

    return 0;
}

/*
Time Complexity:
The time complexity of the provided pushZerosAtEnd function is O(n^2) in the worst case, where 
n is the size of the input array. This arises because, for every zero encountered in the array, a nested loop shifts elements to the left by one position. If there are k zeros in the array, and shifting for each zero involves up to O(n) operations, the overall complexity is approximately O(k×n), which can degrade to O(n^2) if k is close to n.

Space Complexity:
The space complexity is O(1), as the function operates in-place without requiring any additional data structures or memory. All manipulations and updates are performed directly on the input array, with only a few integer variables (start, end, and loop variables) used for tracking.
Thus, the algorithm trades off space efficiency for higher time complexity due to repeated element shifts.
*/