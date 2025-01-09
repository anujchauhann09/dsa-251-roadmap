#include <bits/stdc++.h>  
using namespace std;

// Function to rotate each row of a 2D matrix 'k' times to the right and return the flattened matrix
vector<int> rotateMatRight(vector<vector<int>> mat, int n, int m, int k) {
    vector<int> answer; // To store the resulting flattened matrix
    
    // Reduce k to an effective number of rotations
    // Since rotating m times results in the same matrix, we take k % m
    k = k % m;

    // Perform the right rotation for each row 'k' times
    for (int shift = 0; shift < k; shift++) { // Repeat the rotation 'k' times
        for (int i = 0; i < n; i++) {         // Iterate through each row
            // Perform a single right rotation on the current row
            for (int j = m - 1; j > 0; j--) { 
                swap(mat[i][j], mat[i][j - 1]); // Swap elements to shift right
            }
        }
    }

    // Flatten the matrix into a 1D vector after all rotations
    for (int i = 0; i < n; i++) {             // Iterate through rows
        for (int j = 0; j < m; j++) {         // Iterate through columns
            answer.push_back(mat[i][j]);      // Add each element to the answer vector
        }
    }

    return answer; // Return the flattened rotated matrix
}

int main() {
    // Test Case 1: Small matrix with simple rotation
    vector<vector<int>> mat1 = {{1, 2, 3}, {4, 5, 6}};
    int n1 = 2, m1 = 3, k1 = 1;
    vector<int> result1 = rotateMatRight(mat1, n1, m1, k1);
    cout << "Test Case 1 Result: ";
    for (int num : result1) cout << num << " ";
    cout << endl;

    // Test Case 2: No rotation (k = 0)
    vector<vector<int>> mat2 = {{7, 8, 9}, {10, 11, 12}};
    int n2 = 2, m2 = 3, k2 = 0;
    vector<int> result2 = rotateMatRight(mat2, n2, m2, k2);
    cout << "Test Case 2 Result: ";
    for (int num : result2) cout << num << " ";
    cout << endl;

    // Test Case 3: Full rotation (k = m)
    vector<vector<int>> mat3 = {{13, 14}, {15, 16}};
    int n3 = 2, m3 = 2, k3 = 2;
    vector<int> result3 = rotateMatRight(mat3, n3, m3, k3);
    cout << "Test Case 3 Result: ";
    for (int num : result3) cout << num << " ";
    cout << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of this function is O(k×n×m), where k is the number of right rotations, n is the number of rows, and m is the number of columns in the matrix. For each rotation, we iterate through all rows (n) and for each row, we iterate through the columns (m) to perform the swaps. After the rotations, the function also flattens the matrix into a 1D vector, which takes O(n×m). Therefore, the overall complexity remains O(k×n×m).

Space Complexity: 
The space complexity of this function is O(n×m), which accounts for storing the input matrix and the output vector. No additional data structures or space are used for processing the rotations, as the swaps are performed in place within the input matrix. Thus, the total space required is proportional to the size of the matrix.
*/