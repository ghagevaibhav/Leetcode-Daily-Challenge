class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // Calculate the total number of 1's in the input array
        int total = accumulate(nums.begin(), nums.end(), 0);

        // Get the size of the input array
        int n = nums.size();

        // Calculate the initial count of 1's in the first 'total' elements
        int cnt = accumulate(nums.begin(), nums.begin() + total, 0);  

        // Initialize maxi with the initial count
        int maxi = cnt;

        // Iterate through the array with a sliding window of size 'total'
        for(int i = total; i < n + total; i++){
            // Adjust the count by adding the next element and removing the element that slides out of the window
            cnt += nums[i % n] - nums[(i - total + n) % n];
            // Update maxi to the maximum count found so far
            maxi = max(maxi, cnt);
        }

        // The minimum number of swaps required is the difference between the total 1's and the maximum count of 1's in any window of size 'total'
        return total - maxi;
    }
};
