class Solution {
public:
    // Function to find the center of the star graph
    int findCenter(vector<vector<int>>& e) {
        // Check if the first vertex of the first edge is the same as any vertex in the second edge
        // If true, then it's the center of the star graph
        // Otherwise, the second vertex of the first edge is the center
        return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
    }
};
