class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Compute the prefix sum array
        vector<int> pre(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1] + nums[i];
        }

        // Step 2: Compute the prefix sum modulo k
        for(int i = 0; i < n; i++)
            pre[i] = pre[i] % k;

        // Step 3: Use a map to store the first occurrence of each prefix sum modulo k
        map<int, int> mp;
        mp[0] = -1; // Initialize with (0, -1) to handle cases where the subarray starts from index 0

        for(int i = 0; i < n; i++){
            // If the current prefix sum modulo k has been seen before
            if(mp.find(pre[i]) != mp.end()){
                int ind1 = mp[pre[i]]; // Retrieve the index of the first occurrence
                int diff = i - ind1; // Calculate the difference in indices
                if(diff >= 2){ // Check if the length of the subarray is at least 2
                    return true; // If so, we have found a valid subarray
                }
            } else {
                // Otherwise, store the index of the first occurrence of this prefix sum modulo k
                mp[pre[i]] = i;
            }
        }

        return false; // No valid subarray found
    }
};
