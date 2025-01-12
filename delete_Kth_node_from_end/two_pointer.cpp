#include <bits/stdc++.h>
using namespace std;

/**
 * Definition of the Node class.
 * Represents a single node in the linked list.
 */
class Node {
public:
    int data;   // Data stored in the node.
    Node* next; // Pointer to the next node.

    // Default constructor.
    Node() {
        this->data = 0;
        this->next = NULL;
    }

    // Constructor to initialize a node with a given value.
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Constructor to initialize a node with a given value and next pointer.
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

/**
 * Removes the Kth node from the end of the linked list.
 * 
 * @param head - Pointer to the head of the linked list.
 * @param K - The position (from the end) of the node to be removed.
 * @return - Updated head of the linked list after removal.
 */
Node* removeKthNode(Node* head, int K) {
    // Handle edge cases where the list is empty or K is zero.
    if (head == NULL || K == 0) {
        return head;
    }

    // Initialize two pointers: 'slow' and 'fast', both starting at the head.
    Node* slow = head;
    Node* fast = head;

    // Move the 'fast' pointer K steps ahead.
    for (int i = 0; i < K; i++) {
        // If K exceeds the length of the list, handle removal of the head node.
        if (fast->next == NULL) {
            Node* next = head->next;
            delete head; // Free memory of the head node.
            head = next; // Update head pointer to the new head.
            return head;
        }
        fast = fast->next;
    }

    // Move both 'slow' and 'fast' pointers one step at a time
    // until 'fast' reaches the last node.
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // 'slow' is now just before the Kth node from the end.
    Node* toDelete = slow->next; // Node to be deleted.
    slow->next = toDelete->next; // Update the link to skip the deleted node.
    delete toDelete;             // Free memory of the deleted node.

    return head; // Return the updated head pointer.
}

/**
 * Utility function to create and return a linked list
 * from a vector of integers.
 */
Node* createLinkedList(const vector<int>& values) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int value : values) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

/**
 * Utility function to print the linked list.
 */
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

/**
 * Main function with test cases.
 */
int main() {
    // Test Case 1: Remove the 2nd node from the end of the list.
    Node* head1 = createLinkedList({1, 2, 3, 4, 5});
    cout << "Original List: ";
    printLinkedList(head1);
    head1 = removeKthNode(head1, 2);
    cout << "After Removing 2nd Node from End: ";
    printLinkedList(head1);

    // Test Case 2: Remove the last node from the list.
    Node* head2 = createLinkedList({10, 20, 30});
    cout << "\nOriginal List: ";
    printLinkedList(head2);
    head2 = removeKthNode(head2, 1);
    cout << "After Removing Last Node: ";
    printLinkedList(head2);

    // Test Case 3: Remove the head node by specifying K equal to the list length.
    Node* head3 = createLinkedList({7, 14, 21, 28});
    cout << "\nOriginal List: ";
    printLinkedList(head3);
    head3 = removeKthNode(head3, 4);
    cout << "After Removing Head Node: ";
    printLinkedList(head3);

    return 0;
}

/*
Time Complexity:
The time complexity of the removeKthNode function is O(N), where N represents the number of nodes in the linked list. This is because the algorithm traverses the linked list in two stages. In the first stage, the fast pointer is moved forward by K steps, which takes O(K) time. In the second stage, both slow and fast pointers traverse the remaining nodes of the list until the fast pointer reaches the end. This second traversal covers at most the entire list, resulting in an O(N) operation. Combining these, the overall traversal remains linear, as the total work is proportional to the size of the list.

Space Complexity:
The space complexity of the algorithm is O(1) because the function uses only a constant amount of extra space. It employs a few pointers (slow, fast, toDelete) to traverse and manipulate the linked list, but no additional data structures or recursive calls are introduced. This ensures that the memory usage remains constant, regardless of the size of the input linked list.
*/