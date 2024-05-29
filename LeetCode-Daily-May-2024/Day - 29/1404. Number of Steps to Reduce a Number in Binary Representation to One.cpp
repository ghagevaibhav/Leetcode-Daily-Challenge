class Solution {
public:
    int numSteps(string s) {
        // n stores the size of the input binary string s
        long n = s.size();
        
        // carry variable to keep track of the carry during addition
        int carry = 0;
        
        // ans stores the number of steps required, initially set to n-1
        // as we need at least n-1 steps to process the entire string
        int ans = n - 1;
        
        // Loop through the string from the second last character to the first
        for(int i = n - 1; i > 0; i--){
            // Check if the current bit plus carry is 1
            if(s[i] - '0' + carry == 1){
                // Increment steps count as we need an extra step to make the number even
                ans++;
                // Set carry to 1 for the next iteration
                carry = 1;
            }
        }
        
        // Return the total number of steps plus any remaining carry
        return ans + carry;
    }
};
