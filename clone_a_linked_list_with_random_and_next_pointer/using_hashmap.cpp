#include <bits/stdc++.h>
using namespace std;

// Definition of a Linked List Node
template <typename T>
class LinkedListNode {
public:
    T data; // Node data
    LinkedListNode<T> *next;   // Pointer to the next node
    LinkedListNode<T> *random; // Pointer to a random node in the list

    // Constructor to initialize a node
    LinkedListNode(T data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

// Function to clone a linked list with next and random pointers
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head) {
    if (!head) return NULL; // Handle empty list case

    unordered_map<LinkedListNode<int>*, LinkedListNode<int>*> nodeMapping;

    // Step 1: Create a copy of each node and store mapping of original -> cloned nodes
    LinkedListNode<int>* originalCurr = head;
    while (originalCurr) {
        nodeMapping[originalCurr] = new LinkedListNode<int>(originalCurr->data);
        originalCurr = originalCurr->next;
    }

    // Step 2: Assign next and random pointers to cloned nodes
    originalCurr = head;
    while (originalCurr) {
        LinkedListNode<int>* cloneCurr = nodeMapping[originalCurr];
        cloneCurr->next = nodeMapping[originalCurr->next];  // Assign cloned next pointer
        cloneCurr->random = nodeMapping[originalCurr->random]; // Assign cloned random pointer
        originalCurr = originalCurr->next;
    }

    // Return the head of the cloned linked list
    return nodeMapping[head];
}

// Utility function to print a linked list
void printList(LinkedListNode<int>* head) {
    LinkedListNode<int>* temp = head;
    while (temp) {
        cout << "Node: " << temp->data;
        cout << ", Random: " << (temp->random ? to_string(temp->random->data) : "NULL") << endl;
        temp = temp->next;
    }
    cout << "----------------------\n";
}

// Test cases for the clone function
int main() {
    // Test Case 1: Simple List with Random Pointers
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

    // Test Case 2: Single Node with No Random Pointer
    LinkedListNode<int>* head2 = new LinkedListNode<int>(10);
    cout << "Original List 2:\n";
    printList(head2);

    LinkedListNode<int>* clonedList2 = cloneRandomList(head2);
    cout << "Cloned List 2:\n";
    printList(clonedList2);

    // Test Case 3: Two Nodes with Random Pointers
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
Step 1 (Cloning nodes and storing in hashmap) → O(N)
Step 2 (Assigning next and random pointers) → O(N)
Total Complexity = O(N) + O(N) = O(N)
Since we iterate over the list twice, the overall time complexity is O(N).

Space Complexity:
We use an unordered_map (nodeMapping) to store the mapping of original nodes to cloned nodes, which takes O(N) space.
Besides that, only a few extra pointers are used (constant space O(1)), but since the hashmap dominates, the overall space complexity is O(N).
*/