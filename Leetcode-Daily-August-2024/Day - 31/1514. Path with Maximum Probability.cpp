class Solution {
public:
    // Function to find the maximum probability of reaching the end_node from start_node
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Initialize a vector to store the maximum probability to reach each node
        vector<double> maxProb(n, 0.0);
        // The probability of reaching the start_node is 1 (100%)
        maxProb[start_node] = 1.0;

        // Perform Bellman-Ford algorithm for n-1 iterations to find the maximum probabilities
        for (int i = 0; i < n - 1; ++i) {
            bool updated = false;  // Flag to check if any update happened in this iteration
            for (int j = 0; j < edges.size(); ++j) {
                int u = edges[j][0];  // Starting node of the edge
                int v = edges[j][1];  // Ending node of the edge
                double prob = succProb[j];  // Success probability of the edge

                // Update the maximum probability to reach node v if a higher probability path is found
                if (maxProb[u] * prob > maxProb[v]) {
                    maxProb[v] = maxProb[u] * prob;
                    updated = true;  // Mark that an update has occurred
                }
                // Update the maximum probability to reach node u if a higher probability path is found
                if (maxProb[v] * prob > maxProb[u]) {
                    maxProb[u] = maxProb[v] * prob;
                    updated = true;  // Mark that an update has occurred
                }
            }
            // If no updates happened in this iteration, the probabilities have stabilized, so break out of the loop
            if (!updated) break;
        }

        // Return the maximum probability of reaching the end_node
        return maxProb[end_node];
    }
};
