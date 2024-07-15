class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // Map to store node values and corresponding TreeNode pointers
        unordered_map<int, TreeNode*> mp;
        // Set to store child node values
        unordered_set<int> children;

        // Iterate over each description
        for(auto& arr: descriptions){
            int parent = arr[0], child = arr[1], isLeft = arr[2];
            // Add child to the set of children
            children.insert(child);

            // If the parent node is not yet created, create it
            if(mp.find(parent) == mp.end()){
                mp[parent] = new TreeNode(parent);
            }

            // If the child node is not yet created, create it
            if(mp.find(child) == mp.end()){
                mp[child] = new TreeNode(child);
            }

            // Attach the child node to the appropriate side of the parent node
            if(isLeft == 1){
                mp[parent]->left = mp[child];
            }
            else{
                mp[parent]->right = mp[child];
            }
        }

        int root = -1;
        // Find the root node (which is not a child of any other node)
        for(auto& arr: descriptions){
            if(children.find(arr[0]) == children.end()){
                root = arr[0];
                break;
            }
        }

        // Return the root of the constructed binary tree
        return mp[root];
    }
};
