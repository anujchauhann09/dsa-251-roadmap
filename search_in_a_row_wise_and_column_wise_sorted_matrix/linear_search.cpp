#include <bits/stdc++.h>
using namespace std;

pair<int, int> search(vector<vector<int>> matrix, int x)
{
    int n = matrix.size();  // Number of rows (and columns, since the matrix is square)

    // Loop over each row.
    for (int i = 0; i < n; i++) {
        // Loop over each column in the current row.
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == x) {
                return {i, j};  // Target found; return its coordinates.
            }
        }
    }
    return {-1, -1};  // Target not found; return (-1, -1).
}

int main() {
    // Test Case 1: The target value exists in the matrix.
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int target1 = 5;
    pair<int, int> result1 = search(matrix1, target1);
    if(result1.first != -1)
        cout << "Test Case 1: Found " << target1 << " at (" 
             << result1.first << ", " << result1.second << ")\n";
    else
        cout << "Test Case 1: " << target1 << " not found in the matrix.\n";

    // Test Case 2: The target value does not exist in the matrix.
    vector<vector<int>> matrix2 = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };
    int target2 = 35;
    pair<int, int> result2 = search(matrix2, target2);
    if(result2.first != -1)
        cout << "Test Case 2: Found " << target2 << " at (" 
             << result2.first << ", " << result2.second << ")\n";
    else
        cout << "Test Case 2: " << target2 << " not found in the matrix.\n";

    // Test Case 3: The target value is at the beginning of the matrix.
    vector<vector<int>> matrix3 = {
        {11, 12, 13},
        {14, 15, 16},
        {17, 18, 19}
    };
    int target3 = 11;
    pair<int, int> result3 = search(matrix3, target3);
    if(result3.first != -1)
        cout << "Test Case 3: Found " << target3 << " at (" 
             << result3.first << ", " << result3.second << ")\n";
    else
        cout << "Test Case 3: " << target3 << " not found in the matrix.\n";

    return 0;
}

/*
Time Complexity:
The search function has a time complexity of O(n²) because it might check every element in an n x n matrix. 

Space Complexity:
The space complexity is O(1) since only a constant amount of extra memory is used.
*/