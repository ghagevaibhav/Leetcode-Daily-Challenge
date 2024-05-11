class Solution {
public:
    // Function to find the maximum absolute value that satisfies the given condition
    int findMaxK(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array
        sort(nums.begin(), nums.end()); // Sort the array in non-decreasing order
        
        int l = 0, r = n - 1; // Initialize two pointers for the two ends of the array
        
        // Iterate until the two pointers meet
        while (l < r) {
            // If the absolute values of the elements at the two pointers are equal (one is the negative of the other)
            if (nums[l] == (-1 * (nums[r]))) {
                return nums[r]; // Return the absolute value of the element at the right pointer
            }
            // If the absolute value of the element at the left pointer is less than the element at the right pointer
            else if ((-1 * nums[l]) < nums[r]) {
                r--; // Move the right pointer to the left
            }
            // If the absolute value of the element at the left pointer is greater than the element at the right pointer
            else {
                l++; // Move the left pointer to the right
            }
        }
        return -1; // Return -1 if no such element is found
    }
};
