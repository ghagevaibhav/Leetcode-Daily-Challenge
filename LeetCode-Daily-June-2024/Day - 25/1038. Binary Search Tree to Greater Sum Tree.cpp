class Solution {
private:
    int sum = 0;  // Variable to store the cumulative sum of node values

    // Helper function to traverse the tree in reverse in-order (right -> root -> left)
    void traverse(TreeNode* root) {
        if (root) {
            traverse(root->right);  // Traverse the right subtree first
            sum += root->val;  // Add the current node's value to the cumulative sum
            root->val = sum;  // Update the current node's value to the cumulative sum
            traverse(root->left);  // Traverse the left subtree
        }
    }

public:
    // Function to convert a Binary Search Tree (BST) to a Greater Sum Tree (GST)
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);  // Start the traversal from the root
        return root;  // Return the modified tree
    }
};
