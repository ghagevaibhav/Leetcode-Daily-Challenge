class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(); // Get the size of the strings (both are of same size)
        int ans = -1, left = 0, window = 0; // Initialize answer, left pointer, and window sum

        // Traverse the string using the right pointer
        for(int right = 0; right < n; right++){
            // Add the cost of changing the current character in s to the corresponding character in t
            window += abs(s.at(right) - t.at(right));
            
            // If the current window cost exceeds maxCost, move the left pointer to reduce the window cost
            while(window > maxCost){
                window -= abs(s.at(left) - t.at(left)); // Remove the cost of the character at the left pointer
                left++; // Move the left pointer to the right
            }
            
            // Update the maximum length of the substring where the transformation cost is within the limit
            ans = max(ans, right - left + 1);
        }

        // Return the maximum length of the valid substring
        return ans;
    }
};
