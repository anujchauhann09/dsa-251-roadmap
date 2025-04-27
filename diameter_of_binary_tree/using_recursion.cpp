#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int calculateDiameterOfBinaryTree(TreeNode<int> *root, int &diameter) {
    // Base case: if root is null, height is 0
    if(!root) {
        return 0;
    }

    // Recursively calculate heights of left and right subtrees
    int leftHeight = calculateDiameterOfBinaryTree(root->left, diameter);
    int rightHeight = calculateDiameterOfBinaryTree(root->right, diameter);

    // Calculate diameter passing through current node and update maximum diameter
    int currentDiameter = leftHeight + rightHeight;
    diameter = max(currentDiameter, diameter);

    // Return the height of the current subtree
    return max(leftHeight, rightHeight) + 1;
}

int diameterOfBinaryTree(TreeNode<int> *root){
    int diameter = 0;
    calculateDiameterOfBinaryTree(root, diameter);
    return diameter;
}

int main() {
    // Test Case 1: Simple binary tree with diameter 3
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode<int>* root1 = new TreeNode<int>(1);
    root1->left = new TreeNode<int>(2);
    root1->right = new TreeNode<int>(3);
    root1->left->left = new TreeNode<int>(4);
    root1->left->right = new TreeNode<int>(5);
    cout << "Test Case 1 - Diameter: " << diameterOfBinaryTree(root1) << endl;  // Expected: 3

    // Test Case 2: Binary tree with diameter 4
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    //  /     \
    // 6       7
    TreeNode<int>* root2 = new TreeNode<int>(1);
    root2->left = new TreeNode<int>(2);
    root2->right = new TreeNode<int>(3);
    root2->left->left = new TreeNode<int>(4);
    root2->left->right = new TreeNode<int>(5);
    root2->left->left->left = new TreeNode<int>(6);
    root2->left->right->right = new TreeNode<int>(7);
    cout << "Test Case 2 - Diameter: " << diameterOfBinaryTree(root2) << endl;  // Expected: 4

    // Test Case 3: Empty tree (null root)
    TreeNode<int>* root3 = nullptr;
    cout << "Test Case 3 - Diameter: " << diameterOfBinaryTree(root3) << endl;  // Expected: 0

    return 0;
}

/*
Time Complexity:
The time complexity of this solution is O(n), where n is the number of nodes in the binary tree, as each node is visited exactly once during the post-order traversal. 

Space Complexity:
The space complexity is O(h), where h is the height of the binary tree, due to the recursive call stack. In the worst case of a skewed tree, this becomes O(n), while for a balanced tree it would be O(log n). The algorithm efficiently calculates the diameter by combining height calculations with diameter updates during the traversal.
*/