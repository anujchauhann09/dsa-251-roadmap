#include <bits/stdc++.h>
using namespace std;

/**
 * @brief This function reverses the order of elements in a queue.
 * 
 * It uses a vector to temporarily store elements of the queue in reverse order.
 * First, all elements are dequeued and stored in a vector from the last index to the first.
 * Then, the vector elements are pushed back into the queue, resulting in a reversed queue.
 * 
 * @param q The queue to be reversed.
 * @return queue<int> The reversed queue.
 */
queue<int> reverseQueue(queue<int> q) {
    int size = q.size();                        // Get the size of the queue
    vector<int> reverseElements(size);          // Vector to store queue elements in reverse order
    int index = size - 1;                       // Start from the last index

    // Dequeue all elements from the queue and store them in the vector in reverse order
    while (!q.empty()) {
        int frontElement = q.front();           // Get the front element of the queue
        reverseElements[index--] = frontElement; // Store it in the vector at the current index
        q.pop();                                // Remove the front element from the queue
    }

    // Enqueue the elements from the vector back into the queue
    for (int i = 0; i < size; i++) {
        int element = reverseElements[i];       // Get the element from the vector
        q.push(element);                        // Push it into the queue
    }

    return q;                                   // Return the reversed queue
}

/**
 * @brief Test the reverseQueue function with three test cases.
 */
int main() {
    // Test case 1: A simple queue with distinct integers
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    queue<int> reversedQ1 = reverseQueue(q1);
    cout << "Test Case 1: ";
    while (!reversedQ1.empty()) {
        cout << reversedQ1.front() << " ";
        reversedQ1.pop();
    }
    cout << endl;

    // Test case 2: A queue with duplicate elements
    queue<int> q2;
    q2.push(10);
    q2.push(20);
    q2.push(20);
    q2.push(30);
    queue<int> reversedQ2 = reverseQueue(q2);
    cout << "Test Case 2: ";
    while (!reversedQ2.empty()) {
        cout << reversedQ2.front() << " ";
        reversedQ2.pop();
    }
    cout << endl;

    // Test case 3: A queue with a single element
    queue<int> q3;
    q3.push(100);
    queue<int> reversedQ3 = reverseQueue(q3);
    cout << "Test Case 3: ";
    while (!reversedQ3.empty()) {
        cout << reversedQ3.front() << " ";
        reversedQ3.pop();
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:
The time complexity (TC) of the reverseQueue function is O(n), where n is the number of elements in the queue. This is because the function iterates through each element of the queue twice: first to dequeue all elements and store them in a vector, and second to enqueue the elements back into the queue from the vector. Both operations take linear time in relation to the number of elements.

Space Complexity:
The space complexity (SC) is also O(n), as the function uses a vector to temporarily store the elements of the queue while reversing the order. This vector requires space proportional to the number of elements in the queue. The additional space used by other variables, such as the queue itself, is negligible in terms of space complexity.
*/