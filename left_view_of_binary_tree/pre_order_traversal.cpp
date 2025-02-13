#include <bits/stdc++.h>
using namespace std;

// Definition of a binary tree node
template <typename T>
class TreeNode {
public:
    T data;                      // Value of the node
    TreeNode<T> *left;           // Pointer to the left child
    TreeNode<T> *right;          // Pointer to the right child

    // Constructor to initialize the node with given data
    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Helper function for getLeftView that traverses the tree recursively
// 'level' keeps track of the current level and 'maxLevel' records the deepest level visited so far
void getLeftViewHelper(TreeNode<int>* root, vector<int> &answer, int &level, int &maxLevel) {
    if (root == NULL) {
        return; // Base case: If node is null, simply return
    }

    level++; // Increment level as we go deeper into the tree

    // If this is the first node encountered at the current level, add it to the answer
    if (level > maxLevel) {
        answer.push_back(root->data);
        maxLevel = level;
    }

    // Traverse left subtree first, then right subtree
    getLeftViewHelper(root->left, answer, level, maxLevel);
    getLeftViewHelper(root->right, answer, level, maxLevel);

    level--; // Decrement level when backtracking
}

// Function to return the left view of the binary tree
vector<int> getLeftView(TreeNode<int> *root) {
    if (!root) {
        return {}; // Return an empty vector if the tree is empty
    }

    int level = 0, maxLevel = 0; // Initialize current and maximum levels
    vector<int> answer;         // Vector to store the left view nodes
    getLeftViewHelper(root, answer, level, maxLevel);
    return answer;
}

// Utility function to print the contents of a vector
void printVector(const vector<int> &vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// Main function with test cases
int main() {
    // Test Case 1: Balanced binary tree
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    TreeNode<int>* root1 = new TreeNode<int>(1);
    root1->left = new TreeNode<int>(2);
    root1->right = new TreeNode<int>(3);
    root1->left->left = new TreeNode<int>(4);
    root1->left->right = new TreeNode<int>(5);
    root1->right->left = new TreeNode<int>(6);
    root1->right->right = new TreeNode<int>(7);
    cout << "Left View of Balanced Tree: ";
    printVector(getLeftView(root1));

    // Test Case 2: Left-skewed tree
    //       1
    //      /
    //     2
    //    /
    //   3
    //  /
    // 4
    TreeNode<int>* root2 = new TreeNode<int>(1);
    root2->left = new TreeNode<int>(2);
    root2->left->left = new TreeNode<int>(3);
    root2->left->left->left = new TreeNode<int>(4);
    cout << "Left View of Left Skewed Tree: ";
    printVector(getLeftView(root2));

    // Test Case 3: Right-skewed tree
    //   1
    //    \
    //     2
    //      \
    //       3
    //        \
    //         4
    TreeNode<int>* root3 = new TreeNode<int>(1);
    root3->right = new TreeNode<int>(2);
    root3->right->right = new TreeNode<int>(3);
    root3->right->right->right = new TreeNode<int>(4);
    cout << "Left View of Right Skewed Tree: ";
    printVector(getLeftView(root3));

    return 0;
}

/*
Time and Space Complexity:
The algorithm traverses every node in the tree exactly once, leading to a time complexity of O(n), where n is the total number of nodes. 

Space Complexity:
Due to recursion, the space complexity is O(n) in the worst-case scenario (particularly for skewed trees), as the maximum depth of the recursion stack could be n.
*/
