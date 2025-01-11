#include <iostream>
using namespace std;

class Node {
public:
     int data;
     Node *next;
     Node() {
         this->data = 0;
         this->next = NULL;
     }
     Node(int data) {
         this->data = data;
         this->next = NULL;
     }
     Node (int data, Node *next) {
         this->data = data;
         this->next = next;
     }
};

/**
 * Helper function to insert a new node with given data into the linked list.
 * It updates both the head and tail pointers to maintain the list's structure.
 */
void insertNode(Node* &head, Node* &tail, int data) {
    if(!head) {
        head = new Node(data);
        tail = head;
    }
    else {
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}

/**
 * Adds two numbers represented by linked lists `num1` and `num2`.
 * Each node represents a single digit, and the digits are stored in reverse order.
 * This function handles addition digit by digit, propagating any carry.
 */
Node *addTwoNumbers(Node *num1, Node *num2) {
    Node* newHead = NULL; // Head of the resultant list.
    Node* newTail = NULL; // Tail pointer to insert new nodes at the end.

    int addSum = 0, carry = 0;

    // Process both lists while nodes are available in `num1` and `num2`.
    while(num1 != NULL && num2 != NULL) {
        addSum = (num1->data + num2->data + carry);
        carry = addSum / 10; // Compute carry for the next digit.

        insertNode(newHead, newTail, (addSum % 10)); // Insert the current digit in the result.
        num1 = num1->next; // Move to the next digit in `num1`.
        num2 = num2->next; // Move to the next digit in `num2`.
    }

    // Process any remaining nodes in `num1`.
    while(num1 != NULL) {
        addSum = (num1->data + carry);
        carry = addSum / 10;

        insertNode(newHead, newTail, (addSum % 10));
        num1 = num1->next;
    }

    // Process any remaining nodes in `num2`.
    while(num2 != NULL) {
        addSum = (num2->data + carry);
        carry = addSum / 10;

        insertNode(newHead, newTail, (addSum % 10));
        num2 = num2->next;
    }

    // If there's any carry left, create a new node for it.
    if(carry) {
        insertNode(newHead, newTail, carry);
    }

    return newHead; // Return the head of the resultant list.
}

/**
 * Utility function to print a linked list.
 */
void printList(Node* head) {
    while(head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

/**
 * Main function to test the `addTwoNumbers` implementation with three test cases.
 */
int main() {
    // Test Case 1
    Node* num1 = NULL;
    Node* num1Tail = NULL;
    insertNode(num1, num1Tail, 2);
    insertNode(num1, num1Tail, 4);
    insertNode(num1, num1Tail, 3);

    Node* num2 = NULL;
    Node* num2Tail = NULL;
    insertNode(num2, num2Tail, 5);
    insertNode(num2, num2Tail, 6);
    insertNode(num2, num2Tail, 4);

    Node* result = addTwoNumbers(num1, num2);
    cout << "Test Case 1: ";
    printList(result);

    // Test Case 2
    num1 = NULL;
    num1Tail = NULL;
    insertNode(num1, num1Tail, 0);

    num2 = NULL;
    num2Tail = NULL;
    insertNode(num2, num2Tail, 0);

    result = addTwoNumbers(num1, num2);
    cout << "Test Case 2: ";
    printList(result);

    // Test Case 3
    num1 = NULL;
    num1Tail = NULL;
    insertNode(num1, num1Tail, 9);
    insertNode(num1, num1Tail, 9);
    insertNode(num1, num1Tail, 9);

    num2 = NULL;
    num2Tail = NULL;
    insertNode(num2, num2Tail, 1);

    result = addTwoNumbers(num1, num2);
    cout << "Test Case 3: ";
    printList(result);

    return 0;
}

/*
Time Complexity:
The function processes the nodes of the two input linked lists, num1 and num2. The number of iterations depends on the longer of the two lists. Let n and m be the lengths of num1 and num2 respectively.

1. Processing Nodes of Both Lists:
During the first min(n, m) iterations, the function processes both lists simultaneously.
Afterward, the remaining nodes of the longer list are processed in a separate loop.
Hence, the time complexity of this step is O(max(n,m)).

2. Carry Propagation:
At the end of the iterations, if a carry remains, a constant number of operations are performed to create a new node. This does not affect the overall time complexity.
Thus, the time complexity is O(max(n,m)).

Space Complexity:
1. New Nodes Creation:
The function creates a new linked list to store the sum of the input numbers. In the worst case, a new node is created for every digit of the result.
Additionally, an extra node may be created for a carry at the end, resulting in at most O(max(n,m)+1) nodes.

2. Auxiliary Space:
The function uses a constant amount of auxiliary space for variables like addSum, carry, newHead, newTail, etc.
Thus, the space complexity is O(max(n,m)), as the dominant factor is the memory used for the new linked list.
*/