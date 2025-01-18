#include <bits/stdc++.h>
using namespace std;

/*
    Function to check if a string of parentheses is valid.
    A string is valid if:
    1. Every opening parenthesis has a corresponding closing parenthesis.
    2. Parentheses are properly nested and ordered.
    
    Parameters:
    - s: A string containing parentheses (e.g., "()", "{}[]", "({[]})").

    Returns:
    - true (1): If the string contains valid parentheses.
    - false (0): Otherwise.
*/
bool isValidParenthesis(string s) {
    stack<char> st; // Stack to store opening parentheses.

    // Iterate through each character in the string.
    for (int i = 0; i < s.length(); i++) {
        // If the character is an opening parenthesis, push it onto the stack.
        if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
            st.push(s[i]);
        } 
        // If the character is a closing parenthesis.
        else if (!st.empty()) {
            char topParenthesis = st.top(); // Get the top of the stack.

            // Check if the current closing parenthesis matches the top of the stack.
            if ((s[i] == '}' && topParenthesis == '{') ||
                (s[i] == ')' && topParenthesis == '(') ||
                (s[i] == ']' && topParenthesis == '[')) {
                st.pop(); // Pop the top of the stack if it's a match.
            } 
            else {
                return 0; // Mismatch found.
            }
        } 
        else {
            return 0; // Closing parenthesis without a matching opening parenthesis.
        }
    }

    // If the stack is empty, all parentheses were matched; otherwise, it's invalid.
    return st.empty();
}

int main() {
    // Test Case 1: Balanced parentheses.
    string test1 = "({[]})";
    cout << "Test Case 1: " << (isValidParenthesis(test1) ? "Valid" : "Invalid") << endl;

    // Test Case 2: Unbalanced parentheses.
    string test2 = "({[})";
    cout << "Test Case 2: " << (isValidParenthesis(test2) ? "Valid" : "Invalid") << endl;

    // Test Case 3: Only opening parentheses.
    string test3 = "((({{{[[[";
    cout << "Test Case 3: " << (isValidParenthesis(test3) ? "Valid" : "Invalid") << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of the isValidParenthesis function is O(n), where n is the length of the input string. This is because each character in the string is processed exactly once, either being pushed onto the stack or matched and popped.

Space Complexity:
The space complexity is O(n) in the worst case, as the stack may store all opening parentheses if no matching closing parentheses are encountered. This efficient approach ensures linear traversal and stack operations, making it optimal for validating balanced parentheses in strings.
*/