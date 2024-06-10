class Solution {
public:
    // Function to find the number of subarrays whose sum is divisible by k
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(); // Size of the input array
        int ans = 0; // To store the final count of subarrays
        int pre = 0; // To store the cumulative sum modulo k
        vector<int> sub(k); // Vector to store the frequency of each remainder
        sub[0] = 1; // There's one way to have a sum that is exactly divisible by k initially (an empty subarray)
        
        // Iterate through each number in the array
        for(auto x: nums) {
            // Update the cumulative sum modulo k
            // The (pre + x % k + k) % k handles negative values correctly by ensuring the result is always non-negative
            pre = (pre + x % k + k) % k;
            // Increment the count by the number of times this remainder has been seen before
            ans += sub[pre];
            // Increment the frequency of this remainder
            sub[pre]++;
        }
        
        return ans; // Return the total count of subarrays whose sum is divisible by k
    }
};
