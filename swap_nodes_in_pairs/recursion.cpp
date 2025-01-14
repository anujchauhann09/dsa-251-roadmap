#include <bits/stdc++.h>
using namespace std;

// Definition for a Node in the linked list
class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to swap nodes in pairs recursively
Node* pairsSwap(Node* head) {
    // Base case: If the list is empty or has only one node, return as is
    if (!head || !head->next) {
        return head;
    }

    // Define pointers for the first two nodes and the remaining list
    Node *first = head;              // First node in the pair
    Node *second = head->next;       // Second node in the pair
    Node *remainingNode = second->next; // Remaining nodes after the current pair

    // New head of the swapped list will be the second node
    Node *newHead = second;

    // Adjust pointers to swap the current pair
    second->next = first;

    // Recursively call the function for the remaining list
    first->next = pairsSwap(remainingNode);

    // Return the new head of the swapped list
    return newHead;
}

// Helper function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Helper function to create a linked list from a vector of values
Node* createList(vector<int> values) {
    if (values.empty()) return NULL;

    Node* head = new Node(values[0]);
    Node* temp = head;

    for (size_t i = 1; i < values.size(); i++) {
        temp->next = new Node(values[i]);
        temp = temp->next;
    }
    return head;
}

// Main function to test the pairsSwap function
int main() {
    // Test Case 1
    vector<int> values1 = {1, 2, 3, 4};
    Node* head1 = createList(values1);
    cout << "Original List 1: ";
    printList(head1);
    head1 = pairsSwap(head1);
    cout << "Swapped List 1: ";
    printList(head1);

    // Test Case 2
    vector<int> values2 = {1, 2, 3};
    Node* head2 = createList(values2);
    cout << "Original List 2: ";
    printList(head2);
    head2 = pairsSwap(head2);
    cout << "Swapped List 2: ";
    printList(head2);

    // Test Case 3
    vector<int> values3 = {1};
    Node* head3 = createList(values3);
    cout << "Original List 3: ";
    printList(head3);
    head3 = pairsSwap(head3);
    cout << "Swapped List 3: ";
    printList(head3);

    return 0;
}

/*
Time Complexity:
The time complexity of the recursive pairsSwap function is O(n), where n is the number of nodes in the linked list. This is because the function processes two nodes at a time, making a constant amount of work for each pair, and recurses through the entire list exactly once.

Space Complexity:
The space complexity is O(n) due to the recursive calls. Each recursive call adds a new frame to the call stack, and since the depth of recursion can be up to the number of nodes in the list, the space complexity is proportional to the size of the list.

Both time and space complexities are linear in the number of nodes, as each node is visited exactly once, and recursion creates a stack frame for each node.
*/