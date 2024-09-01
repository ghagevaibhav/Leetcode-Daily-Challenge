class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Initialize a 2D vector 'result' with 'm' rows
        vector<vector<int>> result(m);
        int i;

        // Check if the total number of elements in the 2D array (m * n)
        // matches the size of the original 1D array
        switch (m * n == original.size() ? 1 : 0) {
            case 1:
                i = 0;
                // Fill the 2D vector by slicing the original 1D vector into rows of size 'n'
                while (i < m) {
                    result[i] = vector<int>(original.begin() + i * n, original.begin() + (i * n + n));
                    i++;
                }
                break;
            default:
                // If the size doesn't match, return an empty 2D vector
                return {};
        }
        // Return the constructed 2D array
        return result;
    }
};

// Static initialization block to optimize I/O operations for competitive programming
static const auto kds = []() {
    std::ios::sync_with_stdio(false); // Disable synchronization between C++ and C I/O streams
    std::cin.tie(nullptr);            // Untie cin from cout to speed up I/O operations
    std::cout.tie(nullptr);           // Untie cout from cin to speed up I/O operations
    return 0;
}();
