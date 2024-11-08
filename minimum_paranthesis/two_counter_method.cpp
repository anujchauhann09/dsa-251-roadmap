#include <bits/stdc++.h>  
using namespace std;

// Function to calculate the minimum number of parentheses required
// to make the input `pattern` string balanced
int minimumParentheses(string pattern) {
    // Get the length of the input string `pattern`
    int length = pattern.length();
    
    // `openCount` keeps track of unpaired opening '(' parentheses
    int openCount = 0;

    // `closeCount` counts unpaired closing ')' parentheses
    int closeCount = 0;

    // Iterate through each character in the `pattern` string
    for(int i = 0; i < length; i++) {
        // Check if the current character is an opening parenthesis '('
        if(pattern[i] == '(') {
            // Increment `openCount` as we have an unmatched '('
            openCount++;
        }
        else { // The current character is a closing parenthesis ')'
            // If there's an unmatched opening '(', we can balance it
            if(openCount > 0) {
                // Decrement `openCount` to indicate a match with ')'
                openCount--;
                continue;
            }

            // If no unmatched '(' is available to balance, increment `closeCount`
            closeCount++;
        }
    }

    // The total number of unmatched parentheses will be the sum of
    // `openCount` (remaining unmatched '(') and `closeCount` (remaining unmatched ')')
    return (openCount + closeCount);
}

// Example patterns to test the function:
// (), ((, )), )(, ((((
int main() {
    string pattern = "((())"; // Example input
    cout << "Minimum parentheses needed to balance: " << minimumParentheses(pattern) << endl;
    return 0;
}

/*
Time Complexity:
The time complexity of this code is O(n), where n is the length of the input string. This is because we iterate through each character in the string only once, performing constant-time operations such as incrementing or decrementing counters. Therefore, the time required grows linearly with the size of the input.

Space Complexity:
The space complexity is O(1), or constant space. This is because the function uses only a fixed amount of additional memory regardless of the input size. The variables openCount and closeCount are the only additional storage used, and they do not depend on the length of the input string.
*/