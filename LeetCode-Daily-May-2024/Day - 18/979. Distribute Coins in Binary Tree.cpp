class Solution {
public:
    int ans; // Variable to store the answer

    // Function to count the steps needed to distribute coins
    int countsteps(TreeNode* root) {
        // If the root is null, return 0
        if (root == nullptr) return 0;
        
        // Recursively count steps for left and right subtrees
        int leftcoins = countsteps(root->left);
        int rightcoins = countsteps(root->right);
        
        // Update answer by adding absolute differences of left and right coins
        ans += abs(leftcoins) + abs(rightcoins);
        
        // Return the excess/deficit coins at this node after distributing
        return (root->val - 1) + leftcoins + rightcoins;
    }

    // Function to distribute coins in the binary tree
    int distributeCoins(TreeNode* root) {
        ans = 0; // Initialize answer to 0
        countsteps(root); // Call countsteps to calculate answer
        return ans; // Return the final answer
    }
};
