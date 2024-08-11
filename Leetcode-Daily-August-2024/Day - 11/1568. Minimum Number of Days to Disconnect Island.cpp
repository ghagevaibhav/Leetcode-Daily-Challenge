class Solution {
public:
    // Function to calculate the minimum number of days required to disconnect the grid
    int minDays(vector<vector<int>>& grid) {
        // Lambda function to count the number of islands in the grid
        auto count_islands = [&]() -> int {
            vector<vector<int>> seen(grid.size(), vector<int>(grid[0].size(), 0)); // Keeps track of visited cells
            int islands = 0; // Number of islands found
            
            // Depth-first search (DFS) function to traverse the grid and mark connected land cells
            function<void(int, int)> dfs = [&](int r, int c) {
                seen[r][c] = 1; // Mark the current cell as seen (visited)
                // Explore the four possible directions: up, down, left, and right
                for (auto [dr, dc] : {pair{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                    int nr = r + dr, nc = c + dc; // Calculate the new row and column
                    // Check if the new cell is within bounds, is land, and hasn't been seen yet
                    if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1 && !seen[nr][nc]) {
                        dfs(nr, nc); // Recursively call dfs on the new cell
                    }
                }
            };
            
            // Loop through each cell in the grid
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    // If the cell is land and hasn't been visited, it's a new island
                    if (grid[i][j] == 1 && !seen[i][j]) {
                        islands++; // Increment the island count
                        dfs(i, j); // Perform DFS to mark all connected cells
                    }
                }
            }
            return islands; // Return the total number of islands found
        };
        
        // If the number of islands is not equal to 1 initially, return 0 (no need to remove any land)
        if (count_islands() != 1) return 0;
        
        // Try to disconnect the island by removing each land cell one by one
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) { // If the cell is land
                    grid[i][j] = 0; // Temporarily set it to water
                    // If removing this cell results in more than one island, return 1
                    if (count_islands() != 1) return 1;
                    grid[i][j] = 1; // Restore the cell back to land
                }
            }
        }
        
        // If no single cell removal can disconnect the island, return 2
        return 2;
    }
};
