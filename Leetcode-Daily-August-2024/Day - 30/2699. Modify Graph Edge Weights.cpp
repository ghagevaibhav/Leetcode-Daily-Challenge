class Solution {
public:
    // Define a large constant to represent an infinite distance
    const int INF = 2e9;

    // Function to modify the graph edges to achieve the desired shortest path
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges,
                                           int source, int destination,
                                           int target) {
        // Create an adjacency list to represent the graph
        vector<vector<pair<int, int>>> graph(n);
        
        // Populate the graph with existing edges (ignore edges with -1 weight for now)
        for (const auto& edge : edges) {
            if (edge[2] != -1) {
                graph[edge[0]].emplace_back(edge[1], edge[2]);
                graph[edge[1]].emplace_back(edge[0], edge[2]);
            }
        }

        // Run Dijkstra's algorithm to find the shortest path from source to destination
        int currentShortestDistance = runDijkstra(n, source, destination, graph);
        
        // If the current shortest distance is less than the target, return an empty result
        if (currentShortestDistance < target) {
            return vector<vector<int>>();
        }

        // Check if the current shortest distance matches the target
        bool matchesTarget = (currentShortestDistance == target);
        
        // Iterate through the edges to adjust weights where needed
        for (auto& edge : edges) {
            // Skip edges that already have a specified weight
            if (edge[2] != -1)
                continue;
            
            // Set the edge weight to infinity if we have already matched the target
            // Otherwise, set it to 1 as a starting point
            edge[2] = matchesTarget ? INF : 1;
            
            // Add the edge to the graph with the new weight
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
            
            // If we haven't matched the target, re-run Dijkstra's algorithm
            if (!matchesTarget) {
                int newDistance = runDijkstra(n, source, destination, graph);
                
                // If the new distance is less than or equal to the target, adjust the weight
                if (newDistance <= target) {
                    matchesTarget = true;
                    edge[2] += target - newDistance; // Increase the weight to match the target
                }
            }
        }
        
        // Return the modified edges if we successfully matched the target distance
        return matchesTarget ? edges : vector<vector<int>>();
    }

private:
    // Helper function to run Dijkstra's algorithm to find the shortest path
    int runDijkstra(int n, int source, int destination,
                    const vector<vector<pair<int, int>>>& graph) {
        // Initialize the minimum distance vector with infinity
        vector<int> minDistance(n, INF);
        
        // Boolean array to keep track of visited nodes
        vector<bool> visited(n, false);
        
        // Min-heap to get the node with the smallest distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        // Start with the source node
        minDistance[source] = 0;
        minHeap.emplace(0, source);

        while (!minHeap.empty()) {
            // Extract the node with the smallest distance
            auto [d, u] = minHeap.top();
            minHeap.pop();

            // Skip if the node has already been processed
            if (d > minDistance[u]) continue;

            // Iterate through the neighbors of the current node
            for (const auto& [v, weight] : graph[u]) {
                // If a shorter path to neighbor v is found, update it
                if (d + weight < minDistance[v]) {
                    minDistance[v] = d + weight;
                    minHeap.emplace(minDistance[v], v);
                }
            }
        }

        // Return the shortest distance to the destination node
        return minDistance[destination];
    }
};
