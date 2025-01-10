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

// Function to reverse a linked list by creating a new reversed list
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Initialize the new head of the reversed list as NULL
    LinkedListNode<int> *newHead = NULL;

    // Traverse the original linked list
    while(head != NULL) {
        // Create a new node with the current node's data
        LinkedListNode<int> *newNode = new LinkedListNode<int>(head->data);

        // Insert the new node at the beginning of the reversed list
        newNode->next = newHead;
        newHead = newNode;

        // Move to the next node in the original list
        head = head->next;
    }

    // Return the head of the reversed list
    return newHead;
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
The time complexity of this approach is O(n), where n is the number of nodes in the linked list. This is because we iterate through the original list exactly once. In each iteration, we create a new node and insert it at the beginning of the reversed list. The insertion and traversal of the linked list are constant time operations, so the overall time complexity remains O(n).

Space Complexity:
The space complexity of this approach is O(n) as well. This is because we create a new linked list with the same number of nodes as the original list. For each node in the original list, we create a new node and store it in the reversed list. Hence, the space used by the new list is proportional to the number of nodes in the original list.
*/