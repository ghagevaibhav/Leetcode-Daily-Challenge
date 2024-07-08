class Solution {
public:
    // Recursive function to solve the problem
    void solve(int ind, int &ans, int k, vector<int> v) {
        // Base case: if only one person is left, they are the winner
        if(v.size() == 1) {
            ans = v[0]; // Store the winner in ans
            return;
        }
        // Update the index to the next person to be eliminated
        ind = (ind + k) % v.size();
        // Remove the person at the current index
        v.erase(v.begin() + ind);
        // Recur for the remaining people
        solve(ind, ans, k, v);
        return;
    }

    // Function to find the winner of the game
    int findTheWinner(int n, int k) {
        int ans = -1; // Initialize answer to an invalid value
        int ind = 0; // Start index
        k = k - 1; // Adjust k to be zero-based
        vector<int> v; // Vector to hold the people
        // Populate the vector with people numbered from 1 to n
        for(int i = 1; i <= n; i++) {
            v.push_back(i);
        }
        // Call the recursive solve function
        solve(ind, ans, k, v);
        return ans; // Return the winner
    }
};
