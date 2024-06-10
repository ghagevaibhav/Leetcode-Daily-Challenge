class Solution {
public:

    // Helper function to check if there exists a group of 'size' consecutive numbers
    // starting from index 'i' in the hand vector
    bool check(vector<int> &hand, int i, int size){
        int x = hand[i]; // Get the current value at index 'i'
        int n = hand.size(); // Get the size of the hand vector
        hand[i] = -1; // Mark the current value as visited (-1)
        int cnt = 1; // Initialize a counter for consecutive numbers
        i++; // Move to the next index
        // Iterate until we have found 'size' consecutive numbers or reached the end of the vector
        while(cnt < size && i < n){
            // If the next number is consecutive to the current one
            if(hand[i] == (x + 1)){
                cnt++; // Increment the counter
                x++; // Update the value to be checked
                hand[i] = -1; // Mark the current value as visited (-1)
            }
            i++; // Move to the next index
        }
        // If we found a group of 'size' consecutive numbers, return true
        if(cnt == size){
            return true;
        }
        return false; // Otherwise, return false
    }

    // Main function to check if it's possible to arrange hand in groups of 'groupSize'
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size(); // Get the size of the hand vector
        // If the number of cards is not divisible by groupSize, it's impossible to arrange them
        if(n % groupSize != 0){
            return false; // Return false
        }

        sort(hand.begin(), hand.end()); // Sort the hand vector

        // Iterate through the hand vector
        for(int i = 0; i < n; i++){
            // If the current card has not been visited yet
            if(hand[i] != -1){
                // Check if there exists a group of 'groupSize' consecutive numbers starting from index 'i'
                if(check(hand, i, groupSize) == false){
                    return false; // If not, return false
                }
            }
        }
        return true; // If all groups of 'groupSize' consecutive numbers are found, return true
    }
};
