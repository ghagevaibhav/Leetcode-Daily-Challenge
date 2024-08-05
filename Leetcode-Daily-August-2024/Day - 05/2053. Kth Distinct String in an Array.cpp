class Solution {
public:
    // Function to find the k-th distinct string in the array
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> counter;  // Map to count occurrences of each string
        
        // First pass: Count the occurrences of each string
        for (auto& v : arr) ++counter[v];
        
        // Second pass: Find the k-th distinct string
        for (auto& v : arr) {
            if (counter[v] == 1) {  // Check if the string is distinct
                --k;  // Decrement k for each distinct string found
                if (k == 0) return v;  // If k becomes 0, return the current string
            }
        }
        
        return "";  // If no k-th distinct string is found, return an empty string
    }
};
