#include <iostream>
using namespace std;

// Function to reverse the words in a given string without reversing individual characters
string reverseStringWordWise(string input)
{
    string output = "";         // Holds the final reversed word order result
    string tempOutput = "";      // Temporarily stores each word
    int length = input.size();   // Length of the input string

    // Loop through the entire input string, including the last character (hence i <= length)
    for(int i = 0; i <= length; i++) {
        // Check if we encounter a space or reach the end of the string
        if(input[i] == ' ' || i == length) {
            // Prepend the current word (tempOutput) to the output string
            output = tempOutput + output;
            
            // Add a space at the beginning of the output string to separate words
            output = ' ' + output;
            
            // Clear tempOutput to capture the next word
            tempOutput = "";

            // Continue to the next character in the loop
            continue;
        }
        
        // Add the current character to tempOutput to build the current word
        tempOutput += input[i];
    }

    // Return the final output string, removing the first space character added at the beginning
    return output.substr(1);
}

int main()
{
    string s;
    // Read a line of input from the user
    getline(cin, s);

    // Call the reverseStringWordWise function and store the result
    string ans = reverseStringWordWise(s);

    // Output the result
    cout << ans << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of this code is O(n), where n is the length of the input string. This is because we iterate through the string once to identify each word, storing it temporarily, and then prepend it to the output string. The string concatenation for the reversed word order involves prepending each word to the beginning of the output string, which in this case has an average complexity of O(n) due to repeated additions of smaller strings to form the full output. Thus, the total complexity remains linear with respect to the number of characters in the input. 

Space Complexity:
The space complexity is also O(n) because we store each character of the input string in both output and tempOutput, resulting in a maximum space requirement of roughly twice the input size, which simplifies to O(n).
*/