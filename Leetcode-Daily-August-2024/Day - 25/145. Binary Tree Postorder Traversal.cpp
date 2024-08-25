class Solution {
public:
    // Public method to initiate the postorder traversal and return the result as a vector of integers
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;  // Vector to store the nodes' values in postorder
        postorder(root, nodes);  // Start the postorder traversal
        return nodes;  // Return the vector containing the nodes' values
    }

private:
    // Private helper method to perform postorder traversal recursively
    void postorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;  // Base case: if the node is null, do nothing
        }
        postorder(root->left, nodes);  // Recursively traverse the left subtree
        postorder(root->right, nodes);  // Recursively traverse the right subtree
        nodes.push_back(root->val);  // Process the current node by adding its value to the vector
    }
};
