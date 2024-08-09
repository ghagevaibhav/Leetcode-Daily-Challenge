class Solution {
    // Helper function to check if a 3x3 grid starting at (i, j) is a magic square
    bool isValid(int i, int j, vector<vector<int>>& grid) {
        // Create a count array to track occurrences of digits 1-9
        vector<int> count(10, 0);

        // Check each number in the 3x3 grid
        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 3; ++y) {
                int num = grid[i + x][j + y];
                // If number is out of range or already encountered, return false
                if (num < 1 || num > 9 || count[num] > 0) return false;
                count[num]++;
            }
        }

        // Calculate the sum of the first row
        int sum = grid[i][j] + grid[i][j+1] + grid[i][j+2];
        
        // Check if all rows have the same sum
        for(int x = 0; x < 3; ++x) {
            if(sum != (grid[i + x][j] + grid[i + x][j + 1] + grid[i + x][j + 2])) return false;
        }
        
        // Check if all columns have the same sum
        for(int y = 0; y < 3; ++y) {
            if(sum != (grid[i][j + y] + grid[i + 1][j + y] + grid[i + 2][j + y])) return false;
        }
        
        // Check if both diagonals have the same sum
        if(sum != (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2])) return false;
        if(sum != (grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2])) return false;

        // If all checks passed, return true
        return true;
    }
    
public:
    // Function to count the number of 3x3 magic squares inside the grid
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt = 0;
        int row = grid.size();
        int col = grid[0].size();
        
        // If grid is smaller than 3x3, return 0
        if(row < 3 || col < 3) return 0;

        // Iterate through the grid, checking each 3x3 subgrid
        for(int i = 0; i <= row - 3; ++i) {
            for(int j = 0; j <= col - 3; ++j) {
                // If the current 3x3 grid is a magic square, increment count
                if(isValid(i, j, grid)) cnt++;
            }
        }
        // Return the total count of magic squares found
        return cnt;
    }
};
