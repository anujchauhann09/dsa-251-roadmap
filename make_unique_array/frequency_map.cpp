#include <bits/stdc++.h>  
using namespace std;

// Function to find the minimum number of elements to remove from the array
// so that each remaining element appears only once.
int minElementsToRemove(vector<int> &arr) {
    // Get the size of the array
    int n = arr.size();
    
    // Variable to count the number of elements to remove
    int count = 0;
    
    // A map to store the frequency of each element in the array
    map<int, int> arrMap;

    // Traverse the array to count the frequency of each element
    for (int i = 0; i < n; i++) {
        // If the element is not present in the map, add it with frequency 1
        if (!arrMap.count(arr[i])) {
            arrMap[arr[i]] = 1;
        }
        // If the element is already in the map, increment its frequency by 1
        else {
            arrMap[arr[i]]++;
        }
    }

    // Iterate over the map to calculate the number of elements to remove
    for (auto ele : arrMap) {
        // The frequency of the current element
        int frequency = ele.second;
        
        // If the frequency is more than 1, we need to remove the extra occurrences
        // The number of elements to remove is (frequency - 1)
        count += (frequency - 1);
    }

    // Return the total number of elements to remove
    return count;
}

int main() {
    // Test Case 1: Array with duplicates
    vector<int> arr1 = {1, 2, 2, 3, 1, 1};
    cout << "Test Case 1: " << minElementsToRemove(arr1) << endl; // Output should be 3

    // Test Case 2: Array with all unique elements
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Test Case 2: " << minElementsToRemove(arr2) << endl; // Output should be 0

    // Test Case 3: Array with all identical elements
    vector<int> arr3 = {5, 5, 5, 5};
    cout << "Test Case 3: " << minElementsToRemove(arr3) << endl; // Output should be 3

    return 0;
}

/*
Time Complexity:
The time complexity of this approach is O(n), where n is the size of the input array. This is because we iterate through the array once to build the frequency map. For each element in the array, we perform an O(1) operation to insert or update the element in the map. After building the map, we iterate over the map's entries, but since the number of distinct elements in the map is at most n (in the worst case where all elements are unique), the second iteration is O(n) as well. Hence, the overall time complexity remains O(n).

Space Complexity:
The space complexity is O(n), where n is the size of the input array. This is because we are using a map to store the frequency of each distinct element in the array. In the worst case, when all elements are unique, the map will store n distinct elements. Therefore, the space complexity is O(n).
*/