#include <bits/stdc++.h>
using namespace std;

// Function to set zeros in the matrix. If an element in the matrix is 0,
// then its entire row and column are set to 0. This implementation uses two
// tracking arrays to record which rows and columns originally contain a 0.
void setZeros(vector<vector<int>> &matrix) {
    int n = matrix.size();       // Number of rows in the matrix
    int m = matrix[0].size();    // Number of columns in the matrix

    // Tracking arrays to mark rows and columns that have at least one zero.
    // Initialized with -1; will be set to 0 if a zero is found.
    vector<int> trackRowZero(n, -1);
    vector<int> trackColZero(m, -1);

    // First pass: Identify the rows and columns that contain a zero.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                trackRowZero[i] = 0;
                trackColZero[j] = 0;
            }
        }
    }

    // Second pass: For each cell that is in a row and column marked with a zero,
    // set its entire row and column to zero.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (trackRowZero[i] == 0 && trackColZero[j] == 0) {
                // Set all elements in column j (above and below current cell) to zero.
                for (int k = i - 1; k >= 0; k--) {
                    matrix[k][j] = 0;
                }
                for (int k = i + 1; k < n; k++) {
                    matrix[k][j] = 0;
                }
                // Set all elements in row i (left and right of current cell) to zero.
                for (int k = j - 1; k >= 0; k--) {
                    matrix[i][k] = 0;
                }
                for (int k = j + 1; k < m; k++) {
                    matrix[i][k] = 0;
                }
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
    // Test Case 1: 3x3 matrix with a single zero in the center.
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

    // Test Case 2: 4x4 matrix with no zeros (matrix remains unchanged).
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

    // Test Case 3: 3x3 matrix with zeros in different rows and columns.
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
In the worst case, the algorithm can run in O(n*m*(n+m)) time, because for each cell that qualifies (having both its row and column marked), we traverse its entire row and column.

Space Complexity: 
O(n + m), due to the two tracking arrays used for rows and columns.
*/
