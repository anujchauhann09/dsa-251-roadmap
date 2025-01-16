#include <bits/stdc++.h>
using namespace std;

/**
 * A Queue class implemented using a fixed-size array.
 * This implementation includes basic queue operations: isEmpty, enqueue, dequeue, and front.
 */
class Queue {
public:
    int *queue;     // Pointer to the array that will hold the queue elements
    int size;       // Maximum size of the queue
    int queFront;   // Index of the front element of the queue
    int queRear;    // Index of the rear (next insert position) of the queue

    /**
     * Constructor to initialize the queue.
     * The size is set to 100001, and queFront and queRear are initialized to 0.
     */
    Queue() {
        size = 100001;  // Setting the size to 10^5 + 1 for large input handling
        queue = new int[size];  // Dynamically allocate memory for the array
        queFront = 0;   // Queue starts empty; front index is 0
        queRear = 0;    // Rear index is also 0
    }

    /**
     * Checks if the queue is empty.
     * Returns true if queFront == queRear, indicating no elements in the queue.
     */
    bool isEmpty() {
        return queFront == queRear;
    }

    /**
     * Adds an element to the rear of the queue.
     * If the queue is not full, the element is inserted at queRear, and queRear is incremented.
     */
    void enqueue(int data) {
        if (queRear != size) {  // Ensure the queue is not full
            queue[queRear] = data;  // Insert the element at the rear
            queRear++;  // Move the rear pointer to the next position
        }
    }

    /**
     * Removes and returns the element at the front of the queue.
     * If the queue is empty, returns -1.
     * After dequeuing, adjusts the queFront and queRear pointers as necessary.
     */
    int dequeue() {
        if (queFront == queRear) {  // If the queue is empty
            return -1;
        }

        int dequeuedEle = queue[queFront];  // Store the front element
        queue[queFront] = -1;  // Optional: Clear the dequeued position (for visualization)
        queFront++;  // Move the front pointer to the next position

        // If the queue becomes empty after dequeuing, reset the pointers
        if (queFront == queRear) {
            queFront = 0;
            queRear = 0;
        }

        return dequeuedEle;  // Return the dequeued element
    }

    /**
     * Returns the element at the front of the queue without removing it.
     * If the queue is empty, returns -1.
     */
    int front() {
        if (queFront == queRear) {  // If the queue is empty
            return -1;
        }
        return queue[queFront];  // Return the front element
    }
};

/**
 * Main function to demonstrate the functionality of the Queue class.
 * Includes three test cases to validate all operations of the queue.
 */
int main() {
    // Test case 1: Basic operations
    Queue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    cout << "Front of q1: " << q1.front() << endl;  // Output: 10
    cout << "Dequeued from q1: " << q1.dequeue() << endl;  // Output: 10
    cout << "Front of q1 after dequeue: " << q1.front() << endl;  // Output: 20

    // Test case 2: Dequeue until empty
    Queue q2;
    q2.enqueue(5);
    q2.enqueue(15);
    cout << "Dequeued from q2: " << q2.dequeue() << endl;  // Output: 5
    cout << "Dequeued from q2: " << q2.dequeue() << endl;  // Output: 15
    cout << "Dequeue from empty q2: " << q2.dequeue() << endl;  // Output: -1

    // Test case 3: Check isEmpty and enqueue after reset
    Queue q3;
    cout << "Is q3 empty initially? " << (q3.isEmpty() ? "Yes" : "No") << endl;  // Output: Yes
    q3.enqueue(100);
    q3.enqueue(200);
    cout << "Is q3 empty after enqueue? " << (q3.isEmpty() ? "Yes" : "No") << endl;  // Output: No
    cout << "Front of q3: " << q3.front() << endl;  // Output: 100
    cout << "Dequeued from q3: " << q3.dequeue() << endl;  // Output: 100
    cout << "Dequeued from q3: " << q3.dequeue() << endl;  // Output: 200
    cout << "Is q3 empty after dequeue? " << (q3.isEmpty() ? "Yes" : "No") << endl;  // Output: Yes

    return 0;
}

/*
Time Complexity:
The time complexity for all queue operations—enqueue, dequeue, front, and isEmpty—is O(1) because they involve direct index manipulation or simple comparisons without loops. 

Space Complexity:
The space complexity is O(n), where n is the predefined queue size (100001), as the array used for storing elements takes linear space. This implementation is efficient and ensures constant-time operations with a fixed memory allocation.
*/