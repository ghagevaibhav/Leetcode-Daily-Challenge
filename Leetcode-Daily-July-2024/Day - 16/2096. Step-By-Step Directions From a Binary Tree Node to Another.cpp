class Solution {
public:
    // Function to find the lowest common ancestor (LCA) of nodes p and q
    TreeNode* lca(TreeNode* node, int p, int q){
        if(node == nullptr) return nullptr;  // Base case: if the node is null, return null

        // Recursively find LCA in the left and right subtrees
        TreeNode* leftside = lca(node->left, p, q);
        TreeNode* rightside = lca(node->right, p, q);

        // If both sides are non-null or the current node is either p or q, this is the LCA
        if((leftside && rightside) || (node->val == p || node->val == q))
            return node;
        
        // Return the non-null side, or null if both are null
        return (leftside == nullptr) ? rightside : leftside;
    }

    string lcatostart, lcatoend; // Variables to store paths from LCA to start and destination

    // Helper function to perform DFS and find paths from LCA to startValue and destValue
    void dfs(TreeNode* node, string& path, int p, int q){
        if(node == nullptr) return;  // Base case: if the node is null, return
        if(node->val == p) lcatostart = path;  // If current node is startValue, save the path
        if(node->val == q) lcatoend = path;    // If current node is destValue, save the path

        path.push_back('L');  // Add 'L' to path and go to the left child
        dfs(node->left, path, p, q);
        path.pop_back();  // Backtrack

        path.push_back('R');  // Add 'R' to path and go to the right child
        dfs(node->right, path, p, q);
        path.pop_back();  // Backtrack
    }

    // Main function to get directions from startValue to destValue
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lcanode = lca(root, startValue, destValue);  // Find the LCA of startValue and destValue
        string path = "";
        dfs(lcanode, path, startValue, destValue);  // Find paths from LCA to startValue and destValue

        // Convert the path to startValue to 'U' (upwards) and concatenate with the path to destValue
        for(auto& ch: lcatostart) ch = 'U';
        return lcatostart + lcatoend;
    }
};
