#include <bits/stdc++.h>
using namespace std;

// Function to check if two strings are anagrams
bool areAnagram(string &str1, string &str2) {
    // Step 1: Check if lengths of the two strings are equal
    if (str1.length() != str2.length()) {
        return false; // If lengths are different, they can't be anagrams
    }

    // Step 2: Iterate through each character in the first string
    for (int i = 0; i < str1.length(); i++) {
        bool isPresent = false; // Flag to check if the character is present in str2

        // Step 3: Check if the current character from str1 exists in str2
        for (int j = 0; j < str2.length(); j++) {
            if (str1[i] == str2[j]) { 
                isPresent = true; // Character found in str2
                break; // No need to check further for this character
            }
        }

        // Step 4: If the character is not found in str2, the strings are not anagrams
        if (!isPresent) {
            return false;
        }
    }

    // Step 5: If all characters of str1 are found in str2, they are anagrams
    return true;
}

int main() {
    // Test case 1: Anagram strings
    string str1 = "listen";
    string str2 = "silent";
    cout << "Are '" << str1 << "' and '" << str2 << "' anagrams? " 
         << (areAnagram(str1, str2) ? "Yes" : "No") << endl;

    // Test case 2: Not anagrams
    string str3 = "hello";
    string str4 = "world";
    cout << "Are '" << str3 << "' and '" << str4 << "' anagrams? " 
         << (areAnagram(str3, str4) ? "Yes" : "No") << endl;

    // Test case 3: Anagrams with repeated characters
    string str5 = "aabbcc";
    string str6 = "ccbbaa";
    cout << "Are '" << str5 << "' and '" << str6 << "' anagrams? " 
         << (areAnagram(str5, str6) ? "Yes" : "No") << endl;

    return 0;
}

/*
Time Complexity:
-Outer loop runs for n iterations (length of str1).
-Inner loop also runs for n iterations (length of str2).
-Overall time complexity-> O(n^2).

Space Complexity:
-No additional data structures are used.
-Space complexity-> O(1).
*/