#include <bits/stdc++.h>
using namespace std;

// Function to check if two strings are anagrams
bool areAnagram(string &str1, string &str2) {
    // Step 1: Check if the lengths of the two strings are equal
    if (str1.length() != str2.length()) {
        return false; // If lengths differ, they cannot be anagrams
    }

    // Step 2: Create a frequency map for characters in str1
    unordered_map<char, int> charsFreq;

    // Step 3: Populate the frequency map for str1
    for (int i = 0; i < str1.length(); i++) {
        if (!charsFreq.count(str1[i])) {
            charsFreq[str1[i]] = 1; // Initialize frequency
        } else {
            charsFreq[str1[i]]++; // Increment frequency
        }
    }

    // Step 4: Adjust the frequency map based on characters in str2
    for (int i = 0; i < str2.length(); i++) {
        if (charsFreq.count(str2[i])) {
            charsFreq[str2[i]]--; // Decrement frequency for matching characters
        }
    }

    // Step 5: Check if all frequencies are zero
    for (auto pair : charsFreq) {
        int frequency = pair.second;

        // If any frequency is not zero, the strings are not anagrams
        if (frequency != 0) {
            return false;
        }
    }

    // Step 6: If all checks pass, the strings are anagrams
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
1. Frequency Map Population and Adjustment
    -Iterates over the strings:- O(n), where n is the length of the strings.
2. Frequency Validation
    -Iterates over the frequency map:- O(k), where k is the unique number of characters.
3. Overall-> O(n+k).

Space Complexity:
-The frequency map requires O(k) space, where k is the number of unique characters in the strings.
-Space complexity-> O(k).
*/