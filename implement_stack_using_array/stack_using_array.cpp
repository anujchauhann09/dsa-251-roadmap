#include <iostream>
using namespace std;

// Stack class implementation using an array.
class Stack {
public:
    int *stack;      // Dynamic array to store stack elements.
    int size;        // Maximum capacity of the stack.
    int topIndex;    // Index of the topmost element in the stack.

    // Constructor to initialize the stack with a given capacity.
    Stack(int capacity) {
        this->size = capacity;
        stack = new int[size]; // Allocate memory for the stack array.
        this->topIndex = -1;   // Initialize topIndex to -1 (stack is empty).
    }

    // Method to push an element onto the stack.
    void push(int num) {
        if (topIndex != (size - 1)) { // Check if the stack is not full.
            topIndex++;               // Increment the topIndex.
            stack[topIndex] = num;    // Insert the element at the new topIndex.
        } else {
            cout << "Stack Overflow: Cannot push " << num << " onto the stack." << endl;
        }
    }

    // Method to pop the top element from the stack.
    int pop() {
        if (topIndex == -1) {         // Check if the stack is empty.
            cout << "Stack Underflow: Cannot pop from an empty stack." << endl;
            return -1;                // Return -1 if the stack is empty.
        }
        int poppedElement = stack[topIndex]; // Store the top element to return.
        topIndex--;                          // Decrement the topIndex.
        return poppedElement;
    }

    // Method to get the top element of the stack without removing it.
    int top() {
        if (topIndex == -1) {         // Check if the stack is empty.
            return -1;                // Return -1 if the stack is empty.
        }
        return stack[topIndex];       // Return the top element.
    }

    // Method to check if the stack is empty.
    int isEmpty() {
        return (topIndex == -1) ? 1 : 0;
    }

    // Method to check if the stack is full.
    int isFull() {
        return (topIndex == (size - 1)) ? 1 : 0;
    }
};

// Main function to demonstrate the stack operations.
int main() {
    // Create a stack with a capacity of 5.
    Stack s(5);

    // Test case 1: Push elements onto the stack.
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element after pushes: " << s.top() << endl; // Expected: 30

    // Test case 2: Pop an element and check the top.
    cout << "Popped element: " << s.pop() << endl;           // Expected: 30
    cout << "Top element after pop: " << s.top() << endl;    // Expected: 20

    // Test case 3: Check if the stack is empty or full.
    cout << "Is stack empty? " << s.isEmpty() << endl;       // Expected: 0 (False)
    cout << "Is stack full? " << s.isFull() << endl;         // Expected: 0 (False)

    // Additional operations to show boundary cases.
    s.pop();
    s.pop(); // Stack should now be empty.
    cout << "Popped from empty stack: " << s.pop() << endl;  // Expected: -1
    cout << "Is stack empty? " << s.isEmpty() << endl;       // Expected: 1 (True)

    // Push elements until the stack is full.
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80); // Stack should now be full.
    s.push(90); // Overflow attempt.

    return 0;
}

/*
Time Complexity:
The time complexity of the stack implementation is O(1) for all primary operations—push, pop, and top. This is because these operations involve simple index manipulation or accessing an element in the array, which are constant-time operations. Regardless of the size of the stack, these operations do not depend on the number of elements stored.

Space Complexity:
The space complexity is O(n), where n is the maximum capacity of the stack. This is because a dynamic array of size n is allocated at the time of stack creation. The additional space used is minimal, as it only includes a few integer variables (size, topIndex) to manage the stack.
*/