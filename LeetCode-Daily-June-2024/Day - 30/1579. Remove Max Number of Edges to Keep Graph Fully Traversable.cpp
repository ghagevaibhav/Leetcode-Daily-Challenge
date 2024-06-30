class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // Inner class to handle Union-Find operations
        class UnionFind {
        public:
            vector<int> parent, size;
            int components;
            
            // Constructor to initialize Union-Find structure
            UnionFind(int n) {
                components = n;  // Initially, each node is its own component
                parent.resize(n + 1);  // Parent array to keep track of root of each node
                size.resize(n + 1, 1);  // Size array to keep track of the size of each component
                for (int i = 0; i <= n; ++i) {
                    parent[i] = i;  // Each node is initially its own parent
                }
            }

            // Find function with path compression
            int find(int x) {
                if (parent[x] != x) {
                    parent[x] = find(parent[x]);  // Path compression
                }
                return parent[x];
            }

            // Union function to unite two components
            bool unite(int x, int y) {
                int rootX = find(x), rootY = find(y);
                if (rootX == rootY) return false;  // They are already in the same component
                if (size[rootX] < size[rootY]) swap(rootX, rootY);  // Union by size
                parent[rootY] = rootX;  // Make rootX the parent of rootY
                size[rootX] += size[rootY];  // Update the size of the component
                components--;  // Decrease the number of components
                return true;
            }

            // Check if the entire graph is connected (only one component left)
            bool isConnected() {
                return components == 1;
            }
        };
        
        // Initialize Union-Find structures for Alice and Bob
        UnionFind alice(n), bob(n);
        int edgesRequired = 0;  // Counter for the number of edges used to connect the graph
        
        // Process type 3 edges first (usable by both Alice and Bob)
        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                // If either Alice or Bob can use this edge to unite their components, count it
                if (alice.unite(edge[1], edge[2]) | bob.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            }
        }
        
        // Process type 1 (Alice only) and type 2 (Bob only) edges
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (alice.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            } else if (edge[0] == 2) {
                if (bob.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            }
        }
        
        // Check if both Alice and Bob's graphs are fully connected
        if (alice.isConnected() && bob.isConnected()) {
            // Return the number of edges that can be removed
            return edges.size() - edgesRequired;
        }
        
        // If either graph is not fully connected, return -1
        return -1;
    }
};
