class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(); // Get the size of the input array
        int i = 0, j = 0; // Initialize two pointers for the sliding window
        int ans = 0; // Variable to store the length of the longest subarray
        deque<int> minq; // Deque to store indices of elements in non-decreasing order
        deque<int> maxq; // Deque to store indices of elements in non-increasing order

        // Traverse the array with the right pointer `j`
        while (j < n) {
            int x = nums[j]; // Current element
            
            // Maintain the min deque: remove elements from the back that are greater than the current element
            while (!minq.empty() && nums[minq.back()] >= x) 
                minq.pop_back();
            minq.push_back(j); // Add current element index to the min deque
            
            // Maintain the max deque: remove elements from the back that are less than the current element
            while (!maxq.empty() && nums[maxq.back()] <= x) 
                maxq.pop_back();
            maxq.push_back(j); // Add current element index to the max deque

            // Get the minimum and maximum values in the current window
            int mini = nums[minq.front()];
            int maxi = nums[maxq.front()];

            // Check if the current window is valid based on the given limit
            if (maxi - mini > limit) {
                // If not valid, move the left pointer `i` to reduce the window size
                i++;
                // Remove the indices from the deques that are out of the window's range
                if (i > minq.front()) 
                    minq.pop_front();
                if (i > maxq.front()) 
                    maxq.pop_front();
            } else {
                // If valid, update the maximum length of the subarray found so far
                ans = max(ans, j - i + 1);
                j++; // Move the right pointer to expand the window
            }
        }
        return ans; // Return the length of the longest valid subarray
    }
};
