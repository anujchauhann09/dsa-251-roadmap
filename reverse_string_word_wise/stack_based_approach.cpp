#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Function to reverse the words in a string
string reverseStringWordWise(string input) {
    // Stack to hold the words
    stack<string> words;  
    string word; // Temporary variable to construct each word

    // Iterate through each character in the input string
    for(char c: input) {
        // Check if the current character is a space
        if(c == ' ') {
            // If we have constructed a word, push it onto the stack
            if(!word.empty()) {
                words.push(word);
                word.clear(); // Clear the word variable for the next word
            }
        }
        else {
            // If it's not a space, add the character to the current word
            word += c;
        }
    }

    // After the loop, check if there's a remaining word to push onto the stack
    if(!word.empty()) {
        words.push(word);
        word.clear(); // Clear the word variable for consistency
    }

    string result; // String to store the final reversed result

    // Pop words from the stack to build the result in reverse order
    while(!words.empty()) {
        result += words.top(); // Add the top word from the stack to the result
        words.pop(); // Remove the word from the stack

        // Add a space after the word if there are more words left in the stack
        if(!words.empty()) {
            result += " ";
        }
    }

    // Return the final reversed string with words in the correct order
    return result;
}

// Main function to execute the program
int main() {
    string s; // String to hold user input
    getline(cin, s); // Read a line of input from the user
    string ans = reverseStringWordWise(s); // Call the function to reverse words
    cout << ans << endl; // Print the reversed string
}

/*
Time Complexity:
The time complexity of the reverseStringWordWise function is O(n), where n is the length of the input string. This is because the function traverses the string once to split it into words, and then it processes those words in the stack to form the final output. Each character is visited a constant number of times, resulting in linear time complexity.

Space Complexity:
The space complexity is also O(n). This is due to the use of the stack to store the words, which in the worst case could hold all the words if there are no spaces in the input string. Additionally, the output string, which is constructed to hold the reversed words, also contributes to the space usage. Thus, the overall space complexity remains linear, as it scales with the size of the input. In conclusion, both the time and space complexities of this function are O(n), making it efficient for handling strings of varying lengths.
*/