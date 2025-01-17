#include <bits/stdc++.h>
using namespace std;

/*
   Function to find the next greater element (NGE) for each element in an array.
   For each element, the function determines the next greater element to its right in the array.
   If no such element exists, -1 is returned for that position.
   
   Parameters:
   - arr: Vector of integers for which the NGE is to be found.
   - n: Size of the array.

   Returns:
   - A vector of integers where each index contains the NGE for the corresponding element in the input array.
*/
vector<int> nextGreater(vector<int> &arr, int n) {
    stack<int> trackNge;            // Stack to track elements for finding the NGE.
    vector<int> answer(n, -1);      // Initialize the answer array with -1 for elements without an NGE.

    // Push the last element of the array onto the stack as the starting point.
    trackNge.push(arr[n - 1]);

    // Traverse the array from right to left (starting from the second last element).
    for (int i = n - 2; i >= 0; i--) {
        int element = arr[i];       // Current element being processed.

        // Remove elements from the stack that are less than or equal to the current element.
        while (!trackNge.empty()) {
            int top = trackNge.top();

            // If the top of the stack is greater than the current element, it is the NGE.
            if (top > element) {
                answer[i] = top;    // Store the NGE in the answer vector.
                break;
            }

            trackNge.pop();         // Pop the top element if it's not greater.
        }

        // Push the current element onto the stack.
        trackNge.push(element);
    }

    return answer;
}

// Main function to test the nextGreater function.
int main() {
    // Test case 1
    vector<int> arr1 = {4, 5, 2, 10};
    vector<int> result1 = nextGreater(arr1, arr1.size());
    cout << "Next Greater Elements for {4, 5, 2, 10}: ";
    for (int val : result1) cout << val << " ";
    cout << endl;

    // Test case 2
    vector<int> arr2 = {3, 8, 4, 1, 2};
    vector<int> result2 = nextGreater(arr2, arr2.size());
    cout << "Next Greater Elements for {3, 8, 4, 1, 2}: ";
    for (int val : result2) cout << val << " ";
    cout << endl;

    // Test case 3
    vector<int> arr3 = {10, 20, 30, 40};
    vector<int> result3 = nextGreater(arr3, arr3.size());
    cout << "Next Greater Elements for {10, 20, 30, 40}: ";
    for (int val : result3) cout << val << " ";
    cout << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of the given approach is O(n), where n is the size of the input array. This is because each element is pushed onto the stack at most once and popped from the stack at most once, resulting in a total of O(n) operations for all elements. 

Space Complexity:
The space complexity is O(n) as well, due to the usage of a stack to store elements temporarily during the computation. Additionally, the output vector requires O(n) space to store the result. Therefore, the overall space usage is dominated by the stack and result vector, leading to O(n) space complexity. This approach is efficient for finding the next greater elements in a single traversal of the array while maintaining an optimal usage of memory.
*/
