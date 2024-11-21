#include <iostream>
using namespace std;

// Function to print a matrix in spiral order
void spiralPrint(int **input, int nRows, int nCols) {
    int startRow = 0, endRow = nRows - 1; // Define boundaries for rows
    int startCol = 0, endCol = nCols - 1; // Define boundaries for columns

    // Process the matrix layer by layer
    while (startRow <= endRow && startCol <= endCol) {
        // Print the top row from left to right
        for (int j = startCol; j <= endCol; j++) {
            cout << input[startRow][j] << " ";
        }
        startRow++; // Move the start row down to the next layer

        // Print the right column from top to bottom
        for (int i = startRow; i <= endRow; i++) {
            cout << input[i][endCol] << " ";
        }
        endCol--; // Move the end column left to the next layer

        // Print the bottom row from right to left (if applicable)
        if (startRow <= endRow) { // Ensure there are rows left to process
            for (int j = endCol; j >= startCol; j--) {
                cout << input[endRow][j] << " ";
            }
            endRow--; // Move the end row up to the next layer
        }

        // Print the left column from bottom to top (if applicable)
        if (startCol <= endCol) { // Ensure there are columns left to process
            for (int i = endRow; i >= startRow; i--) {
                cout << input[i][startCol] << " ";
            }
            startCol++; // Move the start column right to the next layer
        }
    }
}

int main() {
    int nRows, nCols;

    // Input the dimensions of the matrix
    cout << "Enter number of rows and columns: ";
    cin >> nRows >> nCols;

    // Dynamically allocate a 2D array
    int **matrix = new int*[nRows];
    for (int i = 0; i < nRows; i++) {
        matrix[i] = new int[nCols];
    }

    // Input matrix elements
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Print the matrix in spiral order
    cout << "Spiral order of the matrix:\n";
    spiralPrint(matrix, nRows, nCols);

    // Deallocate the matrix memory
    for (int i = 0; i < nRows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

/*
Time Complexity:
The time complexity of the spiral traversal of the matrix is O(n × m), where n is the number of rows and m is the number of columns in the matrix. This is because every element in the matrix is visited exactly once during the traversal, and the nested loops ensure all elements are covered in spiral order. 

Space Complexity:
The space complexity is O(1) because the traversal is done in place without using any additional data structures for storage; only a few variables are used to keep track of the boundaries (startRow, endRow, startCol, and endCol). This makes the approach efficient both in terms of time and space.
*/