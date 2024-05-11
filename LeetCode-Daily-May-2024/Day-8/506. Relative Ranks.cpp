#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size(); // Get size of score vector
        vector<string> rankings(n); // Vector to store rankings
        vector<string> rankName = {"Gold Medal", "Silver Medal", "Bronze Medal"}; // Top three ranks
        int maxScore = *max_element(score.begin(), score.end()); // Find max score
        vector<int> scoreToIndex(maxScore + 1, -1); // Map score to index
        
        // Store index of each score
        for(int i = 0; i < n; i++) scoreToIndex[score[i]] = i; 
        
        unordered_map<int, int> rank; // Map score to rank
        int rankct = 1;
        
        // Assign ranks
        for(int i = maxScore; i >= 0; i--) { 
            if(scoreToIndex[i] == -1) continue;
            rank[i] = rankct++;
        }
        
        // Assign medals or rank number
        for(int i = 0; i < n; i++) { 
            int actualRank = rank[score[i]];
            if (actualRank <= 3) rankings[i] = rankName[actualRank - 1];
            else rankings[i] = to_string(actualRank);
        }
        
        return rankings; // Return rankings
    }
};
