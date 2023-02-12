class Solution {
public:
    int dfs (int cur, int par, vector<int> *adj, long long &ans, int &seats) {
        int subTreeSize = 1;
        for (int nb : adj[cur])
            if(nb != par)
                subTreeSize += dfs(nb, cur, adj, ans, seats);
        if(par!=-1) ans += (subTreeSize/seats) + (bool)(subTreeSize%seats);
        return subTreeSize;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = size(roads) + 1;
        long long ans = 0;
        vector<int> adj[n];
        for (vector<int> road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        dfs(0, -1, adj, ans, seats);
        return ans;
    }
};
