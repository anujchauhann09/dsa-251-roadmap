#include <bits/stdc++.h>  
using namespace std;

char firstNonRepeatingCharacter(string str) {
    // Step 1: Create an unordered map to store the frequency of each character.
    unordered_map<char, int> charFrequency;

    // Step 2: Iterate over the string and count the frequency of each character.
    for (char c : str) {
        charFrequency[c]++; // Increment the frequency of character `c` in the map.
    }

    // Step 3: Iterate over the string again to find the first non-repeating character.
    for (char c : str) {
        if (charFrequency[c] == 1) { 
            // If the character's frequency is 1, it is non-repeating.
            return c; // Return the first non-repeating character.
        }
    }

    // Step 4: If no non-repeating character is found, return the first character of the string.
    // (This is a fallback case and can be adjusted based on specific requirements.)
    return str[0];
}

int main() {
    string str1 = "swiss";
    cout << firstNonRepeatingCharacter(str1) << endl; // Output: 'w'

    string str2 = "aabbcc";
    cout << firstNonRepeatingCharacter(str2) << endl; // Output: 'a'

    string str3 = "abcd";
    cout << firstNonRepeatingCharacter(str3) << endl; // Output: 'a'

    return 0;
}

/*
Time Complexity:
The time complexity of this code is O(n) because the algorithm processes the string twice. In the first loop, it iterates through the string of length n to calculate the frequency of each character and stores it in the unordered map. This operation is efficient, as inserting into or updating an unordered map takes O(1) on average for each character. In the second loop, the algorithm iterates through the string again to check the frequency of each character and identify the first non-repeating character. Since each loop runs sequentially, the overall time complexity is O(n).

Space Complexity:
The space complexity is O(k), where k is the number of distinct characters in the string. This is because the unordered map stores a frequency count for each unique character. In the worst case, if all characters in the string are unique, the map will store n entries (where n is the length of the string). Thus, the space usage depends on the number of unique characters, making the complexity O(k). This ensures efficient use of memory while maintaining constant-time access for frequency lookup.
*/