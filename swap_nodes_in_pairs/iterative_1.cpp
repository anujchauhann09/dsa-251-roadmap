#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class for a singly linked list.
class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to swap data between adjacent pairs of nodes in the linked list.
Node* pairsSwap(Node *head) {
    // If the list is empty or has only one node, no swapping is needed.
    if (!head) {
        return head;
    }

    Node* prev = head;         // Pointer to the first node in the current pair.
    Node* curr = head->next;   // Pointer to the second node in the current pair.

    // Traverse the list and swap data between adjacent nodes.
    while (curr != NULL) {
        swap(prev->data, curr->data); // Swap data between the two nodes.

        prev = curr->next; // Move `prev` to the next pair's first node.
        
        // If there's no next node, set `curr` to NULL.
        if (!prev) {
            curr = NULL;
        } else {
            curr = curr->next; // Move `curr` to the next pair's second node.
        }
    }

    return head; // Return the updated head of the linked list.
}

// Helper function to print the linked list.
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create a linked list from a vector of values.
Node* createList(vector<int> values) {
    if (values.empty()) return NULL;

    Node* head = new Node(values[0]);
    Node* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new Node(values[i]);
        current = current->next;
    }
    return head;
}

// Main function with test cases.
int main() {
    // Test Case 1: List with an even number of nodes.
    Node* list1 = createList({1, 2, 3, 4});
    cout << "Original List 1: ";
    printList(list1);
    list1 = pairsSwap(list1);
    cout << "Swapped List 1: ";
    printList(list1);

    // Test Case 2: List with an odd number of nodes.
    Node* list2 = createList({10, 20, 30, 40, 50});
    cout << "Original List 2: ";
    printList(list2);
    list2 = pairsSwap(list2);
    cout << "Swapped List 2: ";
    printList(list2);

    // Test Case 3: List with only one node.
    Node* list3 = createList({99});
    cout << "Original List 3: ";
    printList(list3);
    list3 = pairsSwap(list3);
    cout << "Swapped List 3: ";
    printList(list3);

    return 0;
}
 
/*
Time Complexity:
The time complexity (TC) of the pairsSwap function is O(n), where n is the number of nodes in the linked list. This is because the function traverses the linked list once, swapping the data of adjacent nodes during each iteration. Each operation of swapping the data and moving the pointers involves constant time, and since the traversal is linear, the overall time complexity is proportional to the number of nodes in the list.

Space Complexity:
The space complexity (SC) is O(1) because the function performs all operations in-place without using any additional memory for data structures like arrays, stacks, or recursion. Only a few pointers (prev, curr) are used, which occupy constant space regardless of the size of the linked list.

This ensures the function is highly efficient both in terms of execution time and memory usage. It is suitable for handling large linked lists due to its linear time complexity and constant space requirements.
*/