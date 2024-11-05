#include <bits/stdc++.h>
using namespace std;

string encode(string &message) {
    int length = message.length();        // Get the length of the input string.
    bool flag = false;                    // Flag to track if a character has been added to the encoded message.
    char prevChar = '\0';                 // Stores the previous character for encoding purposes.
    map<char, int> charMap;               // Map to store the frequency of each character encountered.
    string encodedMessage = "";           // The final encoded string to be returned.

    // Iterate over each character in the input string
    for (int i = 0; i < length; i++) {
        // If the current character is not yet in the map, initialize its count to 1.
        if (!charMap.count(message[i])) {
            charMap[message[i]] = 1;      // Initialize character's frequency in the map.

            // If a previous character frequency is stored, add it to the encoded message.
            if (flag) {
                encodedMessage += prevChar;               // Add previous character to encoded message.
                encodedMessage += to_string(charMap[prevChar]); // Append its frequency.
                charMap.erase(prevChar);                  // Clear the previous character's frequency from the map.
            }

            prevChar = message[i];        // Update `prevChar` to the current character.
            flag = true;                  // Indicate that at least one character has been encoded.
            continue;                     // Continue to the next iteration.
        }

        // If the character is already in the map, increment its count.
        charMap[message[i]]++;
    }

    // After the loop, add the final character and its frequency to the encoded message.
    encodedMessage += prevChar;                   // Add the last character to the encoded message.
    encodedMessage += to_string(charMap[prevChar]); // Append the last character's frequency.

    return encodedMessage;                // Return the final encoded string.
}

/*
Time Complexity:
The time complexity of this code is O(n), where n is the length of the input string. This is because we iterate over the string once, counting characters and updating the encoded message as we go. Operations on the map, like inserting and retrieving character frequencies, generally take constant time on average, so they do not add significant complexity.

Space Complexity:
The space complexity is O(k), where k is the number of distinct characters in the input string. This is due to the map that temporarily stores the frequency of each unique character, and also the encoded message string, which can be up to twice the length of the original string in the worst case (since each character is followed by its count). Thus, both time and space complexities are efficient and scale well with the length and diversity of the input string.
*/