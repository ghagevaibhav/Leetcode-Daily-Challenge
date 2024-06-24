class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) 
    {
        int n = nums.size(); // Get the size of the input vector
        int flipped = 0, res = 0; // 'flipped' keeps track of the current flip state, 'res' counts the total number of flips
        vector<int> isFlipped(n, 0); // Create a vector to keep track of the flip operations

        for(int i = 0; i < n; i++){
            if(i >= k){
                // Adjust the flip state by removing the effect of flips that are out of the current window
                flipped ^= isFlipped[i-k];
            }
            if(flipped == nums[i]){
                // If the current bit needs to be flipped to make it 1
                if(i + k > n){
                    // If there's not enough bits left to flip k bits, return -1
                    return -1;
                }
                isFlipped[i] = 1; // Mark this position as flipped
                flipped ^= 1; // Toggle the flip state
                res++; // Increment the flip count
            }
        }
        return res; // Return the total number of flips required
    }
};
