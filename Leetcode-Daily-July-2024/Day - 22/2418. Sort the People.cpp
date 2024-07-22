class Solution {
public:
    // Function to sort people by their heights in descending order
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans; // Vector to store the sorted names
        vector<pair<int, string>> v; // Vector to store height-name pairs
        
        // Loop through each name and corresponding height
        for (int i = 0; i < names.size(); i++) {
            // Push the height and name as a pair into the vector 'v'
            v.push_back({heights[i], names[i]});
        }
        
        // Sort the vector 'v' in descending order based on heights
        sort(v.rbegin(), v.rend());
        
        // Loop through the sorted vector 'v'
        for (auto & x : v) {
            // Extract the name from each pair and push it into the 'ans' vector
            ans.push_back(x.second);
        }
        
        // Return the vector containing names sorted by their heights
        return ans;
    }
};
