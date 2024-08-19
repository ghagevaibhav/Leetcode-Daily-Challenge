class Solution {
public:
    // Function to calculate the minimum number of steps to get 'n' 'A's on the screen
    int minSteps(int n) {
        // If n is 1, no steps are needed since we start with 1 'A' on the screen
        if (n == 1) return 0;

        int steps = 0;   // To keep track of the total number of steps
        int factor = 2;  // Start checking from the smallest prime factor, which is 2

        // Loop until we reduce 'n' to 1
        while (n > 1) {
            // While 'factor' is a divisor of 'n', reduce 'n' by dividing it by 'factor'
            // and add the 'factor' to 'steps'
            while (n % factor == 0) {
                steps += factor; // Add the current factor to the step count
                n /= factor;     // Divide 'n' by the current factor
            }
            // Move to the next potential factor
            factor++;
        }

        // Return the total number of steps
        return steps;
    }
};
