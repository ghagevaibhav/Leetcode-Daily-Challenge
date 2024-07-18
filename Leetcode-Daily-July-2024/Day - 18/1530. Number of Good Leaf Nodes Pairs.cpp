/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    // Recursive function to calculate distances and count pairs
    vector<int> recur(TreeNode* root, int distance, int &cnt) {
        if (!root) return {0};  // Base case: if node is null, return vector with 0

        if (!root->left && !root->right) return {1};  // If leaf node, return vector with 1

        // Recursively calculate distances for left and right subtrees
        vector<int> left = recur(root->left, distance, cnt);
        vector<int> right = recur(root->right, distance, cnt);

        // Count pairs from left and right subtrees within the given distance
        for (int x : left) {
            for (int y : right) {
                if (x > 0 && y > 0) {
                    if (x + y <= distance) cnt++;
                }
            }
        }

        vector<int> ans;
        // Collect distances from the left subtree within the given distance
        for (int x : left) {
            if (x > 0 && x < distance) {
                ans.push_back(x + 1);
            }
        }

        // Collect distances from the right subtree within the given distance
        for (int x : right) {
            if (x > 0 && x < distance) {
                ans.push_back(x + 1);
            }
        }

        return ans;
    }

    // Main function to count pairs of nodes within the given distance
    int countPairs(TreeNode* root, int distance) {
        int cnt = 0;  // Initialize counter for pairs
        recur(root, distance, cnt);  // Call recursive function
        return cnt;  // Return the count of pairs
    }
};
