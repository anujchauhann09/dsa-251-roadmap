#include <bits/stdc++.h>
using namespace std;

// Function to find a triplet (x, y, z) in the array such that x = y + z.
vector<int> findTriplets(vector<int> &arr, int n) 
{
    vector<int> ans; // Vector to store the resulting triplet.

    // Step 1: Sort the array in ascending order to facilitate two-pointer technique.
    sort(arr.begin(), arr.end()); // Example: Input: {10, 2, 6, 5, 5} → Sorted: {2, 5, 5, 6, 10}

    // Step 2: Traverse the array from the last element (potential x) to the start.
    for (int i = n - 1; i >= 0; i--) 
    {
        int j = 0;         // Pointer to the beginning of the array.
        int k = i - 1;     // Pointer to the element just before the current element.

        // Step 3: Use the two-pointer technique to find two numbers that sum to arr[i].
        while (j < k) 
        {
            // Case 1: Check if arr[i] is equal to the sum of arr[j] and arr[k].
            if (arr[i] == arr[j] + arr[k]) 
            {
                ans.push_back(arr[i]); // Add x to the answer.
                ans.push_back(arr[j]); // Add y to the answer.
                ans.push_back(arr[k]); // Add z to the answer.
                return ans; // Return the triplet as we only need one.
            }
            // Case 2: If arr[i] is greater than the sum, increment `j` to increase the sum.
            else if (arr[i] > arr[j] + arr[k]) 
            {
                j++;
            }
            // Case 3: If arr[i] is smaller than the sum, decrement `k` to decrease the sum.
            else 
            {
                k--;
            }
        }
    }

    // If no triplet is found, return an empty vector.
    return ans;
}

// Main function to test the code.
int main() 
{
    // Test Case 1: Array with a valid triplet.
    vector<int> arr1 = {10, 2, 6, 5, 5};
    int n1 = arr1.size();
    vector<int> result1 = findTriplets(arr1, n1);
    cout << "Test Case 1: ";
    for (int val : result1) cout << val << " ";
    cout << endl;

    // Test Case 2: Array without any valid triplet.
    vector<int> arr2 = {1, 2, 3, 8, 13};
    int n2 = arr2.size();
    vector<int> result2 = findTriplets(arr2, n2);
    cout << "Test Case 2: ";
    if (result2.empty()) cout << "No triplet found";
    else for (int val : result2) cout << val << " ";
    cout << endl;

    // Test Case 3: Array with multiple valid triplets (only one triplet will be returned).
    vector<int> arr3 = {4, 7, 1, 11, 3};
    int n3 = arr3.size();
    vector<int> result3 = findTriplets(arr3, n3);
    cout << "Test Case 3: ";
    for (int val : result3) cout << val << " ";
    cout << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of the sorting and two-pointer approach is dominated by the initial sorting step, which takes (nlogn), where n is the size of the array. After sorting, the two-pointer traversal for each element runs in O(n). Since the two-pointer process is performed for each element in the array (in the worst case), the overall complexity of this approach becomes O(nlogn+n^2). However, the O(n^2) term dominates for large n, making the effective time complexity O(n^2).

Space Complexity:
The space complexity of this approach is O(1) because no additional data structures are used apart from a constant number of variables for iteration and storing results. The sorting step modifies the input array in place, so no extra space is required for the sorting process. Hence, the space usage remains constant regardless of the input size.
*/