class Solution {
public:
    // Function to reverse the prefix of the word until the character ch
    string reversePrefix(string word, char ch) {
        int i = word.find(ch); // Find the index of the character ch in the word
        
        // If the character ch is found in the word
        if (i != -1)
            reverse(word.begin(), word.begin() + i + 1); // Reverse the prefix of the word until the character ch
        
        return word; // Return the modified word
    }
};
