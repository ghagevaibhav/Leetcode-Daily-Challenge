class Solution {
public:
    // This function returns the number of students standing in the wrong positions
    int heightChecker(vector<int>& heights) {
        // Get the number of students
        int n = heights.size();
        
        // Create a copy of the original heights vector
        vector<int> copyOfHeights = heights;
        
        // Sort the original heights vector
        sort(heights.begin(), heights.end());
        
        // Initialize a counter to count the number of mismatches
        int cnt = 0;
        
        // Iterate over the heights and compare the sorted heights with the original heights
        for(int i = 0; i < n; i++) {
            // If the heights do not match, increment the counter
            if(copyOfHeights[i] != heights[i]) {
                cnt++;
            }
        }
        
        // Return the count of mismatches
        return cnt;
    }
};
