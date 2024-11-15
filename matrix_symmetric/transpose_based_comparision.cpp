#include <bits/stdc++.h>  
using namespace std;

// Function to check if a given square matrix is symmetric.
bool isMatrixSymmetric(vector<vector<int>> matrix) {
    
    // Determine the size of the matrix (assumes matrix is square).
    int n = matrix.size();

    // Create an empty matrix 'transpose' with the same dimensions as 'matrix'.
    vector<vector<int>> transpose(n, vector<int>(n, 0));

    // Populate the 'transpose' matrix by swapping rows and columns of 'matrix'.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Assign element at matrix[j][i] to transpose[i][j].
            transpose[i][j] = matrix[j][i];
        }
    }

    // Compare the original matrix with its transpose to check for symmetry.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // If any corresponding elements differ, the matrix is not symmetric.
            if (matrix[i][j] != transpose[i][j]) {
                return false;
            }
        }
    }

    // If all elements match, the matrix is symmetric.
    return true;
}

/*
Time Complexity:
The time complexity of this code is O(n^2) because it iterates through all elements of an n×n matrix twice—first to create the transpose of the matrix and then to compare the original matrix with its transpose. In each nested loop, we process every element once, resulting in n×n or O(n^2) operations.

Space Complexity:
The space complexity is also O(n^2), as we create a separate n×n matrix to store the transpose. This additional matrix requires space proportional to the number of elements in the original matrix, leading to an 
O(n^2) space requirement.
*/