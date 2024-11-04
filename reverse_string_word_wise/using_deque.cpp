#include <iostream>
#include <bits/stdc++.h> // Include necessary libraries
using namespace std;

// Function to reverse the words in a given string
string reverseStringWordWise(string input)
{
    deque<string> words; // Using a deque to store words in reverse order
    string word; // Temporary string to store each word while traversing the input

    // Traverse each character in the input string
    for (char c : input) {
        if (c == ' ') { // When encountering a space, a word boundary is found
            if (!word.empty()) { // If word is not empty, it is a valid word
                words.push_front(word); // Insert the word at the front of the deque to reverse order
                word.clear(); // Clear the word for the next word to be constructed
            }
        } else {
            word += c; // If character is not a space, add it to the current word
        }
    }
    
    // Add the last word if the string does not end with a space
    if (!word.empty()) {
        words.push_front(word); // Insert the last word at the front
    }
    
    // Construct the final reversed string from the deque
    string result; // To store the reversed word-wise result
    
    while (!words.empty()) { // Continue until all words are added to the result
        result += words.front(); // Append the word at the front of the deque
        words.pop_front(); // Remove the word from the deque

        if (!words.empty()) { // Add a space after each word, except the last one
            result += " ";
        }
    }
    
    return result; // Return the final reversed string
}

int main()
{
    string s;
    getline(cin, s); // Read a line of input
    string ans = reverseStringWordWise(s); // Get the reversed word-wise string
    cout << ans << endl; // Output the result
}

/*
Time Complexity:
The time complexity of the provided code is O(n), where n represents the length of the input string. This complexity arises from the need to traverse the string twice: once to split the input into individual words and store them in a deque, and again to concatenate those words into the final output string. Since each character in the string is processed a limited number of times—specifically, each character is visited once for word extraction and once for result construction—the overall time taken grows linearly with the size of the input.

Space Complexity:
The space complexity is O(m), where m is the number of words in the input string. This complexity is primarily due to the storage requirements for the deque, which holds each word extracted from the input. The space used for the output string can also contribute to the space complexity, but it is not counted separately since the final output is derived from the words stored in the deque. In summary, the algorithm efficiently uses linear time and space relative to the number of characters and words in the input string, making it suitable for reversing words in a string.
*/