class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        // Define the directions for moving in the matrix: East, South, West, North.
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
        // Initialize the result with the starting position.
        vector<vector<int>> result = {{rStart, cStart}};
        // Initialize the number of steps to take in the current direction and the direction index.
        int steps = 0, d = 0;

        // Continue until all positions in the matrix are filled.
        while (result.size() < rows * cols) {
            // Increase the number of steps every two direction changes (East and West).
            if (d == 0 || d == 2) steps++;
            
            // Move in the current direction for the specified number of steps.
            for (int i = 0; i < steps; i++) {
                // Update the current position based on the direction.
                rStart += directions[d][0];
                cStart += directions[d][1];
                
                // Check if the current position is within the bounds of the matrix.
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    // Add the current position to the result.
                    result.push_back({rStart, cStart});
                }
                
                // If all positions in the matrix are filled, return the result.
                if (result.size() == rows * cols) return result;
            }
            
            // Change the direction (East -> South -> West -> North).
            d = (d + 1) % 4;
        }
        
        // Return the final spiral order of matrix positions.
        return result;
    }
};
