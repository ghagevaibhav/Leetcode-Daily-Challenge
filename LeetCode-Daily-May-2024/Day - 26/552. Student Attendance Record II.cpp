class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1000000007; // Define the modulo constant to handle large numbers
        vector<vector<int>> dp_last(2, vector<int>(3, 0)); // Initialize the DP array for the previous state
        vector<vector<int>> dp_current(2, vector<int>(3, 0)); // Initialize the DP array for the current state

        dp_last[0][0] = 1; // Base case: There is one way to have an empty string with 0 'A's and 0 'L's

        for (int i = 0; i < n; i++) { // Iterate over each position in the string
            for (int count_a = 0; count_a < 2; count_a++) { // Iterate over possible counts of 'A' (0 or 1)
                for (int count_l = 0; count_l < 3; count_l++) { // Iterate over possible counts of consecutive 'L's (0 to 2)
                    // Choose "P"
                    dp_current[count_a][0] = (dp_current[count_a][0] + dp_last[count_a][count_l]) % MOD; // Reset consecutive 'L' count

                    // Choose "A"
                    if (count_a == 0) { // Only add 'A' if there are no 'A's yet
                        dp_current[count_a + 1][0] = (dp_current[count_a + 1][0] + dp_last[count_a][count_l]) % MOD; // Reset consecutive 'L' count and increment 'A' count
                    }

                    // Choose "L"
                    if (count_l < 2) { // Only add 'L' if there are less than 2 consecutive 'L's
                        dp_current[count_a][count_l + 1] = (dp_current[count_a][count_l + 1] + dp_last[count_a][count_l]) % MOD; // Increment consecutive 'L' count
                    }
                }
            }
            dp_last = dp_current; // Move current state to previous state for the next iteration
            dp_current = vector<vector<int>>(2, vector<int>(3, 0)); // Reset current state for the next iteration
        }

        // Sum up the counts for all combinations of length 'n' with different count_a and count_l.
        int res = 0;
        for (int count_a = 0; count_a < 2; count_a++) {
            for (int count_l = 0; count_l < 3; count_l++) {
                res = (res + dp_last[count_a][count_l]) % MOD; // Aggregate results from the last state
            }
        }
        return res; // Return the total number of valid combinations
    }
};
