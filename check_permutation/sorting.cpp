#include <bits/stdc++.h>
using namespace std;

// Function to check if two strings are anagrams
bool areAnagram(string &str1, string &str2) {
    // Check if lengths of the two strings are different
    if (str1.length() != str2.length()) {
        return false; // If lengths are different, they can't be anagrams
    }

    // Sort both strings in lexicographical order
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Compare the sorted strings character by character
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i]) {
            return false; // If any character doesn't match, they are not anagrams
        }
    }

    return true; // If all characters match, the strings are anagrams
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

    // Test case 3: Anagrams with mixed case
    string str5 = "Triangle";
    string str6 = "Integral";
    // Convert both strings to lowercase for case-insensitive comparison
    transform(str5.begin(), str5.end(), str5.begin(), ::tolower);
    transform(str6.begin(), str6.end(), str6.begin(), ::tolower);
    cout << "Are '" << str5 << "' and '" << str6 << "' anagrams? " 
         << (areAnagram(str5, str6) ? "Yes" : "No") << endl;

    return 0;
}

/*
Time Complexity: 
-Sorting both strings takes O(nlogn), where n is the length of each string. The comparison takes O(n). -Overall complexity-> O(nlogn).

Space Complexity: 
Sorting is done in place, so no extra space is used. Space complexity: O(1).
*/