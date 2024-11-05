#include <bits/stdc++.h>
using namespace std;

string encode(string &message)
{
    int length = message.length();  // Length of the input string
    int i = 0, j = 0;               // Pointers to track sequence start and end
    int count = 0;                  // Counter for consecutive character occurrences
    string encodedMessage = "";     // String to hold the final encoded message

    // Main loop to iterate through the string
    while(j < length) {
        // When characters at i and j don't match, record the encoded segment
        if(message[i] != message[j]) {
            // Append character at i and the count of its occurrences
            encodedMessage = encodedMessage + message[i] + to_string(count);
            
            // Move i to the current j position, starting a new sequence
            i = j;
            count = 0;  // Reset count for the new character sequence

            continue;  // Continue to evaluate with updated i and j
        }
        
        // If characters at i and j are the same, increase j and count
        j++;
        count++;
    }

    // Append the final sequence once the loop finishes
    encodedMessage = encodedMessage + message[i] + to_string(count);

    return encodedMessage;
}

/*
Time Complexity:
The time complexity of this code is linear, or O(n), where n represents the length of the input string. This is because each character in the input string is processed only once as the code iterates over the string with pointers i and j, which only move forward. Hence, the function completes in a single pass through the string without any nested loops, leading to efficient performance even for larger inputs.

Space Complexity:
The space complexity of the code is also linear, or O(n), because of the encodedMessage string, which stores the encoded result. In the worst case, each character in the original string could be followed by a count in the result (like a1b1c1... for a string of unique characters), leading to a final result string that is at most twice the length of the original string. Thus, the space used is proportional to the size of the input, resulting in a linear space complexity.
*/