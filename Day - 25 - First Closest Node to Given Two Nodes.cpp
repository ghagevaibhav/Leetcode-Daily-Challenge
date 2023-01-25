class Solution {
public:
    void dfs(int u, vector<int>& d, vector<int>& vis, vector<int>& edges) {
        // mark it visited
        vis[u] = 1;
        // check the outgoing edge
        int v = edges[u];
        // -1 means there is no outgoing edge, so we skip it
        // if it is visited, we also skip it
        if (v != -1 && !vis[v]) {
            d[v] = d[u] + 1;
            dfs(v, d, vis, edges);
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> d1(n, INT_MAX), d2(n, INT_MAX);
      
        vector<int> vis1(n, 0), vis2(n, 0);
        d1[node1] = 0, d2[node2] = 0;
        dfs(node1, d1, vis1, edges);
        dfs(node2, d2, vis2, edges);
        int ans = -1, mi = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (max(d1[i], d2[i]) < mi) {
                mi = max(d1[i], d2[i]);
                ans = i;
            }
        }
        return ans;
    }
};
