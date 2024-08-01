#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    // Function to calculate the minimum height of shelves to place all books
    int minHeightShelves(std::vector<std::vector<int>>& books, int shelfWidth) {
        int n = books.size();  // Number of books
        std::vector<int> dp(n + 1, INT_MAX);  // DP array to store minimum height of shelves
        dp[0] = 0;  // Base case: no books, no height
        
        // Loop through each book
        for (int i = 1; i <= n; ++i) {
            int total_width = 0;  // Track the total width of books on the current shelf
            int max_height = 0;  // Track the maximum height of books on the current shelf
            
            // Place books on the current shelf one by one, starting from book i going backward
            for (int j = i; j > 0; --j) {
                total_width += books[j-1][0];  // Add the width of the j-th book
                
                // If the total width exceeds the shelf width, we cannot place more books on this shelf
                if (total_width > shelfWidth) {
                    break;
                }
                
                // Update the maximum height of the current shelf
                max_height = std::max(max_height, books[j-1][1]);
                
                // Update dp[i] to the minimum height by either keeping previous value or placing books j to i on the current shelf
                dp[i] = std::min(dp[i], dp[j-1] + max_height);
            }
        }
        
        return dp[n];  // Return the minimum height to place all books
    }
};
