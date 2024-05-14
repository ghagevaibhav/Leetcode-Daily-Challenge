class Solution {
public:

    // Variable to store the maximum amount of gold collected
    int ans = INT_MIN;

    // Direction vectors for moving up, down, left, and right
    vector<int> row = {1, -1, 0, 0};
    vector<int> col = {0, 0, -1, 1};

    // Depth-First Search (DFS) function to explore the grid and collect gold
    int dfs(vector<vector<int>> &grid, int x, int y, int n, int m){
        // Base case: if out of bounds or cell is 0 (no gold), return 0
        if(x < 0 || x >= n || y <  0 || y >= m || grid[x][y] == 0 ) return 0;

        // Store the current cell's gold and mark the cell as visited by setting it to 0
        int cur = grid[x][y];
        grid[x][y] = 0;
        
        // Variable to store the maximum gold collected starting from this cell
        int local = cur;

        // Explore all four possible directions
        for(int i = 0; i < 4; i++){
            int newX = x + row[i];
            int newY = y + col[i];
            // Recursively collect gold from the neighboring cells and update the local maximum
            local = max(local, cur + dfs(grid, newX, newY, n, m));
        }

        // Restore the cell's value after exploring all directions (backtracking)
        grid[x][y] = cur;

        // Return the maximum gold collected starting from this cell
        return local; 
    }

    // Main function to find the maximum amount of gold that can be collected
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(); // Number of rows in the grid
        int m = grid[0].size(); // Number of columns in the grid

        // Traverse each cell in the grid
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // Start a DFS from each cell and update the global maximum amount of gold
                ans = max(ans, dfs(grid, i, j, n, m));
            }
        }

        // Return the maximum amount of gold collected
        return ans;
    }
};
