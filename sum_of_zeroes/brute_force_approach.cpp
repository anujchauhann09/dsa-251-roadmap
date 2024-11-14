#include <bits/stdc++.h>  

// Function to calculate the coverage of zeros by neighboring 1s in the matrix.
int coverageOfMatrix(vector<vector<int>> &mat) {
    // Retrieve the dimensions of the matrix.
    int n = mat.size();      // Number of rows in the matrix
    int m = mat[0].size();   // Number of columns in the matrix

    // Variable to store the total coverage of 0's by 1's in the matrix.
    int ans = 0;

    // Loop through each cell of the matrix.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            // If the current cell contains 1, we skip checking its neighbors.
            if(mat[i][j] == 1) {
                continue;
            }
            
            // Check if there is a neighbor to the left (row above) and if it contains 1.
            // If so, add it to the coverage count.
            if(i - 1 >= 0) {
                ans += mat[i-1][j];
            }

            // Check if there is a neighbor on the right and if it contains 1.
            // If so, add it to the coverage count.
            if(j + 1 < m) {
                ans += mat[i][j+1];
            }

            // Check if there is a neighbor below and if it contains 1.
            // If so, add it to the coverage count.
            if(i + 1 < n) {
                ans += mat[i+1][j];
            }

            // Check if there is a neighbor to the left (column to the left) and if it contains 1.
            // If so, add it to the coverage count.
            if(j - 1 >= 0) {
                ans += mat[i][j-1];
            }
        }
    }

    // Return the total coverage count as the result.
    return ans;
}

int main() {
    // Test case 1: Matrix with mixed 0s and 1s
    vector<vector<int>> matrix1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    cout << "Coverage for matrix1: " << coverageOfMatrix(matrix1) << endl;

    // Test case 2: Matrix with all 1s
    vector<vector<int>> matrix2 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    cout << "Coverage for matrix2: " << coverageOfMatrix(matrix2) << endl;

    // Test case 3: Matrix with all 0s
    vector<vector<int>> matrix3 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    cout << "Coverage for matrix3: " << coverageOfMatrix(matrix3) << endl;

    // Test case 4: Rectangular matrix
    vector<vector<int>> matrix4 = {
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    cout << "Coverage for matrix4: " << coverageOfMatrix(matrix4) << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of this code is O(n×m) because it iterates through each cell of the matrix, which has n rows and m columns. For each cell, it checks up to four neighboring cells (top, right, bottom, and left) to see if they contain the value 1. Since each neighboring check is a constant-time operation and there are at most four neighbors, this results in a constant time for each cell, making the overall complexity O(n×m).

Space Complexity:
The space complexity is O(1), or constant space, because it only uses a few integer variables (such as n, m, and ans) and no additional data structures that grow with the input size. Therefore, no additional space proportional to the size of the matrix is required, resulting in a constant space complexity.
*/