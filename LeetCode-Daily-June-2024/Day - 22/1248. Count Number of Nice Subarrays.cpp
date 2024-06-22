class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(); // Get the size of the input array
        vector<int> cnt(n + 1, 0); // Initialize a vector to count the number of times a certain count of odd numbers has been seen
        cnt[0] = 1; // There's one way to have zero odd numbers (by having no elements)
        int ans = 0, t = 0; // ans to store the number of valid subarrays, t to keep track of the current count of odd numbers
        for (int v : nums) { // Iterate over each element in the input array
            t += v & 1; // Increment t by 1 if the current element is odd (v & 1 checks the last bit to determine odd/even)
            if (t - k >= 0) { // Check if there are (t - k) counts of odd numbers previously seen
                ans += cnt[t - k]; // If so, add the count of those to ans, as they form valid subarrays
            }
            cnt[t]++; // Increment the count for the current number of odd numbers seen
        }
        return ans; // Return the total number of valid subarrays
    }
};
