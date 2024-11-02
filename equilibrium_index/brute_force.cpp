#include <bits/stdc++.h> // Include the standard libraries for I/O and general utilities
using namespace std;

// Function to find the equilibrium index of the array
int findEquilibriumIndex(vector<int> &arr) {
    int n = arr.size(); // Get the size of the array
    
    // Loop through each element in the array
    for(int i = 0; i < n; i++) { 
        int leftSum = 0, rightSum = 0; // Initialize left and right sums for the current index
        
        // Calculate the left sum for all elements before the index i
        for(int j = 0; j < i; j++) {
            leftSum += arr[j]; // Add the value of arr[j] to leftSum
        }

        // Calculate the right sum for all elements after the index i
        for(int j = i + 1; j < n; j++) {
            rightSum += arr[j]; // Add the value of arr[j] to rightSum
        }

        // Check if the left sum and right sum are equal
        if(leftSum == rightSum) {
            return i; // If they are equal, return the current index as the equilibrium index
        }
    }

    return -1; // If no equilibrium index is found after checking all elements, return -1
}

// Example main function to test the findEquilibriumIndex function
int main() {
    vector<int> arr = {1, 7, 3, 6, 5, 6}; // Example array
    int index = findEquilibriumIndex(arr); // Call the function to find the equilibrium index

    // Output the result
    if(index != -1) {
        cout << "Equilibrium index found at: " << index << endl; // Print the index if found
    } else {
        cout << "No equilibrium index found." << endl; // Print a message if not found
    }

    return 0; // Return 0 to indicate successful execution of the program
}

/*
Time Complexity:
The time complexity of the given code is O(n^2) because for each element in the array, it calculates the left and right sums by iterating through the elements to the left and right of the current index. This results in nested loops, where the outer loop runs n times, and the inner loops, in the worst case, also run approximately n times, leading to a quadratic growth in the number of operations relative to the size of the input array.

Space Complexity:
The space complexity is O(1) because the algorithm only uses a fixed amount of additional space for the variables leftSum and rightSum, regardless of the size of the input array. Therefore, no extra space proportional to the input size is allocated, making it a constant space complexity.
*/