#include <bits/stdc++.h>
using namespace std;

// Definition of a Node in the linked list.
class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        this->data = 0;
        this->next = NULL;
    }

    // Constructor with data
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Constructor with data and next pointer
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

// Function to remove the Kth node from the end of the linked list.
Node* removeKthNode(Node* head, int K) {
    if (!head) {
        return head; // If the list is empty, return NULL.
    }

    // Stack to store the nodes of the linked list.
    stack<Node*> st;
    Node* temp = head;

    // Push all nodes onto the stack.
    while (temp != NULL) {
        st.push(temp);
        temp = temp->next;
    }

    // Process the stack to find and remove the Kth node from the end.
    while (!st.empty()) {
        Node* currentNode = st.top();
        st.pop();
        K--;

        // If K reaches 0 and the stack is not empty, link the previous node to skip the current node.
        if (!K && !st.empty()) {
            Node* prevNode = st.top();
            prevNode->next = currentNode->next;
            delete currentNode; // Free the memory of the removed node.
            return head;
        }
    }

    // If K reaches 0 and the stack is empty, it means the head is the node to be removed.
    if (!K) {
        Node* newHead = head->next;
        delete head; // Free the memory of the removed head node.
        return newHead;
    }

    return head; // Return the modified head.
}

// Utility function to create a linked list from a vector of integers.
Node* createLinkedList(const vector<int>& values) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int value : values) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Utility function to print a linked list.
void printLinkedList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Test case 1: Remove 2nd node from the end.
    vector<int> values1 = {1, 2, 3, 4, 5};
    Node* head1 = createLinkedList(values1);
    cout << "Original List 1: ";
    printLinkedList(head1);
    head1 = removeKthNode(head1, 2);
    cout << "After removing 2nd node from the end: ";
    printLinkedList(head1);

    // Test case 2: Remove the last node.
    vector<int> values2 = {10, 20, 30, 40};
    Node* head2 = createLinkedList(values2);
    cout << "Original List 2: ";
    printLinkedList(head2);
    head2 = removeKthNode(head2, 1);
    cout << "After removing the last node: ";
    printLinkedList(head2);

    // Test case 3: Remove the head node (K equals the length of the list).
    vector<int> values3 = {7, 14, 21, 28};
    Node* head3 = createLinkedList(values3);
    cout << "Original List 3: ";
    printLinkedList(head3);
    head3 = removeKthNode(head3, 4);
    cout << "After removing the head node: ";
    printLinkedList(head3);

    return 0;
}

/*
Time Complexity:
The removeKthNode function operates on a singly linked list and utilizes a stack to aid in removing the Kth node from the end. The time complexity is determined by the number of nodes in the list (N), as the algorithm performs two primary traversals: the first traversal iterates through the list to push all nodes onto the stack, and the second traversal pops nodes from the stack until the Kth node from the end is found. Both operations involve traversing all N nodes, leading to a time complexity of O(N).

Space Complexity:
The space complexity is influenced by the stack used to store references to the nodes. In the worst-case scenario, the stack will hold all N nodes of the linked list simultaneously. Therefore, the space complexity is O(N) due to the additional memory required for the stack.
*/