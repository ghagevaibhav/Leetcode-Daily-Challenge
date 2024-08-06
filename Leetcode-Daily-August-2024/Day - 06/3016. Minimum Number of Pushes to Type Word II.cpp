class Solution {
public:
    // This function calculates the minimum number of key presses needed
    // to type out the given word on a 3x8 grid keyboard.
    int minimumPushes(string word) {
        // Create a frequency array to count occurrences of each letter in the word.
        vector<int> letterFreq(26, 0);
        
        // Iterate over each character in the word.
        for (char c : word) {
            // Increment the frequency of the corresponding letter.
            letterFreq[c - 'a']++;
        }
        
        // Sort the frequencies in descending order.
        // This helps in allocating the most frequent letters to positions
        // with the least key presses required.
        sort(letterFreq.rbegin(), letterFreq.rend());
        
        int totalPresses = 0;
        // Calculate the total number of key presses needed.
        // Iterate over the frequency array.
        for (int i = 0; i < 26; i++) {
            // If the frequency is zero, we can break out of the loop
            // as there are no more letters to process.
            if (letterFreq[i] == 0) break;
            
            // Calculate the number of key presses for each letter.
            // i / 8 + 1 gives the number of presses based on the row in the grid.
            // letterFreq[i] gives the number of times the letter appears.
            totalPresses += (i / 8 + 1) * letterFreq[i];
        }
        
        // Return the total number of key presses needed.
        return totalPresses;
    }
};
