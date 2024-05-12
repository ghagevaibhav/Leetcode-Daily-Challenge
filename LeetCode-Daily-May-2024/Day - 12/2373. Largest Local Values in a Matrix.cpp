class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size(); // Get the size of the grid
        // Create a 2D vector to store the result, with dimensions (n-2) x (n-2)
        vector<vector<int>> ans(n-2, vector<int>(n-2));
        
        // Iterate over the grid, excluding the last two rows and columns
        for(int i = 0; i < n-2; i++){
            for(int j = 0; j < n-2; j++){
                // For each cell, find the maximum value in the 3x3 subgrid centered around it
                
                // Find the maximum value in the first row of the subgrid
                int row1 = max(grid[i][j], max(grid[i][j+1], grid[i][j+2]));
                
                // Find the maximum value in the second row of the subgrid
                int row2 = max(grid[i+1][j], max(grid[i+1][j+1], grid[i+1][j+2]));
                
                // Find the maximum value in the third row of the subgrid
                int row3 = max(grid[i+2][j], max(grid[i+2][j+1], grid[i+2][j+2]));
                
                // Find the maximum value among the maximum values of each row
                int val = max(max(row1, row2), row3);
                
                // Store the maximum value in the result grid at the corresponding position
                ans[i][j] = val;
            }
        }
        // Return the result grid
        return ans;
    }
};
