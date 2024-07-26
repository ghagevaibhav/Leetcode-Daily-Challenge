class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize the distance matrix with a large value (10001) indicating no direct path
        vector<vector<int>> dis(n, vector(n, 10001));
        int res = 0; // Result variable to store the city with the smallest number of reachable cities
        int smallest = n; // Variable to store the smallest number of reachable cities found
        
        // Populate the distance matrix with the given edges
        for (auto& e : edges)
            dis[e[0]][e[1]] = dis[e[1]][e[0]] = e[2];
        
        // Set the distance from each city to itself as 0
        for (int i = 0; i < n; ++i)
            dis[i][i] = 0;
        
        // Apply Floyd-Warshall algorithm to find the shortest paths between all pairs of cities
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        
        // Determine the city with the smallest number of cities within the distance threshold
        for (int i = 0; i < n; i++) {
            int count = 0; // Variable to count the number of reachable cities from city i
            for (int j = 0; j < n; ++j)
                if (dis[i][j] <= distanceThreshold)
                    ++count;
            // Update the result if the current city has fewer or equal reachable cities compared to the smallest found
            if (count <= smallest) {
                res = i;
                smallest = count;
            }
        }
        return res; // Return the city with the smallest number of reachable cities
    }
};
