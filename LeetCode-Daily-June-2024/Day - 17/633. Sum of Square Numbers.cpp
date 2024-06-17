class Solution {
public:
    bool judgeSquareSum(int c) {
        long long maxSquareRoot = sqrt(c);  // Maximum value of the square root of c
        long long left = 0, right = maxSquareRoot;
        
        // Two-pointer approach to check if there are two integers a and b such that a^2 + b^2 = c
        while (left <= right) {
            long long sumOfSquares = left * left + right * right;  // Sum of squares of the two pointers
            
            if (sumOfSquares == c) {
                return true;  // Found a pair of integers whose squares sum to c
            } else if (sumOfSquares > c) {
                right--;  // Decrease the right pointer to reduce the sum
            } else {
                left++;  // Increase the left pointer to increase the sum
            }
        }
        return false;  // No such pair found
    }
};
