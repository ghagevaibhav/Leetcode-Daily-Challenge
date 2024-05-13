#pragma GCC optimize ("Ofast")                // Optimize for fast execution
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")  // Target specific CPU features
#pragma GCC optimize ("-ffloat-store")       // Disable floating-point optimizations
#pragma GCC optimize ("O3", "unroll-loops")  // Optimize for speed and unroll loops

class Solution {
public:
    // Function to compute the score of a matrix
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();                    // Number of rows
        int m = grid[0].size();                // Number of columns
        int ans = n * (1 << (m-1-0));          // Initialize score based on first column

        // Iterate through columns (excluding first)
        for(int j = 1; j < m; j++){
            int colcnt = 0;                    // Counter for number of ones in current column
            for(int i= 0; i < n; i++){
                // Count ones in column, considering flipping if first element of row is zero
                colcnt += grid[i][0] == 0 ? (grid[i][j] ^ 1) : grid[i][j];
            }
            // Check if flipping the column increases the score
            if(colcnt < n-colcnt){
                ans += (n-colcnt) * (1 << (m-1-j));  // Update score if flipping increases it
            }
            else 
                ans += colcnt * (1 << (m-1-j));      // Otherwise, update score as is
        }
        return ans;  // Return the total score of the matrix
    }
};
