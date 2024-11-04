#include <iostream>
using namespace std;

string reverseStringWordWise(string input) {
    int n = input.size();  // Get the length of the input string.
    int start = 0, end = n - 1;

    // Step 1: Reverse the entire string in-place.
    while (start < end) {
        swap(input[start++], input[end--]);
    }

    // Now the entire string is reversed, but each word is reversed as well.
    // For example, "welcome to coding ninjas" becomes "sajnin gnidoc ot emoclew".

    start = 0;  // Reset 'start' to begin processing each word individually.

    // Step 2: Reverse each word in the reversed string to correct the order of letters in each word.
    for (int i = 0; i <= n; i++) {
        // Check if we have reached a space or the end of the string.
        if (input[i] == ' ' || i == n) {
            end = i - 1;  // Set 'end' to the last character of the current word.

            // Reverse the characters in the current word.
            while (start < end) {
                swap(input[start++], input[end--]);
            }

            // Move 'start' to the first character of the next word.
            start = i + 1;
        }
    }

    // At this point, the input string has each word in the correct order, but the entire sentence is reversed.
    // For example, "sajnin gnidoc ot emoclew" becomes "ninjas coding to welcome".

    return input;
}

int main() {
    string s;
    getline(cin, s);  // Read a line of input from the user.
    string ans = reverseStringWordWise(s);
    cout << ans << endl;  // Output the sentence with words in reverse order.
}

/*
Time Complexity:
The time complexity of this code is O(n), where n is the length of the input string. This is because we make two passes over the string. In the first pass, we reverse the entire string, and in the second pass, we iterate over the string again to reverse each word within it individually. Since each character in the string is processed a fixed number of times, the overall complexity remains linear in terms of the length of the input. 

Space Complexity:
The space complexity is O(1) because the operations are done in-place within the input string, and no additional data structures are used to store intermediate results, which makes this an efficient in-place algorithm.
*/