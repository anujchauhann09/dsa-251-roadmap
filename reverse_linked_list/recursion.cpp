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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Base condition
    if (head == NULL || head->next == NULL) 
	{
        // Return the last node.
        return head;
    }

    // Reverse the rest of Linked List
    LinkedListNode<int> *rest = reverseLinkedList(head->next);

    // Changing the reference of next node next to itself
    head->next->next = head;

    // Assign current node next to NULL.
    head->next = NULL;

    // Return the reverse Linked List.
    return rest;
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
The time complexity of the recursive approach to reversing a linked list is O(n), where n is the number of nodes in the linked list. In each recursive call, the function processes one node (the current node), and then proceeds to the next node in the list. Since every node in the list is visited exactly once during the recursion, the total number of recursive calls will be n. Thus, the overall time complexity is O(n).

Space Complexity:
The space complexity of the recursive approach is O(n) as well. This is because each recursive call adds a new frame to the call stack. Since there are n recursive calls (one for each node), the space required for the call stack grows linearly with the number of nodes in the linked list. Hence, the space complexity is O(n), where n is the number of nodes in the list.
*/