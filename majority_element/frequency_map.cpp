#include <bits/stdc++.h> 
using namespace std;

int findMajorityElement(int arr[], int n) {
    // Calculate the threshold limit: n / 2
    int limit = floor(n / 2);
    
    // Initialize answer as -1 (in case no majority element is found)
    int answer = -1;
    
    // Create a frequency map to store the frequency of each element
    map<int, int> freqMap;

    // Count the frequency of each element in the array
    for(int i = 0; i < n; i++) {
        if(!freqMap.count(arr[i])) {  // If the element is not in the map, add it with frequency 1
            freqMap[arr[i]] = 1;
        }
        else {  // If the element is already in the map, increment its frequency
            freqMap[arr[i]]++;
        }
    }

    // Loop through the map to find the element with a frequency greater than the limit
    for(auto pair: freqMap) {
        int frequency = pair.second;

        // If the frequency of the element is greater than the limit, it is the majority element
        if(frequency > limit) {
            answer = pair.first;
        }
    }

    // Return the majority element, or -1 if no majority element was found
    return answer;
}

int main() {
    // Test case 1: Majority element exists
    int arr1[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Majority Element in arr1: " << findMajorityElement(arr1, n1) << endl; // Expected: 4

    // Test case 2: Majority element exists
    int arr2[] = {1, 1, 1, 3, 3, 2, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Majority Element in arr2: " << findMajorityElement(arr2, n2) << endl; // Expected: 1

    // Test case 3: No majority element exists
    int arr3[] = {1, 2, 3, 4, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Majority Element in arr3: " << findMajorityElement(arr3, n3) << endl; // Expected: -1

    return 0;
}

/*
Time Complexity:
The time complexity of this solution is O(n) because we are iterating over the array once to build the frequency map, and then iterating over the map, which has at most n elements (in the worst case, where all elements are unique).

Space Complexity:
The space complexity is O(n) due to the space required for the frequency map, where at most n different elements can be stored.
*/