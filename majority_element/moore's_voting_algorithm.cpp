#include <iostream>
#include <vector>
using namespace std;

int findMajorityElement(const vector<int>& arr) {
    int count = 0;
    int candidate = -1;

    // Phase 1: Find the candidate
    for(int i = 0; i < arr.size(); i++) {
        if(count == 0) {
            candidate = arr[i];
        }
        count += (arr[i] == candidate) ? 1 : -1;
    }

    // Phase 2: Verify the candidate (optional)
    int occurrences = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == candidate) {
            occurrences++;
        }
    }
    if(occurrences > arr.size() / 2) {
        return candidate; // Majority element
    }
    
    return -1; // No majority element
}

int main() {
    vector<int> arr1 = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    vector<int> arr2 = {1, 2, 3, 4, 5};
    
    cout << "Majority element in arr1: " << findMajorityElement(arr1) << endl;
    cout << "Majority element in arr2: " << findMajorityElement(arr2) << endl;
    
    return 0;
}

/*
Time Complexity: 
O(n) for both the phases combined, where n is the size of the array.

Space Complexity: 
O(1) because we only use a few variables to store the candidate and count.
*/