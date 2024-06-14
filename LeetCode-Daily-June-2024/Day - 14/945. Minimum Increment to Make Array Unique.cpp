class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size();

        // Find the maximum value in the input array
        int maxi = *max_element(nums.begin(), nums.end());

        // Create a frequency array to count occurrences of each number
        // The size is maxi + n + 1 to ensure enough space for potential increments
        vector<int> freq(maxi + n + 1, 0);

        // Count the frequency of each number in the input array
        for(auto el: nums){
            freq[el]++;
        }

        // Initialize the variable to store the number of increments needed
        int ans = 0;

        // Traverse the frequency array to ensure all elements are unique
        for(int i = 0; i < freq.size(); i++){
            // If the current number occurs once or not at all, continue
            if(freq[i] <= 1) continue;

            // Calculate the number of extra occurrences of the current number
            int extra = freq[i] - 1;

            // Move the extra occurrences to the next number
            freq[i+1] += extra;

            // Add the number of extra occurrences to the answer
            // Each extra occurrence represents an increment operation needed
            ans += extra;
        }

        // Return the total number of increments needed to make all elements unique
        return ans;
    }
};
