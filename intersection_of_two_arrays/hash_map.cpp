#include <bits/stdc++.h>
using namespace std;

// Function to find the intersection of two arrays
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> result; // Vector to store the intersection elements
    unordered_map<int, int> mp; // Unordered map to store the frequency of elements in arr1

    // Count the occurrences of each element in arr1
    for (int i = 0; i < n; i++) {
        mp[arr1[i]]++; // Increment the frequency for each element
    }

    // Traverse through arr2 to find common elements
    for (int i = 0; i < m; i++) {
        if (mp.count(arr2[i]) != 0) { // If the current element of arr2 exists in the map
            result.push_back(arr2[i]); // Add it to the result vector
            mp[arr2[i]]--; // Decrease its frequency in the map
        }

        // If the frequency of the element becomes zero, remove it from the map
        if (mp[arr2[i]] == 0) {
            mp.erase(arr2[i]); // Erase the element from the map
        }
    }

    return result; // Return the resulting intersection array
}

int main() {
    // Test case 1
    vector<int> arr1 = {1, 2, 2, 3, 4};
    vector<int> arr2 = {2, 3, 5};
    vector<int> result = findArrayIntersection(arr1, arr1.size(), arr2, arr2.size());
    cout << "Intersection (Test Case 1): ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> arr3 = {7, 8, 9, 10};
    vector<int> arr4 = {10, 8, 11};
    result = findArrayIntersection(arr3, arr3.size(), arr4, arr4.size());
    cout << "Intersection (Test Case 2): ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 3
    vector<int> arr5 = {1, 2, 3, 4, 5};
    vector<int> arr6 = {6, 7, 8};
    result = findArrayIntersection(arr5, arr5.size(), arr6, arr6.size());
    cout << "Intersection (Test Case 3): ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of the findArrayIntersection function is O(n + m), where n is the size of the first array and m is the size of the second array. This is because we iterate through the first array once to populate the frequency map, which takes O(n), and then we traverse the second array to check for matches and update the frequency map, which takes O(m). Operations like checking for an element in the unordered_map, updating the frequency, and erasing an element are O(1) on average, due to the hash table implementation.

Space Complexity:
The space complexity is O(n), as we use an unordered_map to store the frequency of elements from the first array. The size of the map depends on the number of distinct elements in the first array, which in the worst case could be n. The result vector also uses space, but its size is bounded by the smaller of n and m, making the dominant term O(n). Hence, the overall space complexity remains O(n).
*/