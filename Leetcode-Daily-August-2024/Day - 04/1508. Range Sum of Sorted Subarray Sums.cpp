class Solution {
private:
    // Define a constant for the modulus value to be used in calculations
    static const int MODULUS = 1000000007;
    long long maxSubarraySum = 0;
    long long minSubarraySum = 0;

    // Helper function to count subarrays with sum less than or equal to the threshold
    std::pair<int, long long> countAndSumSubarrays(const std::vector<int>& array, long long threshold) {
        int count = 0;  // To store the count of subarrays
        long long totalSum = 0, currentWindowSum = 0, runningSum = 0;
        int size = array.size();

        // Sliding window approach
        for (int start = 0, end = 0; end < size; ++end) {
            // Update the running sum and the sum of the current window
            runningSum += static_cast<long long>(array[end]) * (end - start + 1);
            currentWindowSum += array[end];
            // Adjust the window size if the current window sum exceeds the threshold
            while (currentWindowSum > threshold) {
                runningSum -= currentWindowSum;
                currentWindowSum -= array[start++];
            }
            // Update the count of subarrays and the total sum of valid subarrays
            count += end - start + 1;
            totalSum += runningSum;
        }
        // Return the count of subarrays and their total sum
        return {count, totalSum};
    }

    // Helper function to calculate the sum of the first k subarrays
    long long calculateSumOfFirstKSubarrays(const std::vector<int>& array, int k) {
        long long low = minSubarraySum, high = maxSubarraySum;
        // Binary search to find the threshold such that there are at least k subarrays
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (countAndSumSubarrays(array, mid).first < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        auto [count, sum] = countAndSumSubarrays(array, low);
        // Adjust the sum to include only the first k subarrays
        return sum - low * (count - k);
    }

public:
    // Main function to calculate the sum of subarray sums from the left-th to the right-th
    int rangeSum(std::vector<int>& nums, int n, int left, int right) {
        // Determine the minimum and maximum possible subarray sums
        minSubarraySum = *std::min_element(nums.begin(), nums.end());
        maxSubarraySum = std::accumulate(nums.begin(), nums.end(), 0LL);

        // Calculate the sum for the range and apply the modulus operation
        long long result = (calculateSumOfFirstKSubarrays(nums, right) % MODULUS - 
                            calculateSumOfFirstKSubarrays(nums, left - 1) % MODULUS + 
                            MODULUS) % MODULUS;
        // Return the final result as an integer
        return static_cast<int>(result);
    }
};
