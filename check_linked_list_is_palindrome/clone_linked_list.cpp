#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode {
public:
    T data;                         // Data stored in the node.
    LinkedListNode<T>* next;        // Pointer to the next node in the list.

    // Constructor to initialize the node with provided data.
    LinkedListNode(T data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertNode(LinkedListNode<int>* &head, int data) {
    LinkedListNode<int>* newNode = new LinkedListNode<int>(data);
    newNode->next = head;
    head = newNode;
}

LinkedListNode<int>* createLinkedList(const vector<int>& values) {
    LinkedListNode<int>* head = NULL;
    // Insert nodes in reverse order so the final list order matches the vector.
    for (int i = values.size() - 1; i >= 0; i--) {
        insertNode(head, values[i]);
    }
    return head;
}

bool isPalindrome(LinkedListNode<int>* head) {
    LinkedListNode<int>* newHead = NULL;
    LinkedListNode<int>* temp = head;

    // Create a reversed copy of the linked list.
    while (temp != NULL) {
        insertNode(newHead, temp->data);
        temp = temp->next;
    }

    // Compare the original list with the reversed copy.
    temp = head;
    LinkedListNode<int>* newTemp = newHead;
    while (temp) {
        if (temp->data != newTemp->data) {
            return false;
        }
        temp = temp->next;
        newTemp = newTemp->next;
    }
    return true;
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

    // Test Case 3: Single element list [7] (always a palindrome)
    vector<int> values3 = {7};
    LinkedListNode<int>* head3 = createLinkedList(values3);
    cout << "Test Case 3: " << (isPalindrome(head3) ? "Palindrome" : "Not Palindrome") << endl;

    return 0;
}

/*
Time Complexity:
The algorithm runs in O(n) time where n is the number of nodes in the linked list.
This is due to one pass to create the reversed copy and another pass for the comparison.

Space Complexity:
O(n) extra space is used because a reversed copy of the entire list is created.
*/
