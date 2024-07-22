class Solution {
public:
    // Main function to build the matrix
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        unordered_map<int, vector<int>> graph;
        
        // Build graph for row conditions
        for (const auto& edge : rowConditions) {
            graph[edge[0]].push_back(edge[1]);
        }

        // Perform topological sort for row conditions
        vector<int> row_sorting = topo_sort(graph, k);
        
        // Clear the graph and build it for column conditions
        graph.clear();
        for (const auto& edge : colConditions) {
            graph[edge[0]].push_back(edge[1]);
        }

        // Perform topological sort for column conditions
        vector<int> col_sorting = topo_sort(graph, k);

        // If topological sorting is not possible (cycle detected), return an empty matrix
        if (row_sorting.empty() || col_sorting.empty()) {
            return {};
        }

        // Map to store the positions of values based on their row and column sorting
        unordered_map<int, pair<int, int>> value_position;
        for (int i = 0; i < k; ++i) {
            value_position[row_sorting[i]].first = i;   // Row index
            value_position[col_sorting[i]].second = i;  // Column index
        }

        // Initialize the result matrix with zeros
        vector<vector<int>> res(k, vector<int>(k, 0));
        for (int value = 1; value <= k; ++value) {
            int row = value_position[value].first;
            int column = value_position[value].second;
            res[row][column] = value;  // Place the value in the matrix based on its sorted position
        }

        return res;
    }

private:
    // Helper function to perform DFS for topological sorting
    bool dfs(int src, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, unordered_set<int>& cur_path, vector<int>& res) {
        if (cur_path.count(src)) return false;  // Cycle detected
        if (visited.count(src)) return true;    // Node already visited

        visited.insert(src);   // Mark the node as visited
        cur_path.insert(src);  // Add the node to the current path

        // Recursively visit all neighbors
        for (int neighbor : graph[src]) {
            if (!dfs(neighbor, graph, visited, cur_path, res))  // If any neighbor causes a cycle
                return false;
        }

        cur_path.erase(src);  // Remove the node from the current path (backtracking)
        res.push_back(src);   // Add the node to the result
        return true;
    }

    // Function to perform topological sort
    vector<int> topo_sort(unordered_map<int, vector<int>>& graph, int k) {
        unordered_set<int> visited;
        unordered_set<int> cur_path;
        vector<int> res;

        // Try to perform DFS for each node from 1 to k
        for (int src = 1; src <= k; ++src) {
            if (!dfs(src, graph, visited, cur_path, res))
                return {};  // Return empty if a cycle is detected
        }

        reverse(res.begin(), res.end());  // Reverse the result to get the correct topological order
        return res;
    }
};
