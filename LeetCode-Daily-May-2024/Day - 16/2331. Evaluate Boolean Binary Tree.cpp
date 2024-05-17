class Solution {
public:
    // This helper function evaluates the boolean value of the expression represented by the binary tree.
    bool helper(TreeNode* root) {
        // Base case: if the node value is 0 or 1, return true if it's 1, false if it's 0.
        if (root->val == 0 || root->val == 1) {
            return root->val == 1;
        }
        // If the node value is 2, it represents a logical OR operation.
        else if (root->val == 2) {
            // Recursively evaluate the left and right subtrees and return true if either is true.
            return helper(root->left) || helper(root->right);
        }
        // If the node value is 3, it represents a logical AND operation.
        else if (root->val == 3) {
            // Recursively evaluate the left and right subtrees and return true only if both are true.
            return helper(root->left) && helper(root->right);
        }
        // If the node value is not 0, 1, 2, or 3, it's an invalid value for this problem.
        // Return false as a safe fallback.
        return false;
    }

    // This function initiates the evaluation of the boolean expression tree.
    bool evaluateTree(TreeNode* root) {
        // Call the helper function with the root node of the tree.
        return helper(root);
    }
};
