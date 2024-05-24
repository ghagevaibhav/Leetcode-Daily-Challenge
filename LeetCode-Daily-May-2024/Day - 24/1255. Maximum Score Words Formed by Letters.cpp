class Solution {
public:
    // Function to find the maximum score of words that can be formed
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        // Count of each letter available from 'letters'
        vector<int> count(26, 0); 
        // Temporary count of letters used so far in forming words
        vector<int> lettersCount(26, 0);
        
        // Populate the count array with the frequency of each letter in 'letters'
        for(auto &c : letters){
            count[c - 'a']++;
        }

        // Variable to store the maximum score
        int ans = 0;
        // Start the backtracking process
        backtracking(words, score, count, lettersCount, 0, 0, ans);
        return ans;
    }

    // Helper function for backtracking
    void backtracking(vector<string>& words, vector<int>& score, vector<int>& count, vector<int>& lettersCount, int pos, int temp, int &ans){
        // Check if the current combination of letters exceeds the available counts
        for(int i = 0; i < 26; i++){
            if(lettersCount[i] > count[i]) return;
        }

        // Update the maximum score found so far
        ans = max(ans, temp);

        // Iterate through the remaining words starting from 'pos'
        for(int i = pos; i < words.size(); i++){
            // Add the current word's letters to lettersCount and update the score
            for(auto& c : words[i]){
                lettersCount[c - 'a']++;
                temp += score[c - 'a'];
            }

            // Recursively call backtracking for the next word
            backtracking(words, score, count, lettersCount, i + 1, temp, ans);

            // Backtrack: remove the current word's letters from lettersCount and update the score
            for(auto& c : words[i]){
                lettersCount[c - 'a']--;
                temp -= score[c - 'a'];
            }
        }
    }
};
