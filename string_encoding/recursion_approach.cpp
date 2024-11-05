#include <bits/stdc++.h>
using namespace std;

// Helper function to find the encoded message recursively
void findEncodedMessage(string message, string &encodedMessage) {
    // If the input message is empty, return without doing anything
    if (message.empty()) {
        return;
    }

    // Initialize a position counter to track characters in the message
    int currPosi = 0;
    // Start a count of consecutive characters
    int count = 1;

    // Count consecutive occurrences of the current character
    // Move `currPosi` forward as long as the current character matches the next one
    while (currPosi < message.length() - 1 && message[currPosi] == message[currPosi + 1]) {
        count++;
        currPosi++;
    }

    // Append the current character and its count to the encoded message
    encodedMessage += message[0] + to_string(count);

    // Recur with the remaining substring starting after the counted characters
    findEncodedMessage(message.substr(currPosi + 1), encodedMessage);
}

// Main function to encode the message
string encode(string &message) {
    // Initialize an empty encoded message
    string encodedMessage = "";

    // Call the helper function to perform encoding recursively
    findEncodedMessage(message, encodedMessage);
    
    return encodedMessage;
}

/*
Time Complexity:
The time complexity of this code is O(n^2) in the worst case, where n is the length of the input string. This complexity arises because each recursive call to findEncodedMessage creates a new substring using message.substr, which itself has a time complexity of O(n) due to copying characters into a new string. Since there could be up to n recursive calls (one for each character in the input), the repeated creation of substrings results in an overall time complexity of O(n^2).

Space Complexity:
The space complexity of this code is also O(n^2) in the worst case, primarily due to the recursion depth and the creation of new substrings at each recursive step. The recursive stack may go as deep as n calls, and each call generates a substring of length proportional to the remaining characters, leading to additional memory usage. Therefore, both the recursive stack space and the storage of multiple substrings contribute to an overall space complexity of O(n^2).
*/