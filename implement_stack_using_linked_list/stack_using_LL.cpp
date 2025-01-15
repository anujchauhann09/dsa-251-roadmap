#include <iostream>
using namespace std;

/****************************************************************
    Node class definition:
    A Node class is used to represent each element of the stack.
    - `data` stores the value of the node.
    - `next` is a pointer to the next node in the stack.
*****************************************************************/
class Node
{
public:
    int data;  // Value stored in the node
    Node* next; // Pointer to the next node in the stack

    // Default constructor
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    // Constructor to initialize a node with a value
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Constructor to initialize a node with a value and a pointer to the next node
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

/****************************************************************
    Stack class implementation:
    Implements stack functionality using a linked list.
    - `head`: Points to the top of the stack.
    - `size`: Keeps track of the number of elements in the stack.
*****************************************************************/
class Stack
{
public:
    Node* head; // Pointer to the top of the stack
    int size;   // Size of the stack

    // Constructor to initialize an empty stack
    Stack()
    {
        head = NULL; // Stack is initially empty
        size = 0;    // Stack size is 0
    }

    // Returns the current size of the stack
    int getSize()
    {
        return size;
    }

    // Checks if the stack is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Pushes a new element onto the stack
    void push(int data)
    {
        Node* newNode = new Node(data); // Create a new node
        newNode->next = head;           // Point it to the current top
        head = newNode;                 // Update the top of the stack
        size++;                         // Increment stack size
    }

    // Pops the top element from the stack
    void pop()
    {
        if (isEmpty())
        {
            // If the stack is empty, do nothing
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        Node* temp = head;   // Store the current top
        head = head->next;   // Move the top pointer to the next node
        delete temp;         // Free memory of the old top
        size--;              // Decrement stack size
    }

    // Returns the value of the top element without removing it
    int getTop()
    {
        if (isEmpty())
        {
            // If the stack is empty, return -1
            cout << "Stack is empty. Top element not available." << endl;
            return -1;
        }
        return head->data; // Return the data of the top node
    }
};

/****************************************************************
    Main function:
    - Demonstrates the functionality of the Stack class.
    - Includes 3 test cases for different stack operations.
*****************************************************************/
int main()
{
    // Test Case 1: Basic operations
    cout << "Test Case 1: Basic Operations" << endl;
    Stack stack1;

    stack1.push(10); // Push 10
    stack1.push(20); // Push 20
    stack1.push(30); // Push 30
    cout << "Top element after pushes: " << stack1.getTop() << endl; // Output: 30

    stack1.pop(); // Pop the top element
    cout << "Top element after one pop: " << stack1.getTop() << endl; // Output: 20
    cout << "Stack size: " << stack1.getSize() << endl; // Output: 2
    cout << endl;

    // Test Case 2: Edge case - Pop from an empty stack
    cout << "Test Case 2: Pop from Empty Stack" << endl;
    Stack stack2;

    stack2.pop(); // Attempt to pop from an empty stack
    cout << "Top element of an empty stack: " << stack2.getTop() << endl; // Output: -1
    cout << "Stack size: " << stack2.getSize() << endl; // Output: 0
    cout << endl;

    // Test Case 3: Push and pop multiple elements
    cout << "Test Case 3: Push and Pop Multiple Elements" << endl;
    Stack stack3;

    stack3.push(5);  // Push 5
    stack3.push(15); // Push 15
    stack3.push(25); // Push 25
    cout << "Top element: " << stack3.getTop() << endl; // Output: 25
    stack3.pop(); // Pop the top element
    cout << "Top element after pop: " << stack3.getTop() << endl; // Output: 15
    stack3.pop(); // Pop the top element
    stack3.pop(); // Pop the top element
    cout << "Is stack empty after popping all elements? " << stack3.isEmpty() << endl; // Output: 1 (true)
    cout << endl;

    return 0;
}

/*
Time Complexity:
The time complexity for each operation is efficient because the linked list allows direct access and manipulation of nodes at the top of the stack. The push, pop, and getTop operations all work in constant time, 
O(1). This is because these operations involve updating or accessing the head pointer without traversing the list. The size retrieval operation, getSize, also takes O(1) since the size is maintained as a class variable and doesn't require recalculation.

Space Complexity:
The space complexity depends on the number of elements in the stack. Each element in the stack is represented by a node in the linked list, where each node contains an integer (for the data) and a pointer (to the next node). Therefore, the space required for the stack grows linearly with the number of elements in the stack, resulting in a space complexity of O(n), where n is the number of elements in the stack. Additionally, there is a small, constant amount of extra space used for maintaining the head pointer and the size variable.
*/