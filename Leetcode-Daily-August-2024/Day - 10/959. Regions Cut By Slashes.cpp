class Solution {
    // Union-Find data structures
    vector<int> parent; // To track the parent of each node
    vector<int> rank;   // To maintain the rank (depth) of the tree
    int count;          // To count the number of regions formed

public:
    // Function to calculate the number of regions formed by slashes
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int dots = n + 1;  // Number of dots is one more than grid size
        parent.resize(dots * dots); // Initialize parent array for Union-Find
        rank.resize(dots * dots, 1); // Initialize rank array
        count = 0;

        // Initialize Union-Find structure where each node is its own parent
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }

        // Connect the boundaries (edges of the grid) to the top-left corner (0,0)
        for (int i = 0; i < dots; ++i) {
            for (int j = 0; j < dots; ++j) {
                // If the cell is on the boundary, connect it to the corner
                if (i == 0 || j == 0 || i == n || j == n) {
                    int cell = i * dots + j;
                    unionSets(0, cell);
                }
            }
        }

        // Process each cell in the grid and union regions based on the slashes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '\\') {
                    // Union the two diagonal dots in the same region for a '\\'
                    int cell1 = i * dots + j;
                    int cell2 = (i + 1) * dots + (j + 1);
                    unionSets(cell1, cell2);
                } else if (grid[i][j] == '/') {
                    // Union the two diagonal dots in different regions for a '/'
                    int cell1 = (i + 1) * dots + j;
                    int cell2 = i * dots + (j + 1);
                    unionSets(cell1, cell2);
                }
            }
        }

        return count;
    }
    
private:
    // Union-Find function to unite two sets
    void unionSets(int a, int b) {
        int parentA = find(a); // Find root of set containing 'a'
        int parentB = find(b); // Find root of set containing 'b'
        
        // If both have the same root, a cycle is detected, increase count
        if (parentA == parentB) {
            count++;
        } else {
            // Union by rank
            if (rank[parentA] > rank[parentB]) {
                parent[parentB] = parentA; // Make parentA the root of parentB
            } else if (rank[parentA] < rank[parentB]) {
                parent[parentA] = parentB; // Make parentB the root of parentA
            } else {
                parent[parentB] = parentA; // If ranks are the same, choose one as root
                rank[parentA]++; // Increment rank
            }
        }
    }
    
    // Union-Find function to find the root of the set containing 'a'
    int find(int a) {
        if (parent[a] == a) {
            return a; // If 'a' is its own parent, return 'a'
        }
        return parent[a] = find(parent[a]); // Path compression
    }
};
