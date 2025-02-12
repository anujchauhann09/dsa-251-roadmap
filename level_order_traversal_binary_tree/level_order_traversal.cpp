#include <bits/stdc++.h>
using namespace std;

// Definition of a binary tree node
template <typename T>
class BinaryTreeNode {
public:
    T val;  // Node value
    BinaryTreeNode<T> *left;  // Pointer to left child
    BinaryTreeNode<T> *right; // Pointer to right child

    // Constructor to initialize the node
    BinaryTreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// Function to return the level order traversal of a binary tree
vector<int> getLevelOrder(BinaryTreeNode<int> *root) {
    if (!root) {
        return {};  // Return an empty vector if the tree is empty
    }

    vector<int> result;               // Stores the level order traversal result
    queue<BinaryTreeNode<int> *> q;   // Queue to process nodes level by level

    q.push(root);  // Start with the root node

    while (!q.empty()) {
        BinaryTreeNode<int> *temp = q.front(); // Get the front node from the queue
        q.pop(); // Remove the processed node

        // Push left child if exists
        if (temp->left) {
            q.push(temp->left);
        }

        // Push right child if exists
        if (temp->right) {
            q.push(temp->right);
        }

        // Store the value of the current node in result vector
        result.push_back(temp->val);
    }

    return result;  // Return the level order traversal result
}

// Function to print the level order traversal result
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// Main function to test the getLevelOrder function
int main() {
    // Test Case 1: Simple balanced binary tree
    BinaryTreeNode<int> *root1 = new BinaryTreeNode<int>(1);
    root1->left = new BinaryTreeNode<int>(2);
    root1->right = new BinaryTreeNode<int>(3);
    root1->left->left = new BinaryTreeNode<int>(4);
    root1->left->right = new BinaryTreeNode<int>(5);
    root1->right->left = new BinaryTreeNode<int>(6);
    root1->right->right = new BinaryTreeNode<int>(7);
    cout << "Level Order Traversal of Tree 1: ";
    printVector(getLevelOrder(root1));

    // Test Case 2: Skewed tree (left-skewed)
    BinaryTreeNode<int> *root2 = new BinaryTreeNode<int>(1);
    root2->left = new BinaryTreeNode<int>(2);
    root2->left->left = new BinaryTreeNode<int>(3);
    root2->left->left->left = new BinaryTreeNode<int>(4);
    cout << "Level Order Traversal of Tree 2: ";
    printVector(getLevelOrder(root2));

    // Test Case 3: Tree with only right children (right-skewed)
    BinaryTreeNode<int> *root3 = new BinaryTreeNode<int>(10);
    root3->right = new BinaryTreeNode<int>(20);
    root3->right->right = new BinaryTreeNode<int>(30);
    root3->right->right->right = new BinaryTreeNode<int>(40);
    cout << "Level Order Traversal of Tree 3: ";
    printVector(getLevelOrder(root3));

    return 0;
}

/*
Time Complexity:
The function processes each node exactly once, visiting all nodes in O(N) time, where N is the number of nodes in the tree. Since each node is enqueued and dequeued only once, the total number of operations is proportional to N, making the time complexity O(N).

Space Complexity:
1. Best case (skewed tree): The queue holds at most O(1) nodes at any given time.
2. Worst case (balanced tree): The queue holds at most O(N/2) ≈ O(N) nodes at the last level.
3. Overall complexity: O(N) in the worst case (if the tree is balanced).
*/