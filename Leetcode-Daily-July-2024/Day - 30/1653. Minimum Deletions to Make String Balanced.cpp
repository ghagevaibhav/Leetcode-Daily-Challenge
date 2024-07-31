class Solution {
public:
    // Function to find the minimum number of deletions to make the string balanced
    int minimumDeletions(string s) {
        int n = s.length(); // Get the length of the string
        int ans = 0; // Initialize the answer to 0
        int count_b = 0; // Initialize the count of 'b' characters to 0
        
        // Iterate through each character in the string
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                // If the character is 'b', increment the count_b
                count_b++;
            } else {
                // If the character is 'a', calculate the minimum deletions needed
                // Either increment ans by 1 (delete this 'a')
                // Or keep the current count of 'b' (delete all 'b's seen so far)
                ans = min(ans + 1, count_b);
            }
        }
        // Return the minimum number of deletions required
        return ans;
    }
};
