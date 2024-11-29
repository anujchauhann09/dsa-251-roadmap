#include <bits/stdc++.h>
using namespace std;

// Function to find the first non-repeating character in a string
char firstNonRepeatingCharacter(string str) {
    // Outer loop iterates through each character in the string
    for (int i = 0; i < str.length() - 1; i++) {
        // Skip characters already marked as duplicates ('0')
        if (str[i] == '0') {
            continue; // Continue to the next character if this one is already processed
        }

        int count = 1; // Initialize count for the current character

        // Inner loop checks for duplicates of the current character
        for (int j = i + 1; j < str.length(); j++) {
            if (str[i] == str[j]) { 
                count++; // Increment count if a duplicate is found
                str[j] = '0'; // Mark the duplicate character to avoid processing it again
            }
        }

        // If count remains 1, it means the character is non-repeating
        if (count == 1) {
            return str[i]; // Return the first non-repeating character
        }
    }

    // If no unique character is found, return the first character of the string as a fallback
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
The time complexity of the code is O(n^2) because it uses a nested loop structure. For each character in the string, the outer loop iterates once, and the inner loop scans the remaining characters in the string. This leads to a quadratic time complexity as, for a string of length n, the number of comparisons made is proportional to n×(n−1)/2. This approach is inefficient for large strings. 

Space Complexity:
The space complexity of the code is O(1) because it does not use any additional data structures, and the operations are performed directly on the input string. However, it modifies the input string by marking duplicate characters with '0', which might not be desirable in scenarios where the original string needs to remain unaltered.
*/