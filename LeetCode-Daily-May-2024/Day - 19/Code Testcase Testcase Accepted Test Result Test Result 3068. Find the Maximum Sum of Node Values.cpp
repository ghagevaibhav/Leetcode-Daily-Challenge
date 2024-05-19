class Solution {
public:
    // This function calculates the maximum value sum after performing a bitwise XOR operation with k on each element of nums
    // and adjusting the sum based on the net changes.
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long totalSum = 0;  // Initialize the total sum of the array elements
        int count = 0;  // Counter for the number of positive net changes
        int positiveMin = INT_MAX;  // Minimum positive net change
        int negativeMax = INT_MIN;  // Maximum negative net change

        // Iterate through each node value in nums
        for (int nodeValue : nums) {
            int nodeValAfterOperation = nodeValue ^ k;  // Calculate the value after XOR operation with k
            totalSum += nodeValue;  // Add the original node value to the total sum
            int netChange = nodeValAfterOperation - nodeValue;  // Calculate the net change after the XOR operation

            // If the net change is positive, update the total sum and count the number of positive changes
            if (netChange > 0) {
                positiveMin = min(positiveMin, netChange);  // Track the minimum positive net change
                totalSum += netChange;  // Add the net change to the total sum
                count += 1;  // Increment the count of positive changes
            } else {
                negativeMax = max(negativeMax, netChange);  // Track the maximum negative net change
            }
        }

        // If the number of positive changes is even, return the total sum as is
        if (count % 2 == 0) {
            return totalSum;
        }
        // If the number of positive changes is odd, adjust the total sum by considering either removing the smallest positive change
        // or adding the largest negative change, whichever gives a higher sum
        return max(totalSum - positiveMin, totalSum + negativeMax);
    }
};
