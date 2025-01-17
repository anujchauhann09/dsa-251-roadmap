#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Helper function to reverse a queue using recursion.
 * 
 * This function removes the front element of the queue, recursively calls itself
 * to reverse the remaining queue, and then pushes the removed element back into the queue.
 * The recursion unwinds after processing all elements, effectively reversing the queue.
 * 
 * @param q Reference to the queue to be reversed.
 */
void reverseQueueHelper(queue<int> &q) {
    // Base case: If the queue is empty, return.
    if (q.empty()) {
        return;
    }

    // Remove the front element.
    int frontElement = q.front();
    q.pop();

    // Recursively reverse the remaining queue.
    reverseQueueHelper(q);

    // Push the removed element to the back of the queue.
    q.push(frontElement);
}

/**
 * @brief Function to reverse a queue.
 * 
 * This function uses the reverseQueueHelper function to reverse the given queue.
 * 
 * @param q The queue to be reversed.
 * @return The reversed queue.
 */
queue<int> reverseQueue(queue<int> q) {
    // Call the helper function to reverse the queue.
    reverseQueueHelper(q);

    // Return the reversed queue.
    return q;
}

int main() {
    // Test case 1
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    cout << "Original queue (test case 1): ";
    queue<int> temp1 = q1;
    while (!temp1.empty()) {
        cout << temp1.front() << " ";
        temp1.pop();
    }
    cout << endl;

    queue<int> reversedQ1 = reverseQueue(q1);
    cout << "Reversed queue (test case 1): ";
    while (!reversedQ1.empty()) {
        cout << reversedQ1.front() << " ";
        reversedQ1.pop();
    }
    cout << endl;

    // Test case 2
    queue<int> q2;
    q2.push(10);
    q2.push(20);
    q2.push(30);
    cout << "Original queue (test case 2): ";
    queue<int> temp2 = q2;
    while (!temp2.empty()) {
        cout << temp2.front() << " ";
        temp2.pop();
    }
    cout << endl;

    queue<int> reversedQ2 = reverseQueue(q2);
    cout << "Reversed queue (test case 2): ";
    while (!reversedQ2.empty()) {
        cout << reversedQ2.front() << " ";
        reversedQ2.pop();
    }
    cout << endl;

    // Test case 3
    queue<int> q3;
    q3.push(5);
    cout << "Original queue (test case 3): ";
    queue<int> temp3 = q3;
    while (!temp3.empty()) {
        cout << temp3.front() << " ";
        temp3.pop();
    }
    cout << endl;

    queue<int> reversedQ3 = reverseQueue(q3);
    cout << "Reversed queue (test case 3): ";
    while (!reversedQ3.empty()) {
        cout << reversedQ3.front() << " ";
        reversedQ3.pop();
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of reversing a queue using recursion is O(n), where n is the number of elements in the queue. This is because each element is removed from the front and pushed back to the rear once, resulting in a linear traversal of the queue.

Space Complexity:
The space complexity is also O(n) due to the recursive call stack, as the depth of recursion will be equal to the size of the queue. Together, this approach is efficient for reversing a queue while leveraging recursion, but it uses additional memory proportional to the size of the queue for the recursive stack.
*/