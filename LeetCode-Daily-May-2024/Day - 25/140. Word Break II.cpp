class Solution {
public:
    // Main function that initiates the word break process
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Convert word dictionary to a set for fast lookup
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        // Start the helper function from the beginning of the string
        return wordBreakHelper(s, 0, dict);
    }

private:
    // Helper function to recursively find all valid substrings
    vector<string> wordBreakHelper(const string& s, int start, const unordered_set<string>& dict) {
        // Vector to store all valid substrings from the current start position
        vector<string> validSubstr;
        
        // Base case: if start has reached the end of the string, return an empty string as a valid decomposition
        if (start == s.length())
            validSubstr.push_back("");
        
        // Iterate over all possible end positions for the current substring
        for (int end = start + 1; end <= s.length(); ++end) {
            // Extract the current prefix from start to end
            string prefix = s.substr(start, end - start);
            
            // Check if the prefix is in the dictionary
            if (dict.find(prefix) != dict.end()) {
                // Recursively find valid substrings starting from the end of the current prefix
                vector<string> suffixes = wordBreakHelper(s, end, dict);
                
                // Concatenate the current prefix with each valid suffix and add to the result
                for (const string& suffix : suffixes) {
                    validSubstr.push_back(prefix + (suffix.empty() ? "" : " ") + suffix);
                }
            }
        }
        
        // Return all valid substrings found from the current start position
        return validSubstr;
    }
};
