#include <bits/stdc++.h>
using namespace std;

// TreeNode class template to represent a binary tree node
// Each node contains a data value and pointers to left and right child nodes

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T dat) {
        this->data = dat;
        left = NULL;
        right = NULL;
    }
};

// Helper function to store all nodes in a stack using postorder traversal
void storeNodesInStack(TreeNode<int>* root, stack<TreeNode<int>*>& stk) {
    if (!root) {
        return;
    }
    
    // Process right subtree first, then left subtree, then push root
    storeNodesInStack(root->right, stk);
    storeNodesInStack(root->left, stk);
    stk.push(root);
}

// Function to flatten the binary tree into a linked list in-place
void flattenBinaryTree(TreeNode<int>* root) {
    if (!root) {
        return;
    }
    
    stack<TreeNode<int>*> stk;
    
    storeNodesInStack(root->right, stk);
    storeNodesInStack(root->left, stk);
    stk.push(root);
    
    // Process nodes in order
    while (!stk.empty()) {
        TreeNode<int>* temp = stk.top();
        stk.pop();
        
        // Set left child to NULL as we are converting to a linked list
        temp->left = NULL;
        
        // Link the current node to the next node in stack
        if (!stk.empty()) {
            TreeNode<int>* temp2 = stk.top();
            temp->right = temp2;
        } else {
            temp->right = NULL;
        }
    }
}

// Function to print the flattened binary tree in list format
void printFlattenedTree(TreeNode<int>* root) {
    while (root) {
        cout << root->data << " -> ";
        root = root->right;
    }
    cout << "NULL" << endl;
}

// Driver function to test the flattenBinaryTree function with different test cases
int main() {
    // Test Case 1: Balanced tree
    TreeNode<int>* root1 = new TreeNode<int>(1);
    root1->left = new TreeNode<int>(2);
    root1->right = new TreeNode<int>(5);
    root1->left->left = new TreeNode<int>(3);
    root1->left->right = new TreeNode<int>(4);
    root1->right->right = new TreeNode<int>(6);
    flattenBinaryTree(root1);
    printFlattenedTree(root1);
    
    // Test Case 2: Tree with only left children
    TreeNode<int>* root2 = new TreeNode<int>(1);
    root2->left = new TreeNode<int>(2);
    root2->left->left = new TreeNode<int>(3);
    root2->left->left->left = new TreeNode<int>(4);
    flattenBinaryTree(root2);
    printFlattenedTree(root2);
    
    // Test Case 3: Tree with only right children (already flattened)
    TreeNode<int>* root3 = new TreeNode<int>(1);
    root3->right = new TreeNode<int>(2);
    root3->right->right = new TreeNode<int>(3);
    root3->right->right->right = new TreeNode<int>(4);
    flattenBinaryTree(root3);
    printFlattenedTree(root3);
    
    return 0;
}

/*
Time and Space Complexity:
The function storeNodesInStack() performs a postorder traversal, which takes O(N) time, where N is the number of nodes in the tree. Since a stack is used to store all nodes before processing, the space complexity is O(N). The while-loop in flattenBinaryTree() iterates over each node once, making the total time complexity O(N). Thus, the function efficiently flattens the tree into a linked list with O(N) time and O(N) space complexity due to the extra stack storage.
*/