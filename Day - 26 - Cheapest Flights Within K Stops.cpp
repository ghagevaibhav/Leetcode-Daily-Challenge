class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto x : flights){
            adj[x[0]].push_back({x[1], x[2]});
        }

        vector<int> cost(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({src, 0});
        int count = 0;
        while(count<= k && !q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                int node = q.front().first;
                int price = q.front().second;
                q.pop();

                for(auto [neighbour, fair]: adj[node]){
                    if(fair+price >= cost[neighbour])
                        continue;
                    cost[neighbour] = fair+price;
                    q.push({neighbour, cost[neighbour]});
                }
            }

            count++;
        }
        if(cost[dst] == INT_MAX){
            return -1;
        }
        return cost[dst];

    }
};
