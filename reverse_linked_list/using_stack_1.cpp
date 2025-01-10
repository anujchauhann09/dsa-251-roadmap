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
    // Base case: If the list is empty or has only one element, return the list as is
    if(!head || !head->next) {
        return head;
    }

    // Create a stack to temporarily store the linked list's data
    stack<int> st;
    // Initialize a pointer to traverse the linked list
    LinkedListNode<int> *currentHead = head;

    // Traverse the linked list and push the data of each node onto the stack
    while(currentHead != NULL) {
        st.push(currentHead->data);  // Push the current node's data to the stack
        currentHead = currentHead->next;  // Move to the next node in the list
    }

    // Reset currentHead to the original head of the linked list
    currentHead = head;

    // Pop elements from the stack and assign them back to the linked list nodes
    while(!st.empty()) {
        int data = st.top();  // Get the top element of the stack
        st.pop();  // Remove the top element from the stack

        currentHead->data = data;  // Set the current node's data to the popped value
        currentHead = currentHead->next;  // Move to the next node in the list
    }

    // Return the modified head of the linked list, which is now reversed
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
The time complexity of this approach is O(n), where n is the number of nodes in the linked list. This is because we traverse the list once to push the data to the stack, and then once again to pop the data back into the list.

Space Complexity:
The space complexity of this approach is O(n), where n is the number of nodes in the linked list. This is due to the additional space used by the stack to store the data of all nodes.
*/