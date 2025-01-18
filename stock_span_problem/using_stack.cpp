#include <bits/stdc++.h>
using namespace std;

/*
 * Function to calculate the stock span for each day's price.
 * The stock span for a day is defined as the maximum number of consecutive days (up to the current day)
 * the price of the stock has been less than or equal to the price on the current day.
 *
 * @param price: A vector of integers representing the price of the stock on each day.
 * @return: A vector of integers where each element is the span for the corresponding day in the input prices.
 */
vector<int> findSpans(vector<int> &price) {
    int size = price.size();
    vector<int> answer(size);  // To store the spans
    stack<int> stk;            // Stack to store indices of elements

    for (int i = 0; i < size; i++) {
        // Pop elements from the stack while the current price is greater than or equal to the price at the stack's top index.
        while (!stk.empty() && price[stk.top()] <= price[i]) {
            stk.pop();
        }

        // If the stack is empty, the span is the entire range from 0 to i.
        if (stk.empty()) {
            answer[i] = i + 1;
        }
        // Otherwise, the span is the difference between the current index and the index at the top of the stack.
        else {
            answer[i] = i - stk.top();
        }

        // Push the current index onto the stack.
        stk.push(i);
    }

    return answer;
}

/*
 * Main function to test the findSpans function with multiple test cases.
 */
int main() {
    // Test Case 1
    vector<int> price1 = {100, 80, 60, 70, 60, 75, 85};
    vector<int> spans1 = findSpans(price1);
    cout << "Spans for Test Case 1: ";
    for (int span : spans1) {
        cout << span << " ";
    }
    cout << endl;

    // Test Case 2
    vector<int> price2 = {10, 4, 5, 90, 120, 80};
    vector<int> spans2 = findSpans(price2);
    cout << "Spans for Test Case 2: ";
    for (int span : spans2) {
        cout << span << " ";
    }
    cout << endl;

    // Test Case 3
    vector<int> price3 = {40, 30, 20, 10};
    vector<int> spans3 = findSpans(price3);
    cout << "Spans for Test Case 3: ";
    for (int span : spans3) {
        cout << span << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of this approach is O(n) because each element is pushed onto the stack once and popped at most once, resulting in linear time complexity. The inner loop executes only for elements removed from the stack, ensuring the overall traversal of all elements remains linear. 

Space Complexity:
The space complexity is O(n) due to the stack, which can hold at most n elements in the worst case, and the answer vector, which stores the spans. Thus, the algorithm efficiently computes the spans with minimal extra space and optimal performance for larger inputs.
*/
