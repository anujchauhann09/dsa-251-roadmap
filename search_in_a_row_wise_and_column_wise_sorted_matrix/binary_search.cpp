#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> binarySearch(vector<vector<int>> &matrix, int start, int end, int i, int x) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (matrix[i][mid] == x) {
            return {i, mid};  // Target found at position (i, mid).
        } 
        else if (matrix[i][mid] > x) {
            end = mid - 1;    // Target must be in the left half.
        } 
        else {
            start = mid + 1;  // Target must be in the right half.
        }
    }
    return {-1, -1};  // Target not found in this row.
}


pair<int, int> search(vector<vector<int>> matrix, int x) {
    int n = matrix.size();  // Number of rows (and columns, since the matrix is square)
    pair<int, int> answer = {-1, -1};

    // Loop over each row and perform binary search in that row.
    for (int i = 0; i < n; i++) {
        answer = binarySearch(matrix, 0, n - 1, i, x);
        if (answer.first != -1 && answer.second != -1) {
            return answer;  // Target found; return its coordinates.
        }
    }
    return answer;  // Target not found in any row.
}

int main() {
    // Test Case 1: Target exists in the matrix.
    vector<vector<int>> matrix1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50},
        {60, 70, 80, 90}
    };
    int target1 = 16;
    pair<int, int> result1 = search(matrix1, target1);
    if (result1.first != -1)
        cout << "Test Case 1: Found " << target1 << " at position (" 
             << result1.first << ", " << result1.second << ")\n";
    else
        cout << "Test Case 1: " << target1 << " not found in the matrix.\n";

    // Test Case 2: Target does not exist in the matrix.
    vector<vector<int>> matrix2 = {
        {2, 4, 6, 8},
        {9, 10, 12, 14},
        {15, 17, 19, 21},
        {22, 24, 26, 28}
    };
    int target2 = 11;
    pair<int, int> result2 = search(matrix2, target2);
    if (result2.first != -1)
        cout << "Test Case 2: Found " << target2 << " at position (" 
             << result2.first << ", " << result2.second << ")\n";
    else
        cout << "Test Case 2: " << target2 << " not found in the matrix.\n";

    // Test Case 3: Another matrix where the target exists.
    vector<vector<int>> matrix3 = {
        {5, 10, 15},
        {20, 25, 30},
        {35, 40, 45}
    };
    int target3 = 40;
    pair<int, int> result3 = search(matrix3, target3);
    if (result3.first != -1)
        cout << "Test Case 3: Found " << target3 << " at position (" 
             << result3.first << ", " << result3.second << ")\n";
    else
        cout << "Test Case 3: " << target3 << " not found in the matrix.\n";

    return 0;
}

/*
Time Complexity:
The overall time complexity is O(n log n), where n is the number of rows (or columns) in the square matrix.
This is because we perform a binary search (which takes O(log n) time) for each of the n rows.

Space Complexity:
The space complexity is O(1) auxiliary space, as the algorithm uses a constant amount of extra memory.
*/
