class Solution {
public:
    // Helper function to perform postorder traversal on the tree
    void traverse(Node* root, vector<int> &post) {
        // Base case: If the current node is NULL, return immediately
        if (root == NULL)  
            return;
        
        // Recursively traverse each child of the current node
        for (auto x : root->children) {
            traverse(x, post);
        }
        
        // After traversing all children, add the current node's value to the postorder vector
        post.push_back(root->val);
    }

    // Function to return the postorder traversal of the tree
    vector<int> postorder(Node* root) {
        // Vector to store the postorder traversal result
        vector<int> post;
        
        // Start the traversal from the root node
        traverse(root, post);
        
        // Return the result vector containing the postorder traversal
        return post;
    }
};
