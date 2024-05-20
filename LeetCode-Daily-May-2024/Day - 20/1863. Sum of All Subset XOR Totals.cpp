class Solution {
public: 
    // This function computes the sum of XORs of all subsets of the given vector 'nums'
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input vector
        int ans = 0; // Initialize the answer to 0

        // Iterate over all possible subsets using a bitmask from 0 to (2^n - 1)
        for(int mask = 0; mask < (1 << n); mask++){
            int xorsub = 0; // Initialize the XOR of the current subset to 0

            // Iterate over each element in the vector to check if it is included in the current subset
            for(int i = 0; i < n; i++){
                // Check if the i-th element is included in the current subset (mask)
                if(mask & (1 << i))
                    xorsub ^= nums[i]; // If included, XOR it with the current subset's XOR value
            }

            // Add the XOR value of the current subset to the total answer
            ans += xorsub;
        }

        // Return the total sum of XORs of all subsets
        return ans;
    }
};
