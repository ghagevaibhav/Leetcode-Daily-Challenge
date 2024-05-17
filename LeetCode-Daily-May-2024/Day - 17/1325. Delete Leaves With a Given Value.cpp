class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // Base Case: If the current node is null, return null
        if (!root) return nullptr;

        // Recursively call removeLeafNodes on the left child of the current node
        root->left = removeLeafNodes(root->left, target);

        // Recursively call removeLeafNodes on the right child of the current node
        root->right = removeLeafNodes(root->right, target);

        // Check if the current node is a leaf node and if its value is equal to the target
        if (!root->left && !root->right && root->val == target) {
            // If both conditions are met, return null to remove this leaf node
            return nullptr;
        }

        // If the current node is not a target leaf node, return the current node
        return root;
    }
};

