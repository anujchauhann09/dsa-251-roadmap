#include <iostream>
#include <queue>
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

// Helper function to store all nodes in a queue using preorder traversal
void storeNodesInQueue(TreeNode<int>* root, queue<TreeNode<int>*>& q) {
    if (!root) {
        return;
    }
    
    // Push the root node into the queue
    q.push(root);
    
    // Recursively process the left and right subtrees
    storeNodesInQueue(root->left, q);
    storeNodesInQueue(root->right, q);
}

// Function to flatten the binary tree into a linked list in-place
void flattenBinaryTree(TreeNode<int>* root) {
    if (!root) {
        return;
    }
    
    queue<TreeNode<int>*> q;
    storeNodesInQueue(root, q);
    
    // Process nodes in order
    while (!q.empty()) {
        TreeNode<int>* temp = q.front();
        q.pop();
        
        // Set left child to NULL as we are converting to a linked list
        temp->left = NULL;
        
        // Link the current node to the next node in queue
        if (!q.empty()) {
            TreeNode<int>* temp2 = q.front();
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
The function storeNodesInQueue() performs a preorder traversal, which takes O(N) time, where N is the number of nodes in the tree. The queue stores all N nodes, leading to O(N) space complexity. The while-loop in flattenBinaryTree() processes each node once, making its time complexity O(N) as well. Hence, the overall time complexity is O(N), and the space complexity is O(N) due to the extra queue used for storing nodes before re-linking them.
*/