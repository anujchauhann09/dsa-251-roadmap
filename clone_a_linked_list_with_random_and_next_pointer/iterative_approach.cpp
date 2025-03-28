#include <bits/stdc++.h>
using namespace std;

// Definition of a Linked List Node
template <typename T>
class LinkedListNode {
public:
    T data; // Data stored in the node
    LinkedListNode<T> *next;   // Pointer to the next node
    LinkedListNode<T> *random; // Pointer to a random node in the list

    // Constructor to initialize a new node
    LinkedListNode(T data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

// Function to append a node to the cloned list
void appendNodeToClonedList(LinkedListNode<int>* &clonedHead, LinkedListNode<int>* &clonedTail, LinkedListNode<int>* originalNode) {
    // If the cloned list is empty, initialize the first node
    if (!clonedHead) {
        clonedHead = new LinkedListNode<int>(originalNode->data);
        clonedTail = clonedHead;
        return;
    }

    // Otherwise, create a new node and attach it to the cloned list
    LinkedListNode<int> *newNode = new LinkedListNode<int>(originalNode->data);
    clonedTail->next = newNode;
    clonedTail = newNode;
}

// Function to copy the random pointer from the original list to the cloned list
void copyRandomPointer(LinkedListNode<int>* clonedNode, LinkedListNode<int>* originalNode) {
    clonedNode->random = originalNode->random;
}

// Function to clone a linked list with next and random pointers
LinkedListNode<int>* cloneRandomList(LinkedListNode<int>* originalHead) {
    if (!originalHead) return nullptr; // Handle empty list case

    LinkedListNode<int>* clonedHead = nullptr; // Head of the cloned list
    LinkedListNode<int>* clonedTail = nullptr; // Tail of the cloned list
    LinkedListNode<int>* originalCurrent = originalHead; // Pointer to traverse the original list
    LinkedListNode<int>* clonedCurrent = nullptr; // Pointer to traverse the cloned list

    // Step 1: Clone the linked list structure (next pointers)
    while (originalCurrent) {
        appendNodeToClonedList(clonedHead, clonedTail, originalCurrent);
        originalCurrent = originalCurrent->next;
    }

    // Step 2: Copy the random pointers
    originalCurrent = originalHead;
    clonedCurrent = clonedHead;
    
    while (originalCurrent) {
        copyRandomPointer(clonedCurrent, originalCurrent);
        originalCurrent = originalCurrent->next;
        clonedCurrent = clonedCurrent->next;
    }

    return clonedHead; // Return the head of the cloned list
}

// Function to print the linked list along with random pointers
void printList(LinkedListNode<int>* head) {
    LinkedListNode<int>* temp = head;
    while (temp) {
        cout << "Node: " << temp->data;
        cout << ", Random: " << (temp->random ? to_string(temp->random->data) : "NULL") << endl;
        temp = temp->next;
    }
    cout << "----------------------\n";
}

// Main function to test the clone function
int main() {
    // Test Case 1: Linked list with three nodes and random pointers
    LinkedListNode<int>* head1 = new LinkedListNode<int>(1);
    head1->next = new LinkedListNode<int>(2);
    head1->next->next = new LinkedListNode<int>(3);

    head1->random = head1->next->next;  // 1 -> 3
    head1->next->random = head1;        // 2 -> 1
    head1->next->next->random = head1->next; // 3 -> 2

    cout << "Original List 1:\n";
    printList(head1);

    LinkedListNode<int>* clonedList1 = cloneRandomList(head1);
    cout << "Cloned List 1:\n";
    printList(clonedList1);

    // Test Case 2: Single node with no random pointer
    LinkedListNode<int>* head2 = new LinkedListNode<int>(10);
    cout << "Original List 2:\n";
    printList(head2);

    LinkedListNode<int>* clonedList2 = cloneRandomList(head2);
    cout << "Cloned List 2:\n";
    printList(clonedList2);

    // Test Case 3: Two nodes with cross-linked random pointers
    LinkedListNode<int>* head3 = new LinkedListNode<int>(5);
    head3->next = new LinkedListNode<int>(7);
    head3->random = head3->next;  // 5 -> 7
    head3->next->random = head3;  // 7 -> 5

    cout << "Original List 3:\n";
    printList(head3);

    LinkedListNode<int>* clonedList3 = cloneRandomList(head3);
    cout << "Cloned List 3:\n";
    printList(clonedList3);

    return 0;
}

/*
Time Complexity:
Step 1 (Cloning list structure - next pointers) → O(N)
Step 2 (Copying random pointers) → O(N)
Overall Complexity = O(N) + O(N) = O(N)
Since we traverse the linked list twice, the overall time complexity is O(N).

Space Complexity:
We create a new node for each original node, which takes O(N) extra space.
The total space used is O(N).
*/