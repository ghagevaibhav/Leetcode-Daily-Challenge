class Solution {
public:
    static int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Optimize I/O operations for competitive programming
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        // Initialize starting position (i, j) = (0, 0)
        int i = 0, j = 0, res = 0, direction = 1;  // direction: 1 = North, 2 = East, 3 = South, 4 = West
        
        // Use a set to store the coordinates of obstacles for fast lookup
        set<pair<int,int>> st;
        for (const auto &it : obstacles) {
            st.insert({it[0], it[1]});
        }

        // Iterate over each command in the commands vector
        for (const auto &command : commands) {
            if (command == -1) {  // Turn right
                direction = (direction + 1) % 5;
                if (direction == 0) direction = 1;  // Adjust to stay within 1 to 4
            } else if (command == -2) {  // Turn left
                direction = (direction - 1);
                if (direction == 0) direction = 4;  // Adjust to stay within 1 to 4
            } else {  // Move forward by 'command' steps
                int dist = command;
                while (dist > 0) {
                    // Check the direction and move accordingly, checking for obstacles
                    if (direction == 1) {  // Moving North
                        if (st.find({i, j + 1}) != st.end()) break;  // Stop if obstacle is found
                        j++;  // Move up
                    } else if (direction == 2) {  // Moving East
                        if (st.find({i + 1, j}) != st.end()) break;  // Stop if obstacle is found
                        i++;  // Move right
                    } else if (direction == 3) {  // Moving South
                        if (st.find({i, j - 1}) != st.end()) break;  // Stop if obstacle is found
                        j--;  // Move down
                    } else {  // Moving West
                        if (st.find({i - 1, j}) != st.end()) break;  // Stop if obstacle is found
                        i--;  // Move left
                    }
                    // Calculate the maximum Euclidean distance squared from the origin
                    res = max(res, i * i + j * j);
                    dist--;  // Decrease the remaining steps
                }
            }
        }
        // Return the maximum Euclidean distance squared that the robot has achieved
        return res;
    }
};
