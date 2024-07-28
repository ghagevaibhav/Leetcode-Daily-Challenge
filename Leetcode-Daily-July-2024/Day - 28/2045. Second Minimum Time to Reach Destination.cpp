class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // if the shortest path from 1 to n is of length L
        // find whether there is a path of length L+1
        // there is always a path of length L+2

        // Adjacency list for the graph
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int u = e[0] - 1, v = e[1] - 1;  // Convert to 0-based index
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // BFS to find shortest path lengths from node n to all other nodes
        vector<int> d(n, 1e9);  // Initialize distances with a large value
        d[n - 1] = 0;  // Distance to the target node itself is 0
        queue<int> q;
        q.push(n - 1);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto nei : adj[cur]) {
                if (d[nei] == 1e9) {  // If the node has not been visited
                    d[nei] = d[cur] + 1;
                    q.push(nei);
                }
            }
        }

        // Check the existence of a path with length = d[0] + 1
        int len = d[0] + 2;  // The length of the second minimum path
        q.push(0);
        bool done = false;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto nei : adj[cur]) {
                if (d[nei] == d[cur]) {  // If there's a neighbor with the same distance
                    len--;
                    done = true;
                    break;
                } else if (d[nei] == d[cur] - 1) {  // If the neighbor is one step closer to the goal
                    q.push(nei);
                }
            }
            if (done) break;
        }

        // Calculate the total time needed to traverse the path
        // Traffic light cycle: green in [0, c), [2c, 3c), ... and red in [c, 2c), [3c, 4c), ...
        int currTime = 0;
        for (int i = 0; i < len; i++) {
            if ((currTime / change) % 2 == 1) {  // If it's a red light period, wait until it turns green
                currTime = ((currTime / change) + 1) * change;    
            }
            currTime += time;  // Add the time to traverse one edge
        }
        return currTime;
    }
};
