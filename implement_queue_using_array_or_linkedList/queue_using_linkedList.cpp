#include <bits/stdc++.h>
using namespace std;

/*
 * Node class represents a single node in the linked list implementation of the queue.
 * Each node contains an integer `data` and a pointer `next` to the next node in the queue.
 */
class Node {
public:
    int data;      // Data stored in the node
    Node* next;    // Pointer to the next node

    // Default constructor initializing data to -1 and next to NULL
    Node() {
        this->data = -1;
        this->next = NULL;
    }

    // Constructor to initialize node with a specific value
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

/*
 * Queue class implements a queue data structure using a linked list.
 * It supports standard queue operations: isEmpty, enqueue, dequeue, and front.
 */
class Queue {
public:
    Node* queFront; // Pointer to the front of the queue
    Node* queRear;  // Pointer to the rear of the queue

    // Constructor initializes an empty queue
    Queue() {
        queFront = NULL;
        queRear = NULL;
    }

    /*
     * isEmpty: Checks if the queue is empty.
     * Returns true if the queue is empty (queFront is NULL), otherwise false.
     */
    bool isEmpty() {
        return queFront == NULL;
    }

    /*
     * enqueue: Adds an element to the rear of the queue.
     * If the queue is empty, both queFront and queRear point to the new node.
     */
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (!queRear) { // Queue is empty
            queRear = newNode;
            queFront = newNode;
            return;
        }
        queRear->next = newNode; // Link the new node to the rear
        queRear = newNode;       // Update the rear pointer
    }

    /*
     * dequeue: Removes and returns the front element of the queue.
     * If the queue is empty, returns -1. Updates the front pointer.
     */
    int dequeue() {
        if (!queFront) { // Queue is empty
            return -1;
        }

        int dequeuedEle = queFront->data; // Store data of the front node
        Node* temp = queFront;           // Temporary pointer to the front node
        queFront = queFront->next;       // Move the front pointer to the next node
        delete temp;                     // Free the memory of the dequeued node

        // If the queue becomes empty after dequeue, reset both pointers
        if (!queFront) {
            queFront = NULL;
            queRear = NULL;
        }

        return dequeuedEle;
    }

    /*
     * front: Returns the front element of the queue without removing it.
     * If the queue is empty, returns -1.
     */
    int front() {
        if (!queFront) { // Queue is empty
            return -1;
        }
        return queFront->data;
    }
};

/*
 * Main function to test the Queue class.
 * Creates a queue and performs enqueue, dequeue, and front operations.
 */
int main() {
    Queue q;

    // Test case 1: Basic enqueue and dequeue operations
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front element: " << q.front() << endl; // Output: 10
    cout << "Dequeued: " << q.dequeue() << endl;   // Output: 10
    cout << "Dequeued: " << q.dequeue() << endl;   // Output: 20

    // Test case 2: Check empty queue behavior
    cout << "Dequeued: " << q.dequeue() << endl;   // Output: 30
    cout << "Is queue empty? " << q.isEmpty() << endl; // Output: 1 (true)
    cout << "Dequeued: " << q.dequeue() << endl;   // Output: -1

    // Test case 3: Reusing the queue after it becomes empty
    q.enqueue(40);
    q.enqueue(50);
    cout << "Front element: " << q.front() << endl; // Output: 40
    cout << "Dequeued: " << q.dequeue() << endl;   // Output: 40
    cout << "Dequeued: " << q.dequeue() << endl;   // Output: 50

    return 0;
}

/*
Time Complexity:
The time complexity of this queue implementation is efficient, with O(1) for the enqueue, dequeue, and front operations because these involve only pointer manipulations or direct access without iteration. 

Space Complexity:
The space complexity is O(n), where n is the number of elements in the queue, as each element requires memory allocation for a Node object, which stores the data and a pointer to the next node. This approach dynamically adjusts memory usage based on the queue size, avoiding pre-allocated fixed storage and ensuring optimal memory utilization.
*/