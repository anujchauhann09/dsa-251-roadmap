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

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

// Function to traverse and store the left boundary nodes (excluding leaf nodes)
void leftTraversal(TreeNode<int>* root, vector<int>& answer) {
    if (!root || (!root->left && !root->right)) {
        return;
    }
    
    // Store the current node's data
    answer.push_back(root->data);
    
    // Prioritize left subtree, if not available, move to right
    if (root->left) {
        leftTraversal(root->left, answer);
    } else if (root->right) {
        leftTraversal(root->right, answer);
    }
}

// Function to traverse and store all leaf nodes
void leafTraversal(TreeNode<int>* root, vector<int>& answer) {
    if (!root) {
        return;
    }
    
    // If it's a leaf node, store its data
    if (!root->left && !root->right) {
        answer.push_back(root->data);
    }
    
    // Recur for left and right subtrees
    leafTraversal(root->left, answer);
    leafTraversal(root->right, answer);
}

// Function to traverse and store the right boundary nodes in reverse order (excluding leaf nodes)
void rightTraversal(TreeNode<int>* root, vector<int>& answer) {
    if (!root || (!root->left && !root->right)) {
        return;
    }
    
    // Prioritize right subtree, if not available, move to left
    if (root->right) {
        rightTraversal(root->right, answer);
    } else if (root->left) {
        rightTraversal(root->left, answer);
    }
    
    // Store the current node's data while returning (reverse order)
    answer.push_back(root->data);
}

// Function to perform the boundary traversal of the binary tree
vector<int> traverseBoundary(TreeNode<int>* root) {
    vector<int> answer;
    
    if (!root) {
        return answer;
    }
    
    // Store the root node first
    answer.push_back(root->data);
    
    // Traverse the left boundary
    leftTraversal(root->left, answer);
    
    // Traverse and store all leaf nodes
    leafTraversal(root, answer);
    
    // Traverse the right boundary
    rightTraversal(root->right, answer);
    
    return answer;
}

// Function to create a sample tree and test boundary traversal
int main() {
    // Test Case 1: Balanced binary tree
    TreeNode<int>* root1 = new TreeNode<int>(1);
    root1->left = new TreeNode<int>(2);
    root1->right = new TreeNode<int>(3);
    root1->left->left = new TreeNode<int>(4);
    root1->left->right = new TreeNode<int>(5);
    root1->right->left = new TreeNode<int>(6);
    root1->right->right = new TreeNode<int>(7);
    vector<int> result1 = traverseBoundary(root1);
    for (int val : result1) cout << val << " ";
    cout << endl;
    
    // Test Case 2: Left-skewed tree
    TreeNode<int>* root2 = new TreeNode<int>(1);
    root2->left = new TreeNode<int>(2);
    root2->left->left = new TreeNode<int>(3);
    root2->left->left->left = new TreeNode<int>(4);
    vector<int> result2 = traverseBoundary(root2);
    for (int val : result2) cout << val << " ";
    cout << endl;
    
    // Test Case 3: Right-skewed tree
    TreeNode<int>* root3 = new TreeNode<int>(1);
    root3->right = new TreeNode<int>(2);
    root3->right->right = new TreeNode<int>(3);
    root3->right->right->right = new TreeNode<int>(4);
    vector<int> result3 = traverseBoundary(root3);
    for (int val : result3) cout << val << " ";
    cout << endl;
    
    return 0;
}

/*
Time and Space Complexity: 
The boundary traversal function consists of three main components: left boundary traversal, leaf node traversal, and right boundary traversal (in reverse order). Each function processes nodes recursively, ensuring all required nodes are stored efficiently. The time complexity is O(N) since each node is visited at most once. The space complexity is O(N) in the worst case, as the recursion stack and the result vector together take up O(N) space.
*/