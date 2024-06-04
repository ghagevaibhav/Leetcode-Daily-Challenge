class Solution {
public:
    int longestPalindrome(string s) {
        int strLength = s.size(); // Total length of the input string
        int oddCount = 0;         // Count of characters with an odd frequency
        map<char, int> charFrequency; // Map to store frequency of each character
        
        // Count the frequency of each character
        for(char c : s){
            charFrequency[c]++;
            // If the frequency is odd, increment oddCount, otherwise decrement it
            if(charFrequency[c] % 2 == 1){
                oddCount++;
            } else {
                oddCount--;
            }
        }
        
        // If more than one character has an odd frequency, adjust the palindrome length
        if(oddCount > 1){
            return strLength - oddCount + 1;
        }
        
        // If at most one character has an odd frequency, the whole string can be rearranged as a palindrome
        return strLength;
    }
};
