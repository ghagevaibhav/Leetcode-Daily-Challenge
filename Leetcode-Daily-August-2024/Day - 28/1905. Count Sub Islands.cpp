class Solution {
public:
    // This function counts the number of sub-islands in matrix A that are also islands in matrix B
    int countSubIslands(vector<vector<int>>& B, vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size(), res = 0;

        // Iterate over each cell in matrix A
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the cell in A is part of an island (i.e., A[i][j] == 1), 
                // perform a DFS to check if it forms a sub-island.
                if (A[i][j] == 1)
                    res += dfs(B, A, i, j);
            }
        }

        // Return the total count of sub-islands
        return res;
    }

    // Depth-First Search (DFS) function to check if the island in A is a sub-island of B
    int dfs(vector<vector<int>>& B, vector<vector<int>>& A, int i, int j) {
        int m = A.size(), n = A[0].size(), res = 1;

        // Base case: If the current position is out of bounds or water in A, return 1 (true)
        if (i < 0 || i == m || j < 0 || j == n || A[i][j] == 0) return 1;

        // Mark the current cell in A as visited by setting it to 0 (water)
        A[i][j] = 0;

        // Perform DFS in all four directions (up, down, left, right) and accumulate the results
        res &= dfs(B, A, i - 1, j);  // Up
        res &= dfs(B, A, i + 1, j);  // Down
        res &= dfs(B, A, i, j - 1);  // Left
        res &= dfs(B, A, i, j + 1);  // Right

        // Return the result of the current cell in B combined with the results of DFS
        // If B[i][j] is 1 and all dfs calls return 1, it confirms that the current island in A is a sub-island of B.
        return res & B[i][j];
    }
};
