class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Create a map to count occurrences of each element in arr1
        map<int, int> mp;
        for(auto x: arr1){
            mp[x]++;
        }
        
        // Create a vector to store the result
        vector<int> ans;
        
        // Process elements of arr2 to build the sorted part of the result
        for(int i = 0; i < arr2.size(); i++){
            int x = arr2[i];
            // Add element x from arr2 to the result as many times as it appears in arr1
            while(mp[x] > 0){
                ans.push_back(x);
                mp[x]--;
            }
        }
        
        // Create a vector to store the remaining elements that were not in arr2
        vector<int> remaining;
        for(auto& pair : mp) {
            // Add remaining elements to the 'remaining' vector as many times as they appear
            while(pair.second > 0) {
                remaining.push_back(pair.first);
                pair.second--;
            }
        }
        
        // Sort the remaining elements
        sort(remaining.begin(), remaining.end());
        
        // Append the sorted remaining elements to the result
        ans.insert(ans.end(), remaining.begin(), remaining.end());
        
        // Return the final sorted array
        return ans;
    }
};
