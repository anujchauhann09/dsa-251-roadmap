#include <iostream>
using namespace std;

/**
 * Definition of linked list:
 */
class Node {
public:
    int data;
    Node *next;

    // Default constructor
    Node() {
        this->data = 0;
        this->next = NULL;
    }

    // Constructor with data
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Constructor with data and next pointer
    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

/**
 * Function to add two numbers represented as linked lists.
 * The function modifies the first list (num1) to store the result.
 *
 * @param num1: Pointer to the head of the first linked list.
 * @param num2: Pointer to the head of the second linked list.
 * @return: Pointer to the head of the modified first linked list with the result.
 */
Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node* num1Head = num1; // Keep track of the head of the first list.
    Node* num1Prev = NULL; // Track the previous node of num1 during iteration.

    int addSum = 0, carry = 0;

    // Add corresponding digits from num1 and num2
    while (num1 != NULL && num2 != NULL) {
        addSum = (num1->data + num2->data + carry);
        carry = addSum / 10; // Calculate the carry for the next digit.

        num1->data = (addSum % 10); // Update the current digit in num1.

        num1Prev = num1; // Update the previous pointer.
        num1 = num1->next; // Move to the next node in num1.
        num2 = num2->next; // Move to the next node in num2.
    }

    // If num1 is longer, continue adding carry
    while (num1 != NULL) {
        addSum = (num1->data + carry);
        carry = addSum / 10;

        num1->data = (addSum % 10);
        num1Prev = num1;
        num1 = num1->next;
    }

    // If num2 is longer, add remaining digits of num2 and carry to num1
    while (num2 != NULL) {
        addSum = (num2->data + carry);
        carry = addSum / 10;

        Node* newNode = new Node((addSum % 10)); // Create a new node for the result.
        num1Prev->next = newNode;
        num1Prev = newNode;

        num2 = num2->next;
    }

    // If there is any carry left, create a new node for it
    if (carry) {
        Node* newNode = new Node(carry);
        num1Prev->next = newNode;
    }

    return num1Head; // Return the updated head of num1.
}

/**
 * Utility function to print a linked list.
 */
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

/**
 * Utility function to create a linked list from an array.
 */
Node* createList(const int arr[], int size) {
    if (size == 0) return NULL;

    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

int main() {
    // Test case 1
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    Node* num1 = createList(arr1, 3);
    Node* num2 = createList(arr2, 3);

    cout << "Input List 1: ";
    printList(num1);
    cout << "Input List 2: ";
    printList(num2);

    Node* result = addTwoNumbers(num1, num2);
    cout << "Result List: ";
    printList(result);
    cout << endl;

    // Test case 2
    int arr3[] = {9, 9, 9};
    int arr4[] = {1};
    Node* num3 = createList(arr3, 3);
    Node* num4 = createList(arr4, 1);

    cout << "Input List 1: ";
    printList(num3);
    cout << "Input List 2: ";
    printList(num4);

    result = addTwoNumbers(num3, num4);
    cout << "Result List: ";
    printList(result);
    cout << endl;

    // Test case 3
    int arr5[] = {0};
    int arr6[] = {0};
    Node* num5 = createList(arr5, 1);
    Node* num6 = createList(arr6, 1);

    cout << "Input List 1: ";
    printList(num5);
    cout << "Input List 2: ";
    printList(num6);

    result = addTwoNumbers(num5, num6);
    cout << "Result List: ";
    printList(result);
    cout << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of the addTwoNumbers function is O(max(N, M)), where N is the length of the first linked list (num1) and M is the length of the second linked list (num2). This complexity arises because the function iterates through both linked lists, processing each node exactly once until both lists are fully traversed. Any additional carry at the end requires at most one more operation to create a new node, which does not affect the asymptotic complexity.

Space Complexity:
The space complexity of the function is O(1) in terms of auxiliary space, as the operations are performed in-place by modifying the first linked list (num1). No additional data structures are used, except for a constant number of pointers and variables to manage the iteration and calculations. However, if num2 is longer than num1, new nodes are dynamically allocated to extend the first list to accommodate the result. This memory allocation is part of the output structure and does not contribute to the auxiliary space complexity. Thus, the space used is proportional to the output size, which depends on the sum's digits.
*/