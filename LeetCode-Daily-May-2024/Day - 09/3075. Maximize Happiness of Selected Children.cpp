#include <vector>
#include <algorithm>

class Solution {
public:
    long long maximumHappinessSum(std::vector<int>& happiness, int k) {
        // Get the size of the happiness array
        long long n = happiness.size();
        // Initialize the sum of happiness
        long long sumOfHappiness = 0;
        // Sort the happiness array in non-ascending order
        sort(happiness.begin(), happiness.end(), greater<int>());
        // Initialize index variable
        int i = 0;
        // Perform k iterations
        while(k--){
            // Decrease happiness of the ith element by i if possible
            happiness[i] = max(happiness[i] - i, 0);
            
            // Add current happiness to the sum
            sumOfHappiness += happiness[i++];
        }
        // Return the sum of happiness
        return sumOfHappiness;
    }
};
