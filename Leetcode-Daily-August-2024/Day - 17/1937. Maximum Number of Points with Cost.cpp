class Solution {
public:
    // Function to find the maximum points that can be collected
    long long maxPoints(vector<vector<int>>& points) {
        // Get the number of rows and columns in the grid
        int row = points.size();
        int col = points[0].size();
        
        // Initialize a DP array to store the maximum points for each column in the previous row
        vector<long long> dp(col, 0);
        
        // Initialize the DP array with the values of the first row
        for(int i = 0; i < col; i++) {
            dp[i] = points[0][i];
        }
        
        // Iterate through each row starting from the second row
        for(int r = 1; r < row; r++) {
            // Arrays to store the maximum values while moving left and right across the row
            vector<long long> leftMax(col, 0), rightMax(col, 0);
            // Array to store the new DP values for the current row
            vector<long long> newDp(col, 0);
            
            // Fill the leftMax array: max value up to each column from the left
            leftMax[0] = dp[0];
            for(int i = 1; i < col; i++) {
                leftMax[i] = max(leftMax[i-1], dp[i] + i);
            }
            
            // Fill the rightMax array: max value up to each column from the right
            rightMax[col-1] = dp[col-1] - (col-1);
            for(int i = col-2; i >= 0; i--) {
                rightMax[i] = max(rightMax[i+1], dp[i] - i);
            }
            
            // Compute the new DP values for the current row
            for(int i = 0; i < col; i++) {
                // The new DP value for each column is the maximum of the adjusted leftMax and rightMax values
                // plus the points in the current cell
                newDp[i] = max(leftMax[i] - i, rightMax[i] + i) + points[r][i];
            }
            
            // Update the DP array for the next iteration
            dp = newDp;
        }
        
        // Return the maximum value from the DP array, which represents the maximum points that can be collected
        return *max_element(dp.begin(), dp.end());
    }
};
