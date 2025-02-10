#include <bits/stdc++.h>
using namespace std;

// Template definition for a singly linked list node.
template <typename T>
class LinkedListNode {
public:
    T data;                        // Data stored in the node.
    LinkedListNode<T>* next;       // Pointer to the next node.

    // Constructor: Initializes the node with data and sets next to NULL.
    LinkedListNode(T data) {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int>* reverseLL(LinkedListNode<int>* head) {
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* current = head;
    
    while (current) {
        LinkedListNode<int>* currentNext = current->next;
        current->next = prev;
        prev = current;
        current = currentNext;
    }
    
    return prev;
}

bool isPalindrome(LinkedListNode<int>* head) {
    // An empty list or a single node list is a palindrome.
    if (!head || !head->next) {
        return true;
    }

    // Find the middle of the list using slow and fast pointers.
    LinkedListNode<int>* prev = head;
    LinkedListNode<int>* slow = head;
    LinkedListNode<int>* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // For odd-length lists, skip the middle element.
    if (fast != NULL) {
        slow = slow->next;
    }
    
    // Split the list into two halves.
    prev->next = NULL;
    
    // Reverse the second half of the list.
    LinkedListNode<int>* reverseHead = reverseLL(slow);
    
    // Compare the first half and the reversed second half.
    while (head && reverseHead) {
        if (head->data != reverseHead->data) {
            return false;
        }
        head = head->next;
        reverseHead = reverseHead->next;
    }
    
    return true;
}

LinkedListNode<int>* createLinkedList(const vector<int>& values) {
    if (values.empty()) {
        return NULL;
    }
    
    LinkedListNode<int>* head = new LinkedListNode<int>(values[0]);
    LinkedListNode<int>* current = head;
    
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new LinkedListNode<int>(values[i]);
        current = current->next;
    }
    
    return head;
}

int main() {
    // Test Case 1: Palindrome list [1, 2, 3, 2, 1]
    vector<int> values1 = {1, 2, 3, 2, 1};
    LinkedListNode<int>* head1 = createLinkedList(values1);
    cout << "Test Case 1: " << (isPalindrome(head1) ? "Palindrome" : "Not Palindrome") << endl;

    // Test Case 2: Non-palindrome list [1, 2, 3, 4, 5]
    vector<int> values2 = {1, 2, 3, 4, 5};
    LinkedListNode<int>* head2 = createLinkedList(values2);
    cout << "Test Case 2: " << (isPalindrome(head2) ? "Palindrome" : "Not Palindrome") << endl;

    // Test Case 3: Single element list [10] (a palindrome)
    vector<int> values3 = {10};
    LinkedListNode<int>* head3 = createLinkedList(values3);
    cout << "Test Case 3: " << (isPalindrome(head3) ? "Palindrome" : "Not Palindrome") << endl;

    return 0;
}

/*
Time Complexity:
The overall time complexity is O(n), where n is the number of nodes in the linked list.
This is due to the linear traversals for finding the middle, reversing the second half, and comparing the halves.

Space Complexity:
The space complexity is O(1) since the algorithm uses a constant amount of extra space (a few pointers) and does not require additional data structures.
*/
