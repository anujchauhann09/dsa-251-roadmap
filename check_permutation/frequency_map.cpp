#include <bits/stdc++.h>
using namespace std;

// Function to check if two strings are anagrams
bool areAnagram(string &str1, string &str2) {
    // Step 1: Check if the lengths of the two strings are equal
    if (str1.length() != str2.length()) {
        return false; // If lengths differ, they cannot be anagrams
    }

    // Step 2: Create frequency maps for both strings
    unordered_map<char, int> charsFreq1; // Frequency map for str1
    unordered_map<char, int> charsFreq2; // Frequency map for str2

    // Step 3: Populate frequency maps for both strings
    for (int i = 0; i < str1.length(); i++) {
        // For str1
        if (!charsFreq1.count(str1[i])) {
            charsFreq1[str1[i]] = 1; // Initialize frequency
        } else {
            charsFreq1[str1[i]]++; // Increment frequency
        }

        // For str2
        if (!charsFreq2.count(str2[i])) {
            charsFreq2[str2[i]] = 1; // Initialize frequency
        } else {
            charsFreq2[str2[i]]++; // Increment frequency
        }
    }

    // Step 4: Compare the sizes of the frequency maps
    if (charsFreq1.size() != charsFreq2.size()) {
        return false; // If sizes differ, they cannot be anagrams
    }

    // Step 5: Compare the frequencies of each character
    for (auto pair : charsFreq1) {
        char ch = pair.first; // Character from str1's frequency map

        // If the frequency of the character does not match in both maps, return false
        if (charsFreq1[ch] != charsFreq2[ch]) {
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
1. Populating Frequency Maps
    -Iterates over both strings O(n).
2. Comparing Frequencies
    -Iterates over the frequency map-> O(k), where k is the unique number of characters.
3. Overall-> O(n+k).

Space Complexity: 
-Frequency maps store character frequencies-> O(k), where k is the unique number of characters.
-Space complexity-> O(k).
*/