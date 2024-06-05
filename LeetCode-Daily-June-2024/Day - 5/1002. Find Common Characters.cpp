class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // Initialize a vector to store the minimum frequency of each character
        // across all words. Set the initial value to the maximum possible integer.
        vector<int> min_freq(26, INT_MAX);

        // Iterate through each word in the input list.
        for (auto& word : words) {
            // Initialize a frequency vector for the current word.
            vector<int> freq(26, 0);

            // Count the frequency of each character in the current word.
            for (char c : word) {
                freq[c - 'a']++;
            }

            // Update the minimum frequency vector by comparing the current word's
            // character frequencies with the existing minimum frequencies.
            for (int i = 0; i < 26; ++i) {
                min_freq[i] = min(min_freq[i], freq[i]);
            }
        }

        // Initialize a result vector to store the common characters.
        vector<string> result;

        // Collect the common characters based on the minimum frequency vector.
        for (int i = 0; i < 26; ++i) {
            // Add the character to the result as many times as its minimum frequency.
            while (min_freq[i]-- > 0) {
                result.push_back(string(1, i + 'a'));
            }
        }

        // Return the result vector containing the common characters.
        return result;
    }
};
