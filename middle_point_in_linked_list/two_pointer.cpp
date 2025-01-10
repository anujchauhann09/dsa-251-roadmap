#include <iostream>
using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node *next;
    Node() {
        this->data = 0;
        next = NULL;
    }
    Node(int data) {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

// Function to find the middle element
Node *findMiddle(Node *head) {
    Node *slow = head;
    Node *fast = head;

    // Traverse the list with two pointers: slow and fast
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // Return the slow pointer, which points to the middle
}

int main() {
    // Test Case 1: Odd-length list
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    
    Node *middle1 = findMiddle(head1);
    cout << "Middle Element (Test Case 1): " << middle1->data << endl; // Expected Output: 3

    // Test Case 2: Even-length list
    Node *head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(4);
    
    Node *middle2 = findMiddle(head2);
    cout << "Middle Element (Test Case 2): " << middle2->data << endl; // Expected Output: 3

    // Test Case 3: Single node list
    Node *head3 = new Node(1);
    
    Node *middle3 = findMiddle(head3);
    cout << "Middle Element (Test Case 3): " << middle3->data << endl; // Expected Output: 1
    
    return 0;
}

/*
Time Complexity:
The time complexity of this approach is O(n), where n is the number of nodes in the linked list. This is because the algorithm uses two pointers, slow and fast, which traverse the list only once. The fast pointer moves two steps at a time, and the slow pointer moves one step at a time, so the total number of iterations is proportional to the number of nodes in the list.

Space Complexity:
The space complexity is O(1) because the algorithm uses a constant amount of extra space, only storing the slow and fast pointers, regardless of the size of the linked list. No additional data structures are created or used during the execution. Therefore, the space used by the algorithm remains constant, independent of the list size.
*/