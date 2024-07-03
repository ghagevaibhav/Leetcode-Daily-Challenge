class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input vector
        int ans = 0; // Initialize the answer to 0
        
        // If the size of the array is 4 or less, the minimum difference can be 0
        if(n <= 4) return 0;
        
        // Sort the array to bring similar elements together
        sort(nums.begin(), nums.end());
        
        // Calculate the minimum difference by considering removing the smallest and largest elements
        // The four possible scenarios are:
        // 1. Remove the three smallest elements
        // 2. Remove the two smallest and one largest element
        // 3. Remove one smallest and two largest elements
        // 4. Remove the three largest elements
        ans = min({
            nums[n-1] - nums[3],  // Case 1: Remove the three smallest elements
            nums[n-2] - nums[2],  // Case 2: Remove the two smallest and one largest element
            nums[n-3] - nums[1],  // Case 3: Remove one smallest and two largest elements
            nums[n-4] - nums[0],  // Case 4: Remove the three largest elements
        });
        
        return ans; // Return the minimum difference
    }
};
