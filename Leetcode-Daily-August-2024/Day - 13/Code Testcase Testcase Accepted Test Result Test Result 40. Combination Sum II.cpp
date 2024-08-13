class Solution {
public:
    // Helper function to find all unique combinations that sum to the target
    void helper(int index, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds) {
        // Base case: if the target becomes 0, we have found a valid combination
        if (target == 0) {
            ans.push_back(ds); // Add the current combination (ds) to the answer list
            return;
        }

        // Iterate through the candidates starting from the current index
        for (int i = index; i < candidates.size(); i++) {
            // If the current candidate exceeds the target, no point in continuing (since the array is sorted)
            if (candidates[i] > target) break;

            // Skip duplicate elements to avoid redundant combinations
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            // Include the current candidate in the current combination
            ds.push_back(candidates[i]);

            // Recur with the next index and the reduced target
            helper(i + 1, target - candidates[i], candidates, ans, ds);

            // Backtrack: remove the last element added to the combination
            ds.pop_back();
        }
    }

    // Main function to find all unique combinations that sum to the target
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort the candidates to handle duplicates easily
        vector<vector<int>> ans; // To store all the unique combinations
        vector<int> ds; // To store the current combination
        helper(0, target, candidates, ans, ds); // Call the helper function
        return ans;
    }
};
