class Solution
{
public:
    // Helper function to determine if we can place 'm' balls with at least 'gap' distance apart
    bool canPlaceBalls(int gap, vector<int> &positions, int m)
    {
        int lastPosition = positions[0];  // Place the first ball at the first position
        int ballsRemaining = m - 1;       // We need to place the remaining m-1 balls
        
        // Iterate through the positions starting from the second position
        for (int i = 1; i < positions.size() && ballsRemaining > 0; i++)
        {
            // If the current position is at least 'gap' distance away from the last placed ball
            if (positions[i] - lastPosition >= gap)
            {
                ballsRemaining--;            // Place a ball here
                lastPosition = positions[i]; // Update the last position to the current one
            }
        }
        // If we have placed all m balls, return true; otherwise, return false
        return ballsRemaining == 0;
    }

    // Main function to find the maximum minimum distance to place 'm' balls
    int maxDistance(vector<int> &positions, int m)
    {
        ios_base::sync_with_stdio(0); // Improve input/output efficiency (optional, useful for competitive programming)
        sort(positions.begin(), positions.end()); // Sort the positions array to use binary search
        
        int n = positions.size();
        int left = 1;                                // Minimum possible distance
        int right = positions[n - 1] - positions[0]; // Maximum possible distance
        int maxMinDistance = -1; // Variable to store the maximum of the minimum distances
        
        // Perform binary search on the distance
        while (left <= right)
        {
            int mid = (left + right) / 2; // Find the middle distance
            // Check if it's possible to place the balls with at least 'mid' distance apart
            if (canPlaceBalls(mid, positions, m))
            {
                maxMinDistance = mid; // Update the result
                left = mid + 1;       // Try for a larger minimum distance
            }
            else
                right = mid - 1; // Try for a smaller minimum distance
        }
        return maxMinDistance; // Return the maximum of the minimum distances
    }
};
