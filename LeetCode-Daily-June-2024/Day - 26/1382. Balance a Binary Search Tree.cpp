class Solution {
public:
    // This vector will store the nodes in sorted order after inorder traversal.
    vector<TreeNode*> sortedArr;
    
    // This function balances the BST by first doing an inorder traversal to get a sorted array of nodes,
    // and then converting that sorted array back into a balanced BST.
    TreeNode* balanceBST(TreeNode* root) {
        // Step 1: Inorder traversal to get sorted nodes.
        inorderTraverse(root);
        // Step 2: Convert the sorted array to a balanced BST.
        return sortedArrayToBST(0, sortedArr.size() - 1);
    }
    
    // Helper function to perform inorder traversal on the BST.
    void inorderTraverse(TreeNode* root) {
        // Base case: if the node is null, return.
        if (root == NULL) return;
        // Recursively traverse the left subtree.
        inorderTraverse(root->left);
        // Add the current node to the sorted array.
        sortedArr.push_back(root);
        // Recursively traverse the right subtree.
        inorderTraverse(root->right);
    }
    
    // Helper function to convert the sorted array of nodes into a balanced BST.
    TreeNode* sortedArrayToBST(int start, int end) {
        // Base case: if the start index is greater than the end index, return null.
        if (start > end) return NULL;
        // Find the middle element of the current subarray.
        int mid = (start + end) / 2;
        // Use the middle element as the root of the current subtree.
        TreeNode* root = sortedArr[mid];
        // Recursively build the left subtree using the left half of the current subarray.
        root->left = sortedArrayToBST(start, mid - 1);
        // Recursively build the right subtree using the right half of the current subarray.
        root->right = sortedArrayToBST(mid + 1, end);
        // Return the current root.
        return root;
    }
};
