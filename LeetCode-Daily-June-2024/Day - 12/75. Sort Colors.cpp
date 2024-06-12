class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array
        int start = 0, mid = 0, end = n - 1; // Initialize pointers

        // Iterate until mid pointer crosses end pointer
        while(mid <= end) {
            if(nums[mid] == 0) {
                // If the current element is 0, swap it with the element at the start pointer
                swap(nums[mid], nums[start]);
                // Move both start and mid pointers to the right
                start++;
                mid++;
            } 
            else if(nums[mid] == 1) {
                // If the current element is 1, just move the mid pointer to the right
                mid++;
            } 
            else {
                // If the current element is 2, swap it with the element at the end pointer
                swap(nums[mid], nums[end]);
                // Move the end pointer to the left
                end--;
            }
        }
        return; // Function doesn't need to return anything as it modifies the input array in place
    }
};
