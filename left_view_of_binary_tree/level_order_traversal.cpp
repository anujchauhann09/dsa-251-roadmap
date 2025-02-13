#include <bits/stdc++.h>
using namespace std;

// Definition of a binary tree node
template <typename T>
class TreeNode {
public:
    T data;                    // Node value
    TreeNode<T> *left;         // Pointer to left child
    TreeNode<T> *right;        // Pointer to right child

    // Constructor to initialize node with given data
    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to get the left view of a binary tree using level order traversal with NULL markers
vector<int> getLeftView(TreeNode<int> *root) {
    if (!root) {
        return {}; // Return empty vector if tree is empty
    }

    queue<TreeNode<int>*> q;
    vector<int> answer;

    // Push NULL as a level marker followed by the root node
    q.push(NULL);
    q.push(root);

    // Process the tree level by level
    while (!q.empty()) {
        TreeNode<int>* temp = q.front();
        q.pop();

        // If we encounter a NULL marker, then next node (if exists) is the first node of the next level
        if (temp == NULL) {
            if (!q.empty()) {
                answer.push_back(q.front()->data);
                q.push(NULL);  // Mark the end of the next level
            }
            continue;
        }

        // Push the left and right children into the queue
        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }

    return answer;  // Return the collected left view of the tree
}

// Utility function to print the vector elements
void printVector(const vector<int>& vec) {
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
    //      1
    //     /
    //    2
    //   /
    //  3
    // /
    //4
    TreeNode<int>* root2 = new TreeNode<int>(1);
    root2->left = new TreeNode<int>(2);
    root2->left->left = new TreeNode<int>(3);
    root2->left->left->left = new TreeNode<int>(4);
    cout << "Left View of Left Skewed Tree: ";
    printVector(getLeftView(root2));

    // Test Case 3: Right-skewed tree
    // 1
    //  \
    //   2
    //    \
    //     3
    //      \
    //       4
    TreeNode<int>* root3 = new TreeNode<int>(1);
    root3->right = new TreeNode<int>(2);
    root3->right->right = new TreeNode<int>(3);
    root3->right->right->right = new TreeNode<int>(4);
    cout << "Left View of Right Skewed Tree: ";
    printVector(getLeftView(root3));

    return 0;
}

/*
Time Complexity: 
O(n), where n is the number of nodes, as each node is visited once during the level order traversal.

Space Complexity: 
O(n) in the worst case, due to the additional space used by the queue to store nodes at each level.
*/
