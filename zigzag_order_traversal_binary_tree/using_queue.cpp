#include <bits/stdc++.h>
using namespace std;

// Definition of a binary tree node
template <typename T>
class BinaryTreeNode {
public:
    T data;  // Node value
    BinaryTreeNode<T> *left;  // Pointer to left child
    BinaryTreeNode<T> *right; // Pointer to right child

    // Constructor to initialize the node
    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to return the zig-zag level order traversal of a binary tree
vector<int> zigZagTraversal(BinaryTreeNode<int> *root) {
    if (!root) {
        return {};  // Return an empty vector if the tree is empty
    }

    vector<int> result;  // Stores the zig-zag traversal result
    queue<BinaryTreeNode<int> *> q; // Queue for level-wise traversal
    bool isLeftToRight = true; // Flag to track traversal direction

    q.push(root); // Start with the root node

    while (!q.empty()) {
        int size = q.size();  // Number of nodes at the current level
        vector<int> level(size); // Temporary vector to store level nodes

        for (int i = 0; i < size; i++) {
            BinaryTreeNode<int> *temp = q.front();
            q.pop();

            // Calculate index based on traversal direction
            int index = isLeftToRight ? i : size - i - 1;
            level[index] = temp->data;

            // Push child nodes into the queue
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }

        // Append current level nodes to result
        result.insert(result.end(), level.begin(), level.end());
        isLeftToRight = !isLeftToRight; // Toggle direction for next level
    }

    return result;  // Return the zig-zag traversal result
}

// Function to print the traversal result
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// Main function to test the zig-zag traversal function
int main() {
    // Test Case 1: Simple balanced binary tree
    BinaryTreeNode<int> *root1 = new BinaryTreeNode<int>(1);
    root1->left = new BinaryTreeNode<int>(2);
    root1->right = new BinaryTreeNode<int>(3);
    root1->left->left = new BinaryTreeNode<int>(4);
    root1->left->right = new BinaryTreeNode<int>(5);
    root1->right->left = new BinaryTreeNode<int>(6);
    root1->right->right = new BinaryTreeNode<int>(7);
    cout << "Zig-Zag Traversal of Tree 1: ";
    printVector(zigZagTraversal(root1));

    // Test Case 2: Left-skewed tree
    BinaryTreeNode<int> *root2 = new BinaryTreeNode<int>(1);
    root2->left = new BinaryTreeNode<int>(2);
    root2->left->left = new BinaryTreeNode<int>(3);
    root2->left->left->left = new BinaryTreeNode<int>(4);
    cout << "Zig-Zag Traversal of Tree 2: ";
    printVector(zigZagTraversal(root2));

    // Test Case 3: Right-skewed tree
    BinaryTreeNode<int> *root3 = new BinaryTreeNode<int>(10);
    root3->right = new BinaryTreeNode<int>(20);
    root3->right->right = new BinaryTreeNode<int>(30);
    root3->right->right->right = new BinaryTreeNode<int>(40);
    cout << "Zig-Zag Traversal of Tree 3: ";
    printVector(zigZagTraversal(root3));

    return 0;
}

/*
Time Complexity:
Each node is processed once and inserted into the result list, leading to a O(N) time complexity, where N is the number of nodes in the tree.

Space Complexity:
1. Best case (skewed tree): The queue holds at most O(1) nodes at any given time.
2. Worst case (balanced tree): The queue holds O(N/2) ≈ O(N) nodes at the last level.
3. Overall complexity: O(N) in the worst case due to the extra space used by the level vector.
*/