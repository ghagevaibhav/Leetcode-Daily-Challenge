class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;  // This will store all the subsets
        int n = nums.size();  // Get the size of the input array
        int subsets = 1 << n;  // Total number of subsets is 2^n, achieved by shifting 1 left n times
        
        // Iterate over each possible subset
        for(int num = 0; num < subsets; num++){
            vector<int> list;  // This will store the current subset
            for(int i = 0; i < n; i++){
                // Check if the ith bit in num is set
                if(num & (1 << i)){
                    list.push_back(nums[i]);  // If the bit is set, include nums[i] in the current subset
                }
            }
            ans.push_back(list);  // Add the current subset to the list of all subsets
        }
        
        return ans;  // Return all the subsets
    }
};
