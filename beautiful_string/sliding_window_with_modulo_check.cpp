#include <bits/stdc++.h> 
using namespace std;

// Function to calculate minimum changes to make a binary string alternate in pattern
int makeBeautiful(string str) {
    int n = str.size();  // Get the length of the input string
    int pattern1_mismatches = 0; // Counter for mismatches with pattern "010101..."
    int pattern2_mismatches = 0; // Counter for mismatches with pattern "101010..."

    // Traverse each character in the string
    for (int i = 0; i < n; i++) {
        // Calculate expected characters for both patterns at position `i`
        char expected1 = (i % 2 == 0) ? '0' : '1'; // For pattern "010101..."
        char expected2 = (i % 2 == 0) ? '1' : '0'; // For pattern "101010..."

        // Check if current character matches the expected character in "010101..." pattern
        if (str[i] != expected1) {
            pattern1_mismatches++;  // Increment mismatch count for the first pattern
        }

        // Check if current character matches the expected character in "101010..." pattern
        if (str[i] != expected2) {
            pattern2_mismatches++;  // Increment mismatch count for the second pattern
        }
    }

    // The minimum of the two mismatch counts gives the minimum changes needed
    return min(pattern1_mismatches, pattern2_mismatches);
}

/*
Time Complexity:
The time complexity of this function is O(n), where n is the length of the input string. This is because we iterate through the string only once in a single for-loop, checking each character to compare it against the expected characters for two possible alternating patterns. Each operation within the loop is constant time, making the entire process proportional to the length of the string.

Space Complexity:
The space complexity is O(1), meaning it is constant. This is because we are only using a fixed number of integer counters (pattern1_mismatches and pattern2_mismatches) and a few character variables to store expected characters at each index. These require a constant amount of space, regardless of the size of the input string, so our additional memory usage does not grow with the length of the input.
*/