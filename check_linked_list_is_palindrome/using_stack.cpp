#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode {
public:
    T data;                          // Data stored in the node.
    LinkedListNode<T>* next;         // Pointer to the next node in the list.

    // Constructor: Initializes the node with the given data and sets the next pointer to NULL.
    LinkedListNode(T data) {
        this->data = data;
        this->next = NULL;
    }
};

bool isPalindrome(LinkedListNode<int>* head) {
    LinkedListNode<int>* temp = head;
    stack<LinkedListNode<int>*> stk;
    
    // Push all nodes onto the stack.
    while (temp != NULL) {
        stk.push(temp);
        temp = temp->next;
    }
    
    // Reset temp to the head of the list.
    temp = head;
    
    // Compare each node with the corresponding node from the stack (reverse order).
    while (temp) {
        if (temp->data != stk.top()->data) {
            return false;  // Mismatch found, not a palindrome.
        }
        temp = temp->next;
        stk.pop();
    }
    
    return true;  // All nodes matched, the list is a palindrome.
}

LinkedListNode<int>* createLinkedList(const vector<int>& values) {
    if (values.empty())
        return NULL;
    
    // Create the head node with the first element.
    LinkedListNode<int>* head = new LinkedListNode<int>(values[0]);
    LinkedListNode<int>* current = head;
    
    // Create the rest of the linked list.
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new LinkedListNode<int>(values[i]);
        current = current->next;
    }
    
    return head;
}

int main() {
    // Test Case 1: Palindrome linked list [1, 2, 3, 2, 1]
    vector<int> values1 = {1, 2, 3, 2, 1};
    LinkedListNode<int>* head1 = createLinkedList(values1);
    cout << "Test Case 1: " 
         << (isPalindrome(head1) ? "Palindrome" : "Not Palindrome") 
         << endl;
    
    // Test Case 2: Non-palindrome linked list [1, 2, 3, 4, 5]
    vector<int> values2 = {1, 2, 3, 4, 5};
    LinkedListNode<int>* head2 = createLinkedList(values2);
    cout << "Test Case 2: " 
         << (isPalindrome(head2) ? "Palindrome" : "Not Palindrome") 
         << endl;
    
    // Test Case 3: Single element list [7] (always a palindrome)
    vector<int> values3 = {7};
    LinkedListNode<int>* head3 = createLinkedList(values3);
    cout << "Test Case 3: " 
         << (isPalindrome(head3) ? "Palindrome" : "Not Palindrome") 
         << endl;
    
    return 0;
}

/*
Time Complexity:
The time complexity is O(n), where n is the number of nodes in the linked list.
This is due to the two passes over the list: one to push nodes onto the stack and one to compare them.

Space Complexity:
The space complexity is O(n) since all n nodes are stored in the stack.
*/
