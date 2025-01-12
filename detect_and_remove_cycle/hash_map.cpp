#include <bits/stdc++.h>
using namespace std;

/*************************************************
    Definition of the Node class for a linked list.
*************************************************/

class Node {
public:
    int data;        // Value stored in the node
    Node *next;      // Pointer to the next node

    // Constructor to initialize a node with data and no next node
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Constructor to initialize a node with data and a next node
    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

/*************************************************
    Function to remove a loop from a linked list.
*************************************************/

Node *removeLoop(Node *head) {
    // If the list is empty or contains only one node, no loop is possible.
    if (!head || !head->next) {
        return head;
    }

    // Map to keep track of visited nodes.
    unordered_map<Node*, bool> visitedNodes;

    Node *temp = head;  // Pointer to traverse the list
    Node *prev = NULL;  // Pointer to store the previous node

    // Traverse the list until the end is reached
    while (temp) {
        // If the current node is not yet visited
        if (!visitedNodes.count(temp)) {
            visitedNodes[temp] = true;  // Mark the node as visited
            prev = temp;               // Update the previous node
        } else {
            // If the node is already visited, a loop is detected.
            prev->next = NULL;  // Break the loop by setting the previous node's next to NULL
            break;
        }
        temp = temp->next;  // Move to the next node
    }

    return head;  // Return the head of the modified list
}

/*************************************************
    Function to print a linked list.
*************************************************/
void printList(Node *head) {
    Node *temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

/*************************************************
    Main function to test the removeLoop function.
*************************************************/

int main() {
    // Test case 1: Linked list with a loop
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = head1->next;  // Creates a loop
    head1 = removeLoop(head1);  // Remove the loop
    cout << "Test case 1 - After removing the loop: ";
    printList(head1);

    // Test case 2: Linked list with no loop
    Node *head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = new Node(30);
    head2->next->next->next = new Node(40);
    head2 = removeLoop(head2);  // Should handle gracefully
    cout << "Test case 2 - No loop present: ";
    printList(head2);

    // Test case 3: Single node with a self-loop
    Node *head3 = new Node(5);
    head3->next = head3;  // Self-loop
    head3 = removeLoop(head3);  // Remove the loop
    cout << "Test case 3 - Single node with a self-loop: ";
    printList(head3);

    return 0;
}

/*
Time Complexity:
The function traverses the entire linked list node by node, which requires O(n) time, where n is the number of nodes in the list. For each node, the map operations (insertion and lookup) take O(1) on average. Therefore, the overall time complexity of the function is: T(n)=O(n) where n is the total number of nodes in the linked list.

Space Complexity:
The unordered_map is used to store the visited nodes. In the worst case (i.e., when there is no loop in the linked list), all n nodes are stored in the map. Thus, the space complexity is: S(n)=O(n)

Additionally, a constant amount of extra space is used for pointers (temp, prev, etc.), which does not depend on the size of the input and can be ignored in asymptotic analysis.
*/