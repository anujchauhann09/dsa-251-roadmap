#include<iostream>
#include<bits/stdc++.h>  // Includes all standard libraries, useful for competitive programming.
using namespace std;

// Function to rotate the elements of an array to the left by 'k' positions.
vector<int> rotateArray(vector<int> arr, int k) {
    int n = arr.size();  // Get the size of the array.
    int i = 0;           // Initialize a counter variable 'i' to zero.
    queue<int> arrQue;   // Create a queue to help rotate the array elements.

    // Push all elements of the array into the queue.
    for (int i = 0; i < n; i++) {
        arrQue.push(arr[i]);  // Add each element of 'arr' into 'arrQue'.
    }

    // Rotate the queue by removing the front element and adding it to the back, 'k' times.
    while (i < k) {
        int frontValue = arrQue.front();  // Get the front element of the queue.
        arrQue.pop();                     // Remove the front element.
        arrQue.push(frontValue);          // Add the removed element to the back of the queue.
        i++;                              // Increment the counter after each rotation step.
    }

    // Transfer elements from the queue back to the array.
    i = 0;  // Reset the counter to zero for use in the next loop.
    while (!arrQue.empty()) {
        arr[i++] = arrQue.front();  // Assign the front element of the queue to 'arr' and increment 'i'.
        arrQue.pop();               // Remove the front element from the queue.
    }

    return arr;  // Return the rotated array.
}

int main() {
    vector<int> arr = {7, 5, 2, 11, 2, 43, 1, 1};  // Define an initial array.
    vector<int> arr2 = {1, 2, 3, 4, 5};            // Define another array for testing.

    // Rotate 'arr' by 2 positions and 'arr2' by 3 positions.
    vector<int> result = rotateArray(arr, 2);
    vector<int> result2 = rotateArray(arr2, 3);

    // Print the original array before rotation.
    cout << "Before rotation: " << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";  // Display each element of the original array.
    } 
    cout << endl;

    // Print the rotated array result.
    cout << "After rotation: " << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";  // Display each element of the rotated array.
    } 
    cout << endl;

    return 0;  // Return 0 to indicate successful execution.
}

/*
Time Complexity:
The time complexity of this code is O(n), where n is the number of elements in the array arr. This is because the code requires three main steps, each involving a pass through the elements. First, the elements of arr are pushed into arrQue, which takes O(n). Next, the code rotates the queue k times, which takes O(k), but since k is typically less than or equal to n, this step is approximated as O(n) in the worst case. Finally, the elements from arrQue are assigned back to arr, again taking O(n). Altogether, the time complexity sums up to O(n + k + n), which simplifies to O(n).

Space Complexity:
The space complexity is also O(n) because we are using a queue, arrQue, to store the elements of arr temporarily, which requires additional space equivalent to the number of elements in arr. This additional space allocation results in a space complexity of O(n).
*/