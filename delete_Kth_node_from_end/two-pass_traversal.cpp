#include <bits/stdc++.h>
using namespace std;

// Definition of Node class representing a singly linked list node
class Node {
public:
    int data;       // Data field to store the value of the node
    Node *next;     // Pointer to the next node in the linked list

    // Default constructor initializing data to 0 and next to NULL
    Node() {
        this->data = 0;
        this->next = NULL;
    }

    // Constructor to initialize a node with a given value
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Constructor to initialize a node with a given value and next pointer
    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

// Function to remove the Kth node from the end of a linked list
Node* removeKthNode(Node* head, int K) {
    // If the list is empty, return the head as-is
    if (!head) {
        return head;
    }

    // Calculate the total length of the linked list
    Node* temp = head;
    int length = 0;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    // Calculate the position of the node to be deleted (1-based index)
    int deletionPos = length - K + 1;

    // Reset temp to head and initialize pointers for traversal
    temp = head;
    Node *current = NULL, *prev = NULL, *next = NULL;
    int count = 0;

    // Traverse the list to the position of the node to delete
    while (count < deletionPos) {
        count++;
        prev = current;
        current = temp;
        next = temp->next;
        temp = temp->next;
    }

    // If the node to delete is the head, update the head pointer
    if (!prev) {
        head = head->next;
        delete current; // Free memory for the removed node
        return head;
    }

    // Otherwise, update the pointers to remove the node
    prev->next = next;
    delete current; // Free memory for the removed node

    return head;
}

// Utility function to insert a node at the end of the linked list
void insertNode(Node*& head, int data) {
    if (!head) {
        head = new Node(data);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

// Utility function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main function to test the removeKthNode function
int main() {
    // Test Case 1: Remove the 2nd node from the end of the list
    Node* head1 = NULL;
    insertNode(head1, 1);
    insertNode(head1, 2);
    insertNode(head1, 3);
    insertNode(head1, 4);
    insertNode(head1, 5);
    cout << "Original List (Test Case 1): ";
    printList(head1);
    head1 = removeKthNode(head1, 2);
    cout << "After Removing 2nd Node from End: ";
    printList(head1);

    // Test Case 2: Remove the head node (3rd node from the end)
    Node* head2 = NULL;
    insertNode(head2, 10);
    insertNode(head2, 20);
    insertNode(head2, 30);
    cout << "Original List (Test Case 2): ";
    printList(head2);
    head2 = removeKthNode(head2, 3);
    cout << "After Removing 3rd Node from End: ";
    printList(head2);

    // Test Case 3: Remove the last node from the list
    Node* head3 = NULL;
    insertNode(head3, 7);
    insertNode(head3, 8);
    cout << "Original List (Test Case 3): ";
    printList(head3);
    head3 = removeKthNode(head3, 1);
    cout << "After Removing Last Node: ";
    printList(head3);

    return 0;
}

/*
Time Complexity:
The time complexity of the removeKthNode function is O(N), where N is the number of nodes in the linked list. This is because the function involves two main traversals:

1. The first traversal calculates the length of the linked list, which takes O(N) time.
2. The second traversal goes to the K-th node from the end, which again takes O(N) time in the worst case. However, this traversal does not overlap with the first one and is linear.
Thus, the overall time complexity is O(N) for the function.

Space Complexity:
The space complexity is O(1) because the function does not use any additional data structures to store elements, and it manipulates the linked list directly using pointers. Only a constant amount of space is used for variables such as temp, current, prev, and next.
*/