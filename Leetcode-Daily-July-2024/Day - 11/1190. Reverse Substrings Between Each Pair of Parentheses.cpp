class Solution {
public:
    // Index to keep track of the current position in the string
    int i = 0;

    // Main function to reverse the substrings inside each pair of parentheses
    string reverseParentheses(string s) {
        // Call the helper function to process the string
        return solve(s);
    }

    // Helper function to recursively solve the reversing of parentheses
    string solve(string &s) {
        // Initialize an empty result string
        string res = "";

        // Loop through the string until the end
        while (i < s.length()) {
            // If a closing parenthesis is found, reverse the current result string and return it
            if (s[i] == ')') {
                i++;
                reverse(res.begin(), res.end());
                return res;
            }
            // If an opening parenthesis is found, recursively solve for the substring inside the parentheses
            else if (s[i] == '(') {
                i++;
                string st = solve(s);
                res += st;
            }
            // If a regular character is found, add it to the result string
            else {
                res += s[i];
                i++;
            }
        }
        // Return the final result string
        return res;
    }
};
