class Solution {
public:
    // Recursive Depth First Search (DFS) function to find beautiful subsets
    int dfs(vector<int> &nums, int idx, int k, unordered_map<int, int> &mp) {
        // Base case: If we have processed all elements, return 1 (indicating one valid subset)
        if(idx == nums.size()) return 1;

        int taken = 0;
        // Check if current element can be taken into the subset without violating the conditions
        // Condition: nums[idx] - k and nums[idx] + k should not be present in the current subset
        if(!mp[nums[idx] - k] && !mp[nums[idx] + k]) {
            // Include current element in the subset
            mp[nums[idx]]++;
            // Recurse to the next element
            taken = dfs(nums, idx + 1, k, mp);
            // Backtrack: Remove current element from the subset
            mp[nums[idx]]--;
        }
        
        // Recursive call for the case when the current element is not included in the subset
        int notTaken = dfs(nums, idx + 1, k, mp);
        
        // Return the sum of both cases: including the current element and not including it
        return taken + notTaken;
    }

    // Function to count all beautiful subsets of the given array
    int beautifulSubsets(vector<int> &nums, int k) {
        unordered_map<int, int> mp; // Map to keep track of elements included in the current subset
        int ans = dfs(nums, 0, k, mp); // Start the DFS from the first element
        return ans - 1; // Subtract 1 to exclude the empty subset from the count
    }
};
