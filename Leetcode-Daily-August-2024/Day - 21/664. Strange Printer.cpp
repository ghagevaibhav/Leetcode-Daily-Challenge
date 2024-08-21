class Solution {
public:
    int strangePrinter(string s) {
        // A memoization map to store the minimum turns required for a substring
        unordered_map<string, int> memo;
        
        // Initiate the recursive function to calculate the minimum turns
        return min_turns_to_print(0, s.length() - 1, s, memo);        
    }

private:
    // Helper function to calculate the minimum turns needed to print the substring s[start...end]
    int min_turns_to_print(int start, int end, const string& s, unordered_map<string, int>& memo) {
        // Base case: if the start index exceeds the end index, no printing is needed
        if (start > end) {
            return 0;
        }
        
        // Generate a unique key for the current substring s[start...end] to check in memo
        string key = to_string(start) + "-" + to_string(end);
        
        // If the result for this substring is already computed, return it from memo
        if (memo.count(key)) {
            return memo[key];
        }
        
        // Assume the worst case: print all characters in the current substring independently
        int res = min_turns_to_print(start, end - 1, s, memo) + 1;

        // Try to find a better solution by checking all possible partitions
        for (int middle = start; middle < end; middle++) {
            // If the character at 'middle' matches the character at 'end',
            // consider the case where we print the substring [start...middle] first
            // and the remaining part [middle+1...end-1] later
            if (s[middle] == s[end]) {
                res = min(res, min_turns_to_print(start, middle, s, memo) + min_turns_to_print(middle + 1, end - 1, s, memo));
            }
        }
        
        // Store the computed result in memo for future use
        memo[key] = res;
        
        // Return the minimum number of turns required to print the current substring
        return res;
    }    
};
