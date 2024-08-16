class Solution {
public:
    // Function to find the maximum distance between elements in different arrays.
    int maxDistance(vector<vector<int>>& arrays) {
        // If there are less than 2 arrays, the maximum distance is 0.
        if (arrays.size() < 2) return 0;

        // Initialize global minimum and maximum with the first array's elements.
        int globalMin = arrays[0][0];
        int globalMax = arrays[0].back();
        int result = 0; // Initialize the result to store the maximum distance.

        // Loop through the arrays starting from the second one.
        for (int i = 1; i < arrays.size(); ++i) {

            // Extract the current array's minimum and maximum values.
            int localMin = arrays[i][0];
            int localMax = arrays[i].back();

            // Update the result with the maximum distance found so far.
            // This considers the distance between the current array's max and global min, 
            // and the distance between the current array's min and global max.
            result = max(result, max(localMax - globalMin, globalMax - localMin));

            // Update the global minimum and maximum for subsequent arrays.
            globalMin = min(globalMin, localMin);
            globalMax = max(globalMax, localMax);
        }

        // Return the maximum distance found.
        return result;
    }
};

// Speed up I/O operations to make the program run faster by syncing input/output streams.
static const int speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
