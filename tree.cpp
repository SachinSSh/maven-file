#include <iostream>
using namespace std;

// Definition of a Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to reverse a BST
void reverseBST(TreeNode* root) {
    if (!root) return;

    // Swap the left and right child
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively reverse the left and right subtrees
    reverseBST(root->left);
    reverseBST(root->right);
}

// Utility function to print the tree (In-order Traversal)
void inOrder(TreeNode* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

// Main function
int main() {
    // Creating a sample BST
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    cout << "Original BST (In-order): ";
    inOrder(root);
    cout << endl;

    // Reversing the BST
    reverseBST(root);

    cout << "Reversed BST (In-order): ";
    inOrder(root);
    cout << endl;

    return 0;
}
