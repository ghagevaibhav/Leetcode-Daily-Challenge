class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size(); // Get the length of the input string
        int aCount = 0, bCount = 0; // Counters for 'a' and 'b'
        int lesser = min(x, y); // Determine the lesser value between x and y
        int result = 0; // Initialize the result variable to store the maximum gain

        // Traverse the input string
        for(int i = 0; i < n; i++){
            char c = s[i]; // Get the current character

            // If the current character is greater than 'b'
            if(c > 'b'){
                // Add the lesser value times the minimum count of 'a' or 'b' to the result
                result += min(aCount, bCount) * lesser;
                // Reset the counters for 'a' and 'b'
                aCount = 0, bCount = 0;
            }
            else if(c == 'a'){
                // If 'y' is greater than 'x' and there are 'b' characters available
                if(y > x && bCount > 0){
                    bCount--; // Decrement the 'b' counter
                    result += y; // Add 'y' to the result
                }
                else{
                    aCount++; // Increment the 'a' counter
                }
            }
            else{ // If the current character is 'b'
                // If 'x' is greater than 'y' and there are 'a' characters available
                if(x > y && aCount > 0){
                    aCount--; // Decrement the 'a' counter
                    result += x; // Add 'x' to the result
                }
                else{
                    bCount++; // Increment the 'b' counter
                }
            }
        }

        // Add the lesser value times the minimum count of 'a' or 'b' to the result
        result += min(aCount, bCount) * lesser;

        return result; // Return the final result
    }
};
