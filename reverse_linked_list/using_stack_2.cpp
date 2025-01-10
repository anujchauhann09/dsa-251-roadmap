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
    // Base case: If the list is empty or has only one element, return the head as is
    if(!head || !head->next) {
        return head;
    }

    // Create a stack to store the nodes of the linked list
    stack<LinkedListNode<int>*> st;

    // Traverse the linked list and push each node onto the stack
    while(head != NULL) {
        st.push(head);  // Push the current node onto the stack
        head = head->next;  // Move to the next node in the list
    }

    // After pushing all nodes onto the stack, set the head to the top of the stack
    if(st.size() != 0) {
        head = st.top();  // The last node (top of the stack) becomes the new head of the list
    }

    // Pop nodes from the stack and reverse their links
    while(!st.empty()) {
        LinkedListNode<int> *currentNode = st.top();  // Get the top node from the stack
        st.pop();  // Remove the top node from the stack

        // If this is the last node in the stack, set its 'next' to NULL (end of the list)
        if(st.size() == 0) {
            currentNode->next = NULL;
        }
        else {
            // Otherwise, point the 'next' of the current node to the next node in the stack
            currentNode->next = st.top();
        }
    }

    // Return the new head of the reversed list
    return head;
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
The time complexity is O(n), where n is the number of nodes in the linked list. This is because we traverse the list twice: once to push the nodes onto the stack and once to pop them and reverse the links.

Space Complexity:
The space complexity of this approach is O(n), where n is the number of nodes in the linked list. This is due to the additional space used by the stack to store the data of all nodes.
*/