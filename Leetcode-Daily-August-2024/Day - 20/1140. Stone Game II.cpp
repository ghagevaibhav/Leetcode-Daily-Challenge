class Solution {
public:
    // Helper function to calculate the maximum number of stones the first player can get.
    // piles: The vector containing the piles of stones.
    // dp: Memoization table to store results of subproblems.
    // suffixSum: Precomputed suffix sums to make sum calculations faster.
    // i: Current index in the piles vector.
    // M: The current value of M (number of piles that can be taken).
    int helper(vector<int>& piles, vector<vector<int>>& dp, const vector<int>& suffixSum, int i, int M) {
        // Base case: if we've considered all piles, return 0 (no more stones can be taken).
        if (i == piles.size()) return 0;
        
        // If the remaining piles are fewer than or equal to 2 * M, take all remaining stones.
        if (i + 2 * M >= piles.size()) return suffixSum[i];
        
        // If this subproblem has already been solved, return the stored result.
        if (dp[i][M] != 0) return dp[i][M];
        
        int result = 0;
        // Try taking x piles, where x ranges from 1 to 2 * M.
        for (int x = 1; x <= 2 * M; ++x) {
            // Calculate the result by choosing x piles and then letting the opponent play optimally.
            result = max(result, suffixSum[i] - helper(piles, dp, suffixSum, i + x, max(M, x)));
        }
        
        // Store the result in dp table to avoid recalculating.
        dp[i][M] = result;
        return result;
    }

    // Main function to solve the Stone Game II problem.
    int stoneGameII(vector<int>& piles) {
        // If there are no piles, return 0 (no stones to take).
        if (piles.empty()) return 0;
        
        // Initialize dp table with size n x n filled with 0.
        vector<vector<int>> dp(piles.size(), std::vector<int>(piles.size(), 0));
        
        // Compute the suffix sums: suffixSum[i] is the total number of stones from pile i to the end.
        vector<int> suffixSum(piles.size());
        suffixSum[suffixSum.size() - 1] = piles[piles.size() - 1];
        for (int i = piles.size() - 2; i >= 0; --i) {
            suffixSum[i] = piles[i] + suffixSum[i + 1];
        }
        
        // Start the game from the first pile with M = 1.
        return helper(piles, dp, suffixSum, 0, 1);
    }
};
