class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // Use stringstream to split the sentence into individual words
        stringstream ss(sentence);
        string word;
        vector<string> strArr;
        
        // Extract words from the sentence and store them in a vector
        while (ss >> word) {
            strArr.push_back(word);
        }

        // Iterate through each word in the sentence
        for (int i = 0; i < strArr.size(); i++) {
            // Check each word in the dictionary
            for (int j = 0; j < dictionary.size(); j++) {
                // If the current word starts with the dictionary word, replace it
                if (strArr[i].substr(0, dictionary[j].size()) == dictionary[j]) {
                    strArr[i] = dictionary[j];
                }
            }
        }

        // Join the words back into a sentence
        string res;
        for (int i = 0; i < strArr.size(); i++) {
            if (i > 0) res += " "; // Add a space before each word except the first
            res += strArr[i]; // Add the word to the result string
        }

        // Return the modified sentence
        return res;
    }
};
