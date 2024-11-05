#include <bits/stdc++.h> 

// Function to encode the input string by counting consecutive characters
string encode(string &message)
{
    // Get the length of the input message
    int length = message.length();
    
    // Initialize a count for consecutive characters
    int count = 1;

    // Initialize an empty string to store the encoded message
    string encodedMessage = "";

    // Iterate through the message until the second-to-last character
    for(int i = 0; i < length-1; i++) {
        // Check if the current character is different from the next character
        if(message[i] != message[i+1]) {
            // If they are different, add the current character to the encoded message
            encodedMessage += message[i];
            // Add the count of consecutive characters to the encoded message
            encodedMessage += to_string(count);
            // Reset count for the next character sequence
            count = 1;

            continue; // Continue to the next iteration
        }

        // If the current character is the same as the next one, increment the count
        count++;
    }

    // After exiting the loop, add the last character and its count to the encoded message
    encodedMessage += message[length - 1];
    encodedMessage += to_string(count);

    // Return the final encoded message
    return encodedMessage;
}

/*
Time Complexity:
The time complexity of the encode function is O(n), where n is the length of the input string. This is because the function iterates through the string exactly once, performing a constant amount of work for each character, which includes comparing characters and appending to the output string. Thus, the overall time taken grows linearly with the size of the input.

Space Complexity:
The space complexity is O(n) in the worst case as well. This is due to the additional space required for the encodedMessage string that is being constructed. In the scenario where the input string consists of all unique characters, the encoded message could be nearly as long as the input, leading to space usage that scales linearly with the input size. Therefore, both time and space complexities are linear in relation to the length of the input string.
*/