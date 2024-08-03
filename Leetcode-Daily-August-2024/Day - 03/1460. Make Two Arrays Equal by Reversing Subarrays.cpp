class Solution {
public:
    // Function to check if two vectors can be made equal by sorting
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // Sort the 'arr' vector
        sort(arr.begin(), arr.end());
        
        // Sort the 'target' vector
        sort(target.begin(), target.end());
        
        // Iterate through each element in the vectors
        for (int i = 0; i < arr.size(); i++) {
            // Compare the elements of both vectors at index 'i'
            // If any element is not equal, return false
            if (arr[i] != target[i]) return false;
        }
        
        // If all elements are equal after sorting, return true
        return true;
    }
};
