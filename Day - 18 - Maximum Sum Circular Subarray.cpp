class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int max_sum = INT_MIN;
        int min_sum = INT_MAX;
        int total = 0;

        int temp_max = 0;
        int temp_min = 0;

        for(int i = 0; i < n ; i++){
            total += nums[i];
            
            temp_max += nums[i];
            max_sum = max_sum < temp_max ? temp_max : max_sum;
            temp_max = temp_max < 0 ? 0 : temp_max;

            temp_min += nums[i];
            min_sum = min_sum > temp_min ? temp_min : min_sum;
            temp_min = temp_min > 0 ? 0 : temp_min;
        }

        if(total == min_sum)
            return max_sum;
        return max(max_sum,(total-min_sum));

    }
};
