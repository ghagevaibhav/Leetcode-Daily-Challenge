class Solution {
public:
    // Function to determine the minimum number of characters 
    // to append to string s to make t a subsequence of s
    int appendCharacters(string s, string t) {
        int n = s.size(); // Length of string s
        int m = t.size(); // Length of string t
        int i = 0; // Pointer for string s
        int j = 0; // Pointer for string t
        
        // Iterate through both strings
        while(i < n && j < m){
            // If characters at both pointers match, move pointer of t
            if(s[i] == t[j]){
                j++;
            }
            // Always move pointer of s
            i++;
        }
        
        // The number of characters to append is the remaining length of t
        return m - j;
    }
};
