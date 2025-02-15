#include <bits/stdc++.h>
using namespace std;

// Function to set zeros in the matrix such that if an element is 0,
// its entire row and column are set to 0. This function uses an auxiliary
// matrix "trackZero" to remember the original positions of zeros.
void setZeros(vector<vector<int>> &matrix) {
    int n = matrix.size();         // Number of rows
    int m = matrix[0].size();      // Number of columns

    // Create an auxiliary matrix to track the positions of zeros.
    // Initialized with -1; positions with a 0 in the original matrix will be marked as 0.
    vector<vector<int>> trackZero(n, vector<int>(m, -1));

    // Traverse the matrix to mark the positions of zeros in trackZero.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                trackZero[i][j] = 0;
            }
        }
    }

    // For each marked zero, set its entire row and column to zero.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (trackZero[i][j] != 0) {
                continue; // Skip if this position was not originally zero
            }

            // Set all elements in the current column to zero (above and below the zero).
            for (int k = i - 1; k >= 0; k--) {
                matrix[k][j] = 0;
            }
            for (int k = i + 1; k < n; k++) {
                matrix[k][j] = 0;
            }

            // Set all elements in the current row to zero (left and right of the zero).
            for (int k = j - 1; k >= 0; k--) {
                matrix[i][k] = 0;
            }
            for (int k = j + 1; k < m; k++) {
                matrix[i][k] = 0;
            }
        }
    }
}

// Utility function to print a 2D matrix.
void printMatrix(const vector<vector<int>> &matrix) {
    for (const auto &row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Main function with test cases
int main() {
    // Test Case 1: A 3x3 matrix with a single zero in the middle.
    // Expected output:
    // 1 0 3
    // 0 0 0
    // 7 0 9
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };
    cout << "Original Matrix 1:" << endl;
    printMatrix(matrix1);
    setZeros(matrix1);
    cout << "Modified Matrix 1:" << endl;
    printMatrix(matrix1);

    // Test Case 2: A 4x4 matrix with no zeros.
    // Expected output: The matrix remains unchanged.
    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    cout << "Original Matrix 2:" << endl;
    printMatrix(matrix2);
    setZeros(matrix2);
    cout << "Modified Matrix 2:" << endl;
    printMatrix(matrix2);

    // Test Case 3: A 3x3 matrix with multiple zeros.
    // Expected output:
    // 0 0 0
    // 0 5 0
    // 0 0 0
    vector<vector<int>> matrix3 = {
        {0, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };
    cout << "Original Matrix 3:" << endl;
    printMatrix(matrix3);
    setZeros(matrix3);
    cout << "Modified Matrix 3:" << endl;
    printMatrix(matrix3);

    return 0;
}

/*
Time Complexity:
This algorithm first scans the entire matrix to track the positions of zeros, which takes O(n * m) time.
For each zero found, it may traverse its entire row and column, leading to a worst-case time complexity of O(n * m * (n + m)).

Space Complexity:
The space complexity is O(n * m) due to the auxiliary matrix "trackZero" used for tracking zeros.
*/
