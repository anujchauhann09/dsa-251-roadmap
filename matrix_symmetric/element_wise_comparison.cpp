#include <bits/stdc++.h>
using namespace std;

// Function to check if a square matrix is symmetric
bool isMatrixSymmetric(vector<vector<int>> matrix) {
    
    // Variable defines the size of the matrix
    int n = matrix.size(); 

    // Iterate through the rows and columns of the matrix
    for (int i = 0; i < n; i++) { // Outer loop for rows
        for (int j = 0; j < n; j++) { // Inner loop for columns
            
            // Check if the element at (i, j) is equal to the element at (j, i)
            // Symmetry means matrix[i][j] == matrix[j][i] for all valid i and j
            if (matrix[i][j] != matrix[j][i]) {
                
                // If a mismatch is found, the matrix is not symmetric
                return false;
            }
        }
    }

    // If no mismatch is found, the matrix is symmetric
    return true;
}

/*
Time Complexity:
The time complexity of the isMatrixSymmetric function is O(n^2), where n is the size of the square matrix (number of rows or columns). This is because the function uses two nested loops to iterate through each element of the n×n matrix. For every element at position (i, j), it compares it with its transposed element (j, i), resulting in a total of n^2 iterations.

Space Complexity:
The space complexity is O(1) because the function does not use any additional data structures or allocate extra space proportional to the input size. It only uses a few variables for indexing and comparisons, making its memory usage constant regardless of the matrix size.
*/