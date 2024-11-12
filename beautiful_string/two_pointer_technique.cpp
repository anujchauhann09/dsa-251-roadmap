#include <bits/stdc++.h>
using namespace std;

// This function takes a character ('0' or '1') and returns its opposite.
// If the character is '0', it returns '1'; otherwise, it returns '0'.
char giveOpposite(char num) {
    if (num == '0')
        return '1';
    return '0';
}

// This function calculates the minimum number of changes needed to make
// the input string "beautiful" by trying two different starting approaches.
int makeBeautiful(string str) {
    int length = str.length();   // Get the length of the input string.
    string str2 = str;           // Make a copy of the string for the second approach.
    int count1 = 0;              // Counter for changes in the first approach.
    int count2 = 0;              // Counter for changes in the second approach.

    // Initialize the second approach by changing the first character of str2.
    str2[0] = giveOpposite(str2[0]);
    count2++;  // Increase the change count for str2 since we altered the first character.

    // Loop through the string from the first to the second-last character.
    for (int i = 0; i < length - 1; i++) {
        // Approach 1: Keep the first character of str as is and check if it alternates.
        if (str[i] == str[i + 1]) { // If two consecutive characters are the same,
            count1++;               // increment the count for this approach.
            str[i + 1] = giveOpposite(str[i + 1]); // Change the next character to make it alternate.
        }

        // Approach 2: Start with the first character of str2 already changed.
        if (str2[i] == str2[i + 1]) { // If two consecutive characters are the same,
            count2++;                 // increment the count for this approach.
            str2[i + 1] = giveOpposite(str2[i + 1]); // Change the next character to make it alternate.
        }
    }

    // Return the minimum of the two counts, which represents the minimum changes required.
    return min(count1, count2);
}

/*
Time Complexity:
The time complexity of this code is O(n), where n is the length of the input string. This is because the code iterates through each character of the string only once in the main loop. Each iteration involves checking consecutive characters and possibly modifying one of them, but no nested loops or additional complex operations are performed, making the overall execution linear with respect to the input size.

Space Complexity:
The space complexity of this code is O(n) as well. This is due to the creation of a second string, str2, which is a copy of the input string str. Since both str and str2 require space proportional to the input size, the overall space usage scales linearly with the size of the input string. No other significant auxiliary space is used in the function, aside from a few integer variables that do not depend on the input size.
*/