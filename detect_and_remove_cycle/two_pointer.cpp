#include <iostream>
using namespace std;

// Definition of a Node in the linked list
class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = nullptr;
    }

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

// Function to remove a loop in a linked list
Node* removeLoop(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        // If the list is empty or contains only one node, there's no loop
        return head;
    }

    // Slow Pointer - Moves one node at a time
    Node* slow = head;

    // Fast Pointer - Moves two nodes at a time
    Node* fast = head;

    // Detecting the cycle in the list
    while (true) {
        if (fast == nullptr || fast->next == nullptr) {
            // No cycle in the list
            return head;
        }

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Cycle found
            break;
        }
    }

    // Reset fast pointer to head to find the start of the cycle
    fast = head;

    // Start will eventually point to the start of the cycle
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    Node* start = slow;

    // Finding the node just before the start of the cycle
    Node* cur = start;
    while (true) {
        if (cur->next == start) {
            // Breaking the cycle
            cur->next = nullptr;
            return head;
        }
        cur = cur->next;
    }
}

// Helper function to create a loop in the linked list
void createLoop(Node* head, int position) {
    if (position == 0) return;

    Node* temp = head;
    Node* loopStart = nullptr;
    int index = 1;

    while (temp->next != nullptr) {
        if (index == position) {
            loopStart = temp;
        }
        temp = temp->next;
        index++;
    }
    temp->next = loopStart;
}

// Helper function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    int count = 0; // To prevent infinite loops in case of cycles
    while (temp != nullptr && count < 20) {
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
    }
    if (temp != nullptr) {
        cout << "(Cycle Detected)";
    } else {
        cout << "NULL";
    }
    cout << endl;
}

// Main function with test cases
int main() {
    // Test Case 1: Linked list with no loop
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    cout << "Test Case 1 - Before Removing Loop: ";
    printList(head1);
    head1 = removeLoop(head1);
    cout << "Test Case 1 - After Removing Loop: ";
    printList(head1);
    cout << endl;

    // Test Case 2: Linked list with a loop at position 2
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(4);
    createLoop(head2, 2);
    cout << "Test Case 2 - Before Removing Loop: ";
    printList(head2);
    head2 = removeLoop(head2);
    cout << "Test Case 2 - After Removing Loop: ";
    printList(head2);
    cout << endl;

    // Test Case 3: Single-node linked list with a loop
    Node* head3 = new Node(1);
    head3->next = head3; // Self-loop
    cout << "Test Case 3 - Before Removing Loop: ";
    printList(head3);
    head3 = removeLoop(head3);
    cout << "Test Case 3 - After Removing Loop: ";
    printList(head3);

    return 0;
}

/*
Time Complexity:
The time complexity of the two-pointer approach to remove a loop in a linked list is O(n), where n is the number of nodes in the linked list. This complexity arises because, in the worst case, both the slow and fast pointers traverse the entire list to detect and remove the loop.

Space Complexity:
The space complexity of the approach is O(1), as it only uses two pointers (slow and fast) and a few auxiliary variables without requiring any additional data structures. This ensures an efficient and memory-optimized solution.
*/