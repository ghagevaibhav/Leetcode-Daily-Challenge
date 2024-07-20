class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        // Get the number of rows and columns
        int n = rowSum.size();
        int m = colSum.size();

        // Initialize a matrix with n rows and m columns filled with zeros
        vector<vector<int>> matrix(n, vector<int>(m));

        // Iterate over each cell in the matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // Set the value of the current cell to the minimum of rowSum[i] and colSum[j]
                if(rowSum[i] < colSum[j]){
                    matrix[i][j] = rowSum[i];
                }
                else if(rowSum[i] > colSum[j]){
                    matrix[i][j] = colSum[j];
                }
                else {
                    matrix[i][j] = rowSum[i];
                }

                // Update the remaining rowSum and colSum after filling the current cell
                rowSum[i] -= matrix[i][j];
                colSum[j] -= matrix[i][j];
            }
        }
        // Return the resulting matrix
        return matrix;
    }
};
