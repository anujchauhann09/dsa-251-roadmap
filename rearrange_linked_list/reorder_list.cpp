#include <bits/stdc++.h>
using namespace std;

// Template class for a singly linked list node.
template <typename T>
class Node {
public:
    T data;           // The value stored in the node.
    Node* next;       // Pointer to the next node in the list.

    // Constructor to initialize a node with given data.
    Node(T data) {
        this->data = data;
        next = NULL;
    }

    // Destructor to free memory of subsequent nodes recursively.
    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

// Function to find the middle node of the linked list using slow and fast pointers.
Node<int>* findMiddle(Node<int>* head) {
    Node<int>* slow = head;
    Node<int>* fast = head;
    // Move 'slow' one step and 'fast' two steps until 'fast' reaches the end.
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to reverse a linked list.
Node<int>* reverseList(Node<int>* head) {
    Node<int>* prev = NULL;
    Node<int>* curr = head;
    // Reverse the pointers of each node iteratively.
    while (curr) {
        Node<int>* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Function to rearrange the linked list such that nodes are in the order:
// first node, last node, second node, second last node, and so on.
Node<int>* rearrangeList(Node<int>* head) {
    if (!head || !head->next) {
        return head;  // If the list is empty or has only one node, no rearrangement is needed.
    }

    // Find the middle of the list.
    Node<int>* mid = findMiddle(head);

    // Reverse the second half of the list.
    Node<int>* secondHalf = reverseList(mid->next);
    mid->next = NULL; // Split the list into two halves.

    Node<int>* firstHalf = head;
    // Merge the two halves by alternating nodes from each half.
    while (firstHalf && secondHalf) {
        Node<int>* tempFirst = firstHalf->next;
        Node<int>* tempSecond = secondHalf->next;

        firstHalf->next = secondHalf;
        secondHalf->next = tempFirst;

        firstHalf = tempFirst;
        secondHalf = tempSecond;
    }
    return head;
}

// Helper function to print the linked list.
void printList(Node<int>* head) {
    Node<int>* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Helper function to create a linked list from a vector of integers.
Node<int>* createList(const vector<int>& values) {
    if (values.empty()) return NULL;
    Node<int>* head = new Node<int>(values[0]);
    Node<int>* current = head;
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new Node<int>(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Test Case 1: Linked list with an odd number of nodes.
    vector<int> values1 = {1, 2, 3, 4, 5};
    Node<int>* list1 = createList(values1);
    cout << "Original List 1: ";
    printList(list1);
    list1 = rearrangeList(list1);
    cout << "Rearranged List 1: ";
    printList(list1);
    delete list1;  // Free memory allocated for list1.

    cout << "\n----------------------\n";

    // Test Case 2: Linked list with an even number of nodes.
    vector<int> values2 = {10, 20, 30, 40, 50, 60};
    Node<int>* list2 = createList(values2);
    cout << "Original List 2: ";
    printList(list2);
    list2 = rearrangeList(list2);
    cout << "Rearranged List 2: ";
    printList(list2);
    delete list2;  // Free memory allocated for list2.

    cout << "\n----------------------\n";

    // Test Case 3: Linked list with a single node.
    vector<int> values3 = {100};
    Node<int>* list3 = createList(values3);
    cout << "Original List 3: ";
    printList(list3);
    list3 = rearrangeList(list3);
    cout << "Rearranged List 3: ";
    printList(list3);
    delete list3;  // Free memory allocated for list3.

    return 0;
}

/*
Time Complexity:
This approach runs in linear time relative to the number of nodes because it makes a fixed number of passes through the list—one to locate the middle, one to reverse the second half, and one to merge the two halves—resulting in O(n) time complexity. 

Space Complexity:
Additionally, since the reordering is done in place using only a few pointer variables, the extra space required remains constant, leading to an O(1) space complexity.
*/
