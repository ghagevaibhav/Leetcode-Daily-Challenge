class Solution {
public:
    // Main function to partition the input string into all possible palindrome partitioning
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;  // Resultant list of all possible palindrome partitions
        vector<string> path;         // Current path (particular partitioning) being explored
        solver(0, ans, path, s);     // Start the solver function from the 0th index
        return ans;                  // Return the list of all palindrome partitions
    }

    // Helper function to recursively find all palindrome partitions
    void solver(int ind, vector<vector<string>>& ans, vector<string>& path, string s){
        int n = s.size();
        // If the current index has reached the end of the string, add the current path to the answer
        if(ind == n){
            ans.push_back(path);
            return;
        }
        // Iterate through the string and partition it at every possible point
        for(int i = ind; i < n; i++){
            // If the substring from ind to i is a palindrome, proceed
            if(isPalindrome(s, ind, i)){
                // Add the palindrome substring to the current path
                path.push_back(s.substr(ind, i - ind + 1));
                // Recur for the remaining substring
                solver(i+1, ans, path, s);
                // Backtrack and remove the last added palindrome substring
                path.pop_back();
            }
        }
    }

    // Utility function to check if a substring is a palindrome
    bool isPalindrome(string s, int start, int end){
        // Check characters from both ends towards the center
        while(start < end){
            if(s[start] != s[end]){
                return false;  // Not a palindrome if characters don't match
            }
            start++;
            end--;
        }
        return true;  // It's a palindrome if all characters match
    }
};
