#include <bits/stdc++.h>
using namespace std;

/**
 * Function to calculate stock spans.
 * The span of the stock price on a given day is defined as the maximum number 
 * of consecutive days (including the current day) the price has been less than 
 * or equal to its price on the current day.
 * 
 * @param price Vector of stock prices.
 * @return Vector of spans for each day.
 */
vector<int> findSpans(vector<int> &price) {
    int size = price.size();
    vector<int> answer;

    // Iterate through each stock price.
    for (int i = 0; i < size; i++) {
        int countDays = 0;

        // Check for consecutive days with prices less than or equal to the current day's price.
        for (int j = i; j >= 0; j--) {
            if (price[i] >= price[j]) {
                countDays++;
            } else {
                break; // Stop when a greater price is found.
            }
        }

        // Store the span for the current day.
        answer.push_back(countDays);
    }

    return answer;
}

int main() {
    // Test case 1
    vector<int> prices1 = {100, 80, 60, 70, 60, 75, 85};
    vector<int> spans1 = findSpans(prices1);
    cout << "Spans for prices {100, 80, 60, 70, 60, 75, 85}: ";
    for (int span : spans1) {
        cout << span << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> prices2 = {10, 4, 5, 90, 120, 80};
    vector<int> spans2 = findSpans(prices2);
    cout << "Spans for prices {10, 4, 5, 90, 120, 80}: ";
    for (int span : spans2) {
        cout << span << " ";
    }
    cout << endl;

    // Test case 3
    vector<int> prices3 = {30, 20, 25, 28, 27, 29, 35};
    vector<int> spans3 = findSpans(prices3);
    cout << "Spans for prices {30, 20, 25, 28, 27, 29, 35}: ";
    for (int span : spans3) {
        cout << span << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of this approach is O(n²) because for each day's stock price (outer loop), we iterate backward through the prices up to the current day (inner loop). In the worst case, this results in a nested iteration where the inner loop runs approximately n times for the first day, n-1 times for the second day, and so on, leading to a total of O(n²) iterations. 

Space Complexity:
The space complexity is O(n) because we use an additional vector to store the spans for all n days. There are no other significant data structures or recursive calls consuming extra memory, so the additional space usage is limited to storing the results. This approach, though simple and intuitive, can become inefficient for large input sizes due to its quadratic time complexity, making it suitable only for smaller datasets.
*/