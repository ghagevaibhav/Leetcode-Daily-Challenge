class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Edge case: if there are exactly two numbers, return them
        int n = nums.size();
        if(n == 2) return nums;

        // Step 1: XOR all the numbers to get the XOR of the two unique numbers
        long long xorr = 0;
        for(const auto &x: nums){
            xorr ^= x;
        }

        // Step 2: Find the rightmost set bit in the XOR result
        // This bit will be different between the two unique numbers
        int rightmost = (xorr & (xorr - 1)) ^ xorr;

        // Step 3: Initialize two variables to hold the two unique numbers
        int b1 = 0, b2 = 0;

        // Step 4: Partition the numbers into two groups and XOR separately
        for(int i = 0; i < n ; i++){
            if(rightmost & nums[i]){
                // Group 1: Numbers where the bit is set
                b1 ^= nums[i];
            } else {
                // Group 2: Numbers where the bit is not set
                b2 ^= nums[i];
            }
        }

        // Step 5: Return the two unique numbers
        return {b1, b2};
    }
};
