#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node

    // Constructor to initialize a node with data
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Helper function to perform the pairwise swap of two nodes
Node* swap(Node* prev, Node* curr)
{
    // Adjusting the pointers to swap the nodes
    prev->next = curr->next;
    curr->next = prev;

    // Returning the new head of the swapped pair
    return curr;
}

// Function to perform pairwise swapping of nodes in the linked list
Node* pairsSwap(Node* head)
{
    // Creating a dummy node to simplify handling the head
    Node *dummyNode = new Node(-1);
    dummyNode->next = head;
    Node *curr = dummyNode;

    // Loop to traverse the list and swap adjacent nodes
    while (curr->next != NULL && curr->next->next != NULL)
    {
        // Perform the swap for the current pair
        curr->next = swap(curr->next, curr->next->next);

        // Move to the next pair
        curr = curr->next->next;
    }

    // Return the new head of the swapped list
    return dummyNode->next;
}

// Helper function to print the linked list
void printList(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function to test the pairsSwap function
int main()
{
    // Test Case 1: List with even number of nodes
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);

    cout << "Original List (Test Case 1): ";
    printList(head1);
    head1 = pairsSwap(head1);
    cout << "Swapped List (Test Case 1): ";
    printList(head1);

    // Test Case 2: List with odd number of nodes
    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(7);
    head2->next->next->next = new Node(8);
    head2->next->next->next->next = new Node(9);

    cout << "\nOriginal List (Test Case 2): ";
    printList(head2);
    head2 = pairsSwap(head2);
    cout << "Swapped List (Test Case 2): ";
    printList(head2);

    // Test Case 3: Single-node list
    Node* head3 = new Node(10);

    cout << "\nOriginal List (Test Case 3): ";
    printList(head3);
    head3 = pairsSwap(head3);
    cout << "Swapped List (Test Case 3): ";
    printList(head3);

    return 0;
}

/*
Time Complexity:
The time complexity (TC) of the pairsSwap function is O(n), where n is the number of nodes in the linked list. This is because the algorithm traverses the entire linked list once, performing a constant amount of work for each node pair. Each iteration processes two nodes, so the total number of iterations is proportional to the size of the list.

Space Complexity:
The space complexity (SC) is O(1) since the algorithm operates in-place and does not use any extra data structures that scale with the size of the input. A constant amount of additional memory is used for temporary pointers like curr, dummyNode, and the helper function's parameters.

Thus, the function is efficient both in terms of time and space. It achieves the swapping of adjacent pairs of nodes in a single traversal without requiring auxiliary storage, making it optimal for this task.
*/