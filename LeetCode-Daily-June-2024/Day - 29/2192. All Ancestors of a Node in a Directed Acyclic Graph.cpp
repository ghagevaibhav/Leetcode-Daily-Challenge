class Solution {
public:
    // Function to compute ancestors for each node in a directed graph
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Initialize two vectors of vectors: 'ans' for ancestors and 'directChild' for children
        vector<vector<int>> ans(n), directChild(n);
        
        // Step 1: Build directChild adjacency list from the edges
        for (auto& e : edges) {
            directChild[e[0]].push_back(e[1]);
        }
        
        // Step 2: Perform DFS from each node to find ancestors
        for (int i = 0; i < n; i++) {
            dfs(i, i, ans, directChild); // Start DFS from node 'i' with itself as the initial ancestor
        }
        
        // Return the computed ancestors for each node
        return ans;
    }

private:
    // Recursive function to perform DFS and populate ancestors
    void dfs(int x, int curr, vector<vector<int>>& ans, vector<vector<int>>& directChild) {
        // Traverse each child of the current node 'curr'
        for (int ch : directChild[curr]) {
            // Ensure 'x' is added to ancestors of 'ch' only once
            if (ans[ch].empty() || ans[ch].back() != x) {
                ans[ch].push_back(x); // Add 'x' as an ancestor of 'ch'
                dfs(x, ch, ans, directChild); // Recursively call DFS for node 'ch'
            }
        }
    }
};
