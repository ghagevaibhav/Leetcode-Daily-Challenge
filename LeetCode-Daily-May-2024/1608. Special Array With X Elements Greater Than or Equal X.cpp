class Solution {
public:
    // Function to find the special value x in the array nums
    int specialArray(vector<int>& nums) {
        int n = nums.size();  // Get the size of the array
        int maxi = *max_element(nums.begin(), nums.end());  // Find the maximum element in the array
        int x = 0;  // Initialize x to 0
        
        // Loop through values of x from 0 to the maximum element in the array
        while(x <= maxi) {
            int cnt = 0;  // Counter to count how many elements are greater than or equal to x
            
            // Iterate through the array
            for(int i = 0; i < n; i++) {
                if(nums[i] >= x) {  // Check if the current element is greater than or equal to x
                    cnt++;  // Increment the counter if the condition is true
                }
            }
            
            // Check if the count of elements greater than or equal to x is exactly x
            if(cnt == x) {
                return x;  // If true, return x as the special value
            }
            else {
                x++;  // Otherwise, increment x and continue the loop
            }
        }
        
        return -1;  // If no such x is found, return -1
    }
};
