#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum number of parentheses needed to make the pattern balanced
int minimumParentheses(string pattern) {
    int length = pattern.length(); // Get the length of the input pattern
    int closeCount = 0; // Counter for unmatched closing parentheses
    stack<int> patternStack; // Stack to track unmatched opening parentheses

    // Iterate through each character in the input pattern
    for(int i = 0; i < length; i++) {
        if(pattern[i] == '(') {
            // If the character is an opening parenthesis, push it onto the stack
            patternStack.push(pattern[i]);
        }
        else {
            // If the character is a closing parenthesis
            if(!patternStack.empty()) {
                // If there is an unmatched opening parenthesis in the stack, pop it
                // because this closing parenthesis can pair with it
                patternStack.pop();
            }
            else {
                // If no opening parenthesis is available to pair, increment closeCount
                closeCount++;
            }
        }
    }

    // The total number of unbalanced parentheses is the sum of:
    // - Remaining opening parentheses in the stack (patternStack.size())
    // - Unmatched closing parentheses counted by closeCount
    return (patternStack.size() + closeCount);
}

int main() {
    string s = "(()))("; // Example input
    cout << "Minimum parentheses needed to balance: " << minimumParentheses(s) << endl;
    return 0;
}

/*
Time Complexity:
The time complexity of this code is O(n) because the function iterates through each character in the input string pattern once. For each character, the code either pushes or pops from the stack in constant time. This means that the number of operations grows linearly with the size of the input string, making the time complexity proportional to the input length, n.

Space Complexity:
The space complexity is also O(n) in the worst case, as we use a stack to store unmatched opening parentheses. If the input consists entirely of opening parentheses with no closing parentheses, the stack will store all n characters, leading to an O(n) space requirement. Additionally, we use a constant amount of extra space for variables like closeCount, length, and i, so the main space usage is determined by the stack, resulting in an overall space complexity of O(n).
*/