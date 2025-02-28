#include <bits/stdc++.h>
using namespace std;

// Definition of a Binary Tree Node
template <typename T>
class BinaryTreeNode 
{
public : 
    T data; // Data stored in the node
    BinaryTreeNode<T> *left; // Pointer to the left child
    BinaryTreeNode<T> *right; // Pointer to the right child

    // Constructor to initialize a node with data and set left and right pointers to NULL
    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Helper function to perform in-order traversal and store nodes in a queue
void BinaryTreeToDoublyLinkedListHelper(BinaryTreeNode<int>* root, queue<BinaryTreeNode<int>*> &q) {
    // Base case: if the current node is NULL, return
    if(!root) {
        return;
    }

    // Recursively process the left subtree
    BinaryTreeToDoublyLinkedListHelper(root->left, q);

    // Push the current node into the queue
    q.push(root);

    // Recursively process the right subtree
    BinaryTreeToDoublyLinkedListHelper(root->right, q);
}

// Function to convert a binary tree to a doubly linked list (DLL)
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // If the tree is empty, return NULL
    if(!root) {
        return root;
    }

    // Create a queue to store nodes in in-order traversal
    queue<BinaryTreeNode<int>*> q;

    // Perform in-order traversal and populate the queue
    BinaryTreeToDoublyLinkedListHelper(root, q);

    // The head of the DLL is the first node in the queue
    BinaryTreeNode<int>* head = q.front();

    // Process the queue to construct the DLL
    while(!q.empty()) {
        // Get the current node from the queue
        BinaryTreeNode<int>* current = q.front();
        q.pop();

        // If there is a next node in the queue, link it to the current node
        if(!q.empty()) {
            BinaryTreeNode<int>* currentNext = q.front();
            current->right = currentNext; // Set current's right pointer to the next node
            currentNext->left = current; // Set next node's left pointer to the current node
        }
    }

    // Return the head of the DLL
    return head;
}

// Utility function to print the doubly linked list
void printDLL(BinaryTreeNode<int>* head) {
    BinaryTreeNode<int>* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

// Main function to test the BTtoDLL function
int main() {
    // Test Case 1: Simple binary tree
    //     1
    //    / \
    //   2   3
    BinaryTreeNode<int>* root1 = new BinaryTreeNode<int>(1);
    root1->left = new BinaryTreeNode<int>(2);
    root1->right = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int>* dll1 = BTtoDLL(root1);
    cout << "Test Case 1: ";
    printDLL(dll1); // Expected Output: 2 1 3

    // Test Case 2: Binary tree with only left children
    //     4
    //    /
    //   5
    //  /
    // 6
    BinaryTreeNode<int>* root2 = new BinaryTreeNode<int>(4);
    root2->left = new BinaryTreeNode<int>(5);
    root2->left->left = new BinaryTreeNode<int>(6);
    BinaryTreeNode<int>* dll2 = BTtoDLL(root2);
    cout << "Test Case 2: ";
    printDLL(dll2); // Expected Output: 6 5 4

    // Test Case 3: Binary tree with only right children
    //     7
    //      \
    //       8
    //        \
    //         9
    BinaryTreeNode<int>* root3 = new BinaryTreeNode<int>(7);
    root3->right = new BinaryTreeNode<int>(8);
    root3->right->right = new BinaryTreeNode<int>(9);
    BinaryTreeNode<int>* dll3 = BTtoDLL(root3);
    cout << "Test Case 3: ";
    printDLL(dll3); // Expected Output: 7 8 9

    return 0;
}

/*
Time Complexity: 
The time complexity of the algorithm is O(N), where N is the number of nodes in the binary tree. This is because each node is visited exactly once during the in-order traversal, and the queue operations (push and pop) are performed in constant time.

Space Complexity: 
The space complexity is O(N) due to the queue storing all the nodes of the binary tree. Additionally, the recursion stack uses O(H) space, where H is the height of the tree. In the worst case (a skewed tree), the space complexity remains O(N).
*/