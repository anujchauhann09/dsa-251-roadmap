#include <bits/stdc++.h>
using namespace std;

/****************************************************************
    Following is the class structure of the LinkedListNode class:
*****************************************************************/

template <typename T>
class LinkedListNode {
public:
    T data;                           // Data of the current node
    LinkedListNode<T>* next;          // Pointer to the next node

    LinkedListNode(T data) {          // Constructor to initialize the node
        this->data = data;
        this->next = NULL;
    }
};

/****************************************************************
    Function to reverse a linked list iteratively.
*****************************************************************/

LinkedListNode<int>* reverseLinkedList(LinkedListNode<int>* head) {
    LinkedListNode<int> *current = head, *prev = NULL, *next = NULL;

    // Traverse the linked list while reversing pointers
    while (current != NULL) {
        next = current->next;        // Store the next node
        current->next = prev;        // Reverse the link
        prev = current;              // Move prev to the current node
        current = next;              // Move to the next node
    }

    return prev;                     // New head of the reversed list
}

/****************************************************************
    Helper function to print the linked list.
*****************************************************************/

void printList(LinkedListNode<int>* head) {
    LinkedListNode<int>* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

/****************************************************************
    Helper function to create a linked list from a vector of values.
*****************************************************************/

LinkedListNode<int>* createList(vector<int> values) {
    if (values.empty()) return NULL;

    LinkedListNode<int>* head = new LinkedListNode<int>(values[0]);
    LinkedListNode<int>* temp = head;
    for (int i = 1; i < values.size(); i++) {
        temp->next = new LinkedListNode<int>(values[i]);
        temp = temp->next;
    }
    return head;
}

/****************************************************************
    Main function with three test cases.
*****************************************************************/

int main() {
    // Test Case 1: List with multiple elements
    vector<int> values1 = {1, 2, 3, 4, 5};
    LinkedListNode<int>* head1 = createList(values1);
    cout << "Original List (Test Case 1): ";
    printList(head1);
    head1 = reverseLinkedList(head1);
    cout << "Reversed List (Test Case 1): ";
    printList(head1);

    // Test Case 2: List with a single element
    vector<int> values2 = {42};
    LinkedListNode<int>* head2 = createList(values2);
    cout << "Original List (Test Case 2): ";
    printList(head2);
    head2 = reverseLinkedList(head2);
    cout << "Reversed List (Test Case 2): ";
    printList(head2);

    // Test Case 3: Empty list
    vector<int> values3 = {};
    LinkedListNode<int>* head3 = createList(values3);
    cout << "Original List (Test Case 3): ";
    printList(head3);
    head3 = reverseLinkedList(head3);
    cout << "Reversed List (Test Case 3): ";
    printList(head3);

    return 0;
}

/*
Time Complexity:
The time complexity of the iterative approach to reversing a linked list is O(n), where n is the number of nodes in the linked list. This is because we traverse each node exactly once to reverse the links.

Space Complexity:
The space complexity is O(1) since no additional data structures are used, and the reversal is performed in place by manipulating pointers, requiring only a constant amount of extra memory for the prev, current, and next pointers.
*/