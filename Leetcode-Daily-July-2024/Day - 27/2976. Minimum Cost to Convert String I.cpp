class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int inf = 1 << 29; // A large number representing infinity
        int g[26][26]; // Graph to store the minimum cost to change one character to another
        
        // Initialize the graph with infinity and 0 for the diagonal
        for (int i = 0; i < 26; ++i) {
            fill(begin(g[i]), end(g[i]), inf);
            g[i][i] = 0; // No cost to change a character to itself
        }

        // Populate the graph with the given conversion costs
        for (int i = 0; i < original.size(); ++i) {
            int x = original[i] - 'a'; // Convert character to index
            int y = changed[i] - 'a'; // Convert character to index
            int z = cost[i]; // Cost of conversion
            g[x][y] = min(g[x][y], z); // Store the minimum cost for the conversion
        }

        // Use Floyd-Warshall algorithm to find the shortest paths between all pairs of characters
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        long long ans = 0; // Initialize the answer
        int n = source.length(); // Length of the source string
        for (int i = 0; i < n; ++i) {
            int x = source[i] - 'a'; // Convert source character to index
            int y = target[i] - 'a'; // Convert target character to index
            if (x != y) { // If characters are different
                if (g[x][y] >= inf) { // If there is no valid conversion path
                    return -1; // Return -1 indicating it's impossible to convert
                }
                ans += g[x][y]; // Add the minimum conversion cost to the answer
            }
        }
        return ans; // Return the total minimum cost
    }
};
