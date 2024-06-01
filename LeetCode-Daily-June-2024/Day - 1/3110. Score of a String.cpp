class Solution {
public:
    // Function to calculate the score of a string based on the differences
    // between consecutive characters
    int scoreOfString(string s) {
        int ans = 0; // Initialize the score to 0
        int n = s.size(); // Get the length of the string
        
        // Iterate through the string, comparing each character to the next one
        for(int i = 0; i < n-1; i++){
            // Add the absolute difference between consecutive characters to the score
            ans += abs(s[i] - s[i+1]);
        }
        
        return ans; // Return the final score
    }
};
