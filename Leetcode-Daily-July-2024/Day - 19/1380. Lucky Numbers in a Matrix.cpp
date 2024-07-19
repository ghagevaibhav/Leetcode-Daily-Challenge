class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        // Get the number of rows (n) and columns (m) in the matrix
        int n = mat.size();
        int m = mat[0].size();
        
        // Vector to store the lucky numbers
        vector<int> ans;
        
        // Variables to track if the current element is the minimum in its row and maximum in its column
        bool a = false, b = false;
        
        // Iterate over each element in the matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // Find the minimum element in the current row
                int mini = *min_element(mat[i].begin(), mat[i].end());
                
                // Check if the current element is the minimum in its row
                if(mat[i][j] == mini) a = true;
                
                // Initialize maxi to the smallest possible integer
                int maxi = INT_MIN;
                
                // Find the maximum element in the current column
                for(int k = 0; k < n; k++){
                    if(mat[k][j] > maxi) maxi = mat[k][j];
                }
                
                // Check if the current element is the maximum in its column
                if(mat[i][j] == maxi) b = true;
                
                // If the current element is both the minimum in its row and maximum in its column, it's a lucky number
                if(a && b) ans.push_back(mat[i][j]);
                
                // Reset the flags for the next element
                a = false, b = false;
            }
        }
        // Return the vector of lucky numbers
        return ans;
    }
};
