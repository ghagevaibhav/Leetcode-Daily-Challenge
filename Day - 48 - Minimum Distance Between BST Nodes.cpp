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

 void inorder(TreeNode* root,vector<int>&ans)
 {
    if(root==NULL)return;  
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans); 
}

    int minDiffInBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);

        int mini = INT_MAX;

        for(int i = 0;i<v.size()-1;++i)
            if(v[i]!=v[i+1]) mini = min(mini,v[i+1]-v[i]);   
        
        return mini;
    }
};
