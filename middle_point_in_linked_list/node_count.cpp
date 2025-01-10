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

// Function to find the middle of the linked list
Node *findMiddle(Node *head) {
    int countNodes = 0;
    int middlePosi;

    Node *temp = head;

    // Count the number of nodes
    while (temp != NULL) {
        countNodes++;
        temp = temp->next;
    }

    middlePosi = countNodes / 2;

    // Move the head pointer to the middle node
    while (middlePosi--) {
        head = head->next;
    }

    return head;
}

int main() {
    // Test case 1
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    
    Node *middle1 = findMiddle(head1);
    cout << "Middle of first list: " << middle1->data << endl; // Expected output: 3
    
    // Test case 2
    Node *head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = new Node(30);
    
    Node *middle2 = findMiddle(head2);
    cout << "Middle of second list: " << middle2->data << endl; // Expected output: 20
    
    // Test case 3
    Node *head3 = new Node(5);
    head3->next = new Node(10);
    
    Node *middle3 = findMiddle(head3);
    cout << "Middle of third list: " << middle3->data << endl; // Expected output: 10
    
    return 0;
}

/*
Time Complexity:
The time complexity of this approach is O(n), where n is the number of nodes in the linked list. This is because the function performs two traversals of the list: one to count the total number of nodes and another to move the pointer to the middle node. Since both traversals involve iterating over all nodes in the list, the time complexity is linear in relation to the size of the list.

Space Complexity:
The space complexity is O(1), as the algorithm only uses a constant amount of extra space. The only variables used are countNodes, middlePosi, and temp, all of which occupy a fixed amount of space regardless of the size of the input linked list. Therefore, the space complexity remains constant.
*/