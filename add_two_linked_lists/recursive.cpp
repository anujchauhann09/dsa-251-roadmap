#include <iostream>
using namespace std;

class Node {
public:
     int data;
     Node *next;
     Node() {
         this->data = 0;
         this->next = NULL;
     }
     Node(int data) {
         this->data = data;
         this->next = NULL;
     }
     Node (int data, Node *next) {
         this->data = data;
         this->next = next;
     }
};

/**
 * Helper function to insert a new node with given data into the linked list.
 * It updates both the head and tail pointers to maintain the list's structure.
 */
void insertNode(Node* &head, Node* &tail, int data) {
    if(!head) {
        head = new Node(data);
        tail = head;
    }
    else {
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}

// Recursive helper function to add two numbers represented as linked lists.
Node* addTwoNumbersHelper(Node* num1, Node* num2, int carry) {
    // Base case: if both lists are NULL and there's no carry, return NULL
    if (!num1 && !num2 && !carry) {
        return NULL;
    }

    // Extract values and the next nodes of both lists
    int val1 = (num1 != NULL) ? num1->data : 0;
    int val2 = (num2 != NULL) ? num2->data : 0;

    Node* next1 = (num1 != NULL) ? num1->next : NULL;
    Node* next2 = (num2 != NULL) ? num2->next : NULL;

    // Calculate the sum and carry for the current digit
    int sum = val1 + val2 + carry;

    // Create a new node with the value of the current digit (sum % 10)
    Node* sumNode = new Node(sum % 10);

    // Recursively compute the sum for the next nodes and pass the carry
    sumNode->next = addTwoNumbersHelper(next1, next2, sum / 10);

    return sumNode;
}

// Wrapper function to add two numbers
Node* addTwoNumbers(Node* num1, Node* num2) {   
    return addTwoNumbersHelper(num1, num2, 0);
}

/**
 * Utility function to print a linked list.
 */
void printList(Node* head) {
    while(head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

/**
 * Main function to test the `addTwoNumbers` implementation with three test cases.
 */
int main() {
    // Test Case 1
    Node* num1 = NULL;
    Node* num1Tail = NULL;
    insertNode(num1, num1Tail, 2);
    insertNode(num1, num1Tail, 4);
    insertNode(num1, num1Tail, 3);

    Node* num2 = NULL;
    Node* num2Tail = NULL;
    insertNode(num2, num2Tail, 5);
    insertNode(num2, num2Tail, 6);
    insertNode(num2, num2Tail, 4);

    Node* result = addTwoNumbers(num1, num2);
    cout << "Test Case 1: ";
    printList(result);

    // Test Case 2
    num1 = NULL;
    num1Tail = NULL;
    insertNode(num1, num1Tail, 0);

    num2 = NULL;
    num2Tail = NULL;
    insertNode(num2, num2Tail, 0);

    result = addTwoNumbers(num1, num2);
    cout << "Test Case 2: ";
    printList(result);

    // Test Case 3
    num1 = NULL;
    num1Tail = NULL;
    insertNode(num1, num1Tail, 9);
    insertNode(num1, num1Tail, 9);
    insertNode(num1, num1Tail, 9);

    num2 = NULL;
    num2Tail = NULL;
    insertNode(num2, num2Tail, 1);

    result = addTwoNumbers(num1, num2);
    cout << "Test Case 3: ";
    printList(result);

    return 0;
}

/*
Time complexity:
The time complexity of this recursive approach depends on the number of nodes in the longer of the two linked lists, denoted as n. For each node in the list, the function makes a single recursive call, performing a constant amount of work during each call, such as adding the corresponding digits and handling the carry. As a result, the total number of recursive calls is proportional to the length of the longer list, making the time complexity O(n). This ensures that the algorithm processes each node exactly once.

Space complexity:
The space complexity arises primarily from the recursion stack and the creation of new nodes. Since the recursion goes as deep as the number of nodes in the list, the recursion stack requires O(n) space. Additionally, a new node is allocated for every sum digit, resulting in a new linked list whose size matches the total number of digits, including the extra carry, if any. This also contributes O(n) to the space complexity. Therefore, the overall space complexity is O(n), combining both the recursion stack and the new nodes. This approach is efficient, with a linear relationship to the size of the input, ensuring scalability for larger linked lists.
*/