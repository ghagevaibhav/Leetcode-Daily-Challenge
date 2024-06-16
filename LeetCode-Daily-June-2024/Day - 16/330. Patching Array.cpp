class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long missing = 1; // Initialize 'missing' to 1. This represents the smallest sum that we can't form yet.
        int patches = 0;  // Initialize the number of patches needed to 0.
        int i = 0;        // Initialize the index for traversing the nums array.
        
        // Continue looping until 'missing' exceeds 'n'
        while (missing <= n) {
            // If there are still elements in nums and the current element is <= 'missing'
            if (i < nums.size() && nums[i] <= missing) {
                // Add nums[i] to 'missing' (we can now form sums up to 'missing + nums[i]')
                missing += nums[i];
                i++; // Move to the next element in nums
            }
            else { // If the current element is greater than 'missing' or no more elements in nums
                // Double 'missing' (we add 'missing' itself as a patch)
                missing += missing;
                patches++; // Increment the number of patches needed
            }
        }
        
        // Return the total number of patches needed
        return patches;
    }
};
