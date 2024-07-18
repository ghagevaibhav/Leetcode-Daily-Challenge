class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // Map to store the resulting forest with tree roots
        unordered_map<int, TreeNode*> res;
        // Set for quick lookup of nodes to be deleted
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        // Initialize the result with the root node
        res[root->val] = root;

        // Recursive function to traverse the tree
        function<void(TreeNode*, TreeNode*, bool)> recursion = [&](TreeNode* parent, TreeNode* cur_node, bool isleft) {
            if (cur_node == nullptr) return; // Base case: If current node is null, return
            
            // Traverse left and right children
            recursion(cur_node, cur_node->left, true);
            recursion(cur_node, cur_node->right, false);

            // Check if the current node needs to be deleted
            if (to_delete_set.find(cur_node->val) != to_delete_set.end()) {
                // Remove the current node from result map if present
                if (res.find(cur_node->val) != res.end()) {
                    res.erase(cur_node->val);
                }

                // Disconnect the current node from its parent
                if (parent) {
                    if (isleft) {
                        parent->left = nullptr;
                    } else {
                        parent->right = nullptr;
                    }
                }

                // Add the left child to the result if it exists
                if (cur_node->left) {
                    res[cur_node->left->val] = cur_node->left;
                }
                // Add the right child to the result if it exists
                if (cur_node->right) {
                    res[cur_node->right->val] = cur_node->right;
                }
            }
        };

        // Start the recursion with the root node
        recursion(nullptr, root, false);
        
        // Prepare the final result from the map
        vector<TreeNode*> result;
        for (auto& pair : res) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};
