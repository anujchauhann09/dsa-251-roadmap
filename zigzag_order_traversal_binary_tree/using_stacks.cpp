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

    vector<int> answer;  // Stores the zig-zag traversal result
    stack<BinaryTreeNode<int> *> oddLevel, evenLevel; // Two stacks for alternate level traversal

    oddLevel.push(root);  // Start with the root node

    while (!oddLevel.empty() || !evenLevel.empty()) {
        
        // Process nodes at odd levels (left to right)
        while (!oddLevel.empty()) {
            BinaryTreeNode<int> *temp = oddLevel.top();
            oddLevel.pop();
            answer.push_back(temp->data);

            // Push left before right for even level processing
            if (temp->left) {
                evenLevel.push(temp->left);
            }
            if (temp->right) {
                evenLevel.push(temp->right);
            }
        }

        // Process nodes at even levels (right to left)
        while (!evenLevel.empty()) {
            BinaryTreeNode<int> *temp = evenLevel.top();
            evenLevel.pop();
            answer.push_back(temp->data);

            // Push right before left for odd level processing
            if (temp->right) {
                oddLevel.push(temp->right);
            }
            if (temp->left) {
                oddLevel.push(temp->left);
            }
        }
    }

    return answer;  // Return the zig-zag traversal result
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
Each node is pushed and popped exactly once from a stack, leading to a O(N) time complexity, where N is the number of nodes in the tree.

Space Complexity:
1. Best case (skewed tree): The maximum space used by the stacks is O(1).
2. Worst case (balanced tree): The space used is O(N/2) ≈ O(N) at the last level.
*/