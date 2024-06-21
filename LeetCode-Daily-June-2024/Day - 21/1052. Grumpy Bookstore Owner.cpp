class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int m) {
        int n = grumpy.size();    // Get the size of the grumpy array
        int l = 0;                // Left pointer for the sliding window
        int window = 0;           // Current window sum for grumpy customers
        int max_window = 0;       // Maximum window sum for grumpy customers
        int satisfied = 0;        // Base satisfied customers (when not grumpy)

        for(int i = 0; i < n; i++){
            if(grumpy[i] == 1){
                window += customers[i]; // Add to window if the owner is grumpy
            } else {
                satisfied += customers[i]; // Always satisfied customers
            }

            // Check if the current window size exceeds the allowed 'm' minutes
            if(i - l + 1 > m){
                // If the leftmost customer in the window was grumpy, subtract their value
                if(grumpy[l])
                    window -= customers[l];
                l += 1; // Move the left pointer to the right
            }

            // Update the maximum sum of customers that can be satisfied by using the technique
            max_window = max(max_window, window);
        }

        // Return the total maximum satisfied customers
        return satisfied + max_window;
    }
};
