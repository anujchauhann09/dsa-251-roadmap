#include <bits/stdc++.h>
using namespace std;

// Function to find the first triplet (x, y, z) in the array such that x + y = z or similar relationships.
vector<int> findTriplets(vector<int> &arr, int n) 
{
    // If the array size is less than 3, no triplet can exist. Return -1.
    if (n <= 3) {
        return {-1};
    }

    vector<int> answer; // To store the result triplet.
    int i, j, k;        // Variables to iterate through the array.

    // Step 1: Iterate over all possible combinations of triplets.
    for (i = 0; i < n - 2; i++) {
        bool isTriplet = false; // Flag to indicate if a valid triplet is found.

        for (j = i + 1; j < n - 1; j++) {

            for (k = j + 1; k < n; k++) {
                // Check if any pair of numbers sums up to the third number.
                if (arr[i] + arr[j] == arr[k]) {
                    isTriplet = true; // Triplet found.
                    break;                    
                }
                else if (arr[i] + arr[k] == arr[j]) {
                    isTriplet = true; // Triplet found.
                    break;
                }
                else if (arr[j] + arr[k] == arr[i]) {
                    isTriplet = true; // Triplet found.
                    break;
                }
            }

            // If a triplet is found, store it in the result vector and exit the inner loop.
            if (isTriplet) {
                answer.push_back(arr[i]);
                answer.push_back(arr[j]);
                answer.push_back(arr[k]);
                break;
            }
        }

        // If a triplet is found, exit the outer loop.
        if (isTriplet) {
            break;
        }
    }

    return answer; // Return the result vector containing the triplet or empty if no triplet is found.
}

// Main function to test the code.
int main() 
{
    // Test Case 1: Array with a valid triplet.
    vector<int> arr1 = {1, 2, 3, 5, 8};
    int n1 = arr1.size();
    vector<int> result1 = findTriplets(arr1, n1);
    cout << "Test Case 1: ";
    if (result1.size() > 1) {
        for (int val : result1) cout << val << " ";
    } else {
        cout << "No triplet found";
    }
    cout << endl;

    // Test Case 2: Array without a valid triplet.
    vector<int> arr2 = {4, 7, 10, 15};
    int n2 = arr2.size();
    vector<int> result2 = findTriplets(arr2, n2);
    cout << "Test Case 2: ";
    if (result2.size() > 1) {
        for (int val : result2) cout << val << " ";
    } else {
        cout << "No triplet found";
    }
    cout << endl;

    // Test Case 3: Array with multiple triplets (only the first valid one is returned).
    vector<int> arr3 = {2, 4, 6, 10, 16};
    int n3 = arr3.size();
    vector<int> result3 = findTriplets(arr3, n3);
    cout << "Test Case 3: ";
    if (result3.size() > 1) {
        for (int val : result3) cout << val << " ";
    } else {
        cout << "No triplet found";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity: 
The time complexity of this approach is determined by the three nested loops. The outermost loop iterates over the array from the first element to the third-last element, the middle loop iterates over the remaining elements after the current element of the outer loop, and the innermost loop iterates over the elements following the current element of the middle loop. As a result, the time complexity is O(n^3), where n is the size of the array, because all possible triplets are being checked exhaustively. This cubic growth makes the approach inefficient for larger arrays.

Space Complexity:
The space complexity of the approach is O(1) because no additional space is used apart from a small number of variables (e.g., answer, i, j, k) and the result vector that stores the triplet if found. The result vector's size is constant (at most three integers), so it does not contribute to a growing space requirement based on the input size. Thus, the algorithm operates with constant additional space.
*/