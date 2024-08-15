class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // Sort the array to make it easier to calculate pair distances
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Initialize the binary search range
        int low = 0, high = nums[n - 1] - nums[0];

        // Define a lambda function to count pairs with distance <= max_distance
        auto count_pairs = [&](int max_distance) {
            int count = 0, j = 0;
            // Iterate over each element as the starting point of a pair
            for (int i = 0; i < n; ++i) {
                // Move j forward while the pair distance is within max_distance
                while (j < n && nums[j] - nums[i] <= max_distance) ++j;
                // The number of valid pairs with the current i is j - i - 1
                count += j - i - 1;
            }
            return count;
        };

        // Perform binary search on the possible distances
        while (low < high) {
            int mid = low + (high - low) / 2;
            // Check if there are fewer than k pairs with distance <= mid
            if (count_pairs(mid) < k) 
                low = mid + 1;  // Increase the lower bound
            else 
                high = mid;     // Otherwise, decrease the upper bound
        }

        // low will be the k-th smallest distance when binary search ends
        return low;
    }
};
