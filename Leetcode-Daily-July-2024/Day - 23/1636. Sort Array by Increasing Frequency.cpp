class Solution {
public:
    // Function to sort elements by frequency and value
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input vector
        map<int, int> freq; // Create a map to store the frequency of each element
        
        // Count the frequency of each element in the input vector
        for(auto x: nums){
            freq[x]++;
        }
        
        // Sort the vector based on the custom comparator
        sort(nums.begin(), nums.end(), [&freq](int a, int b){
            if(freq[a] == freq[b]){
                return a > b; // If frequencies are the same, sort by value in descending order
            }
            return freq[a] < freq[b]; // Otherwise, sort by frequency in ascending order
        });
        
        return nums; // Return the sorted vector
    }
};
