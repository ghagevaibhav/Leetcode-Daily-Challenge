class Solution {
public:
    // This function checks if two stones are in the same row or column.
    bool isValid(vector<int>& pos1, vector<int>& pos2)
    {
        // Check if they share the same row or the same column.
        if (pos1[0] == pos2[0]) return true;  // Same row.
        if (pos1[1] == pos2[1]) return true;  // Same column.
        return false;  // Not in the same row or column.
    }

    // This function performs a Depth First Search (DFS) to visit all stones 
    // connected to the current stone (by row or column).
    void dfs(vector<vector<int>>& stones, vector<bool>& visited, int currIdx)
    {
        visited[currIdx] = true;  // Mark the current stone as visited.

        // Iterate over all stones to find the next connected stone.
        for (int i = 0; i < stones.size(); i++)
        {
            if (visited[i]) continue;  // Skip if the stone is already visited.
            if (isValid(stones[i], stones[currIdx]))  // Check if stones are connected.
                dfs(stones, visited, i);  // Recursively visit the connected stone.
        }
    }

    // Main function to count the maximum number of stones that can be removed.
    int removeStones(vector<vector<int>>& stones)
    {
        int n = stones.size();  // Total number of stones.
        vector<bool> visited(n, false);  // Initialize a visited array.
        int componentCount = 0;  // To count connected components.

        // Iterate through all stones.
        for (int i = 0; i < n; i++)
        {
            if (visited[i]) continue;  // Skip if the stone is already visited.
            
            // If a new component (unvisited stone) is found, perform DFS.
            dfs(stones, visited, i);
            componentCount++;  // Increment the component count.
        }

        // Return the maximum number of stones that can be removed, which is 
        // the total number of stones minus the number of connected components.
        return (n - componentCount); 
    }
};
