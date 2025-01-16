#include <bits/stdc++.h>
using namespace std;

// Class to implement a Queue using two stacks
class Queue {
    // Two stacks used for implementing the queue
    stack<int> stk1, stk2;

public:
    // Enqueues 'X' into the queue. Returns true after enqueuing.
    bool enqueue(int X) {
        // Push the element onto the first stack
        stk1.push(X);
        return true;
    }

    /*
      Dequeues the front element from the queue.
      Returns -1 if the queue is empty, otherwise returns the dequeued element.
    */
    int dequeue() {
        // If both stacks are empty, the queue is empty
        if (stk1.empty() && stk2.empty()) {
            return -1;
        }

        // If the second stack is empty, transfer all elements from the first stack to the second
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }

        // Pop the top element of the second stack (front of the queue)
        int topEle = stk2.top();
        stk2.pop();
        return topEle;
    }
};

int main() {
    Queue q;

    // Test Case 1: Basic enqueue and dequeue operations
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Dequeue: " << q.dequeue() << endl; // Expected: 1
    cout << "Dequeue: " << q.dequeue() << endl; // Expected: 2

    // Test Case 2: Dequeue after adding more elements
    q.enqueue(4);
    q.enqueue(5);
    cout << "Dequeue: " << q.dequeue() << endl; // Expected: 3
    cout << "Dequeue: " << q.dequeue() << endl; // Expected: 4

    // Test Case 3: Dequeue from an empty queue
    q.dequeue(); // Expected: 5 (last element in the queue)
    cout << "Dequeue: " << q.dequeue() << endl; // Expected: -1 (queue is empty)

    return 0;
}

/*
Time Complexity:
The time complexity for the enqueue operation is O(1) because elements are directly pushed onto the first stack (stk1) without any additional operations. The time complexity for the dequeue operation is O(1) on average (amortized). When elements need to be moved from stk1 to stk2 (to reverse their order), it takes O(n) time, where n is the number of elements in stk1. However, this transfer happens only when stk2 is empty, so each element is moved exactly once during its lifetime in the queue, resulting in an amortized O(1) complexity per operation.

Space Complexity:
The space complexity is O(n), where n is the total number of elements in the queue at any given time. Both stacks (stk1 and stk2) together can hold at most n elements, but never more. Therefore, the extra space usage is proportional to the size of the queue.
*/
