class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        // To store the original indices of the robots
        vector<int> ids;
        for(int i = 0; i < n; i++){
            ids.push_back(i);
        }
        
        // Lambda function to compare robots based on their positions
        auto compare = [&](int id1, int id2){
            return positions[id1] <= positions[id2];
        };
        
        // Sorting robots based on their positions
        sort(ids.begin(), ids.end(), compare);

        // Stack to keep track of robots moving to the right ('R')
        stack<int> st;
        for(auto id: ids){
            if(directions[id] == 'R'){
                st.push(id); // Push the index of the robot moving to the right
            }
            else {
                // Process collisions for robots moving to the left ('L')
                while(!st.empty() && healths[id] > 0){
                    if(healths[id] > healths[st.top()]){
                        healths[id]--; // Decrease health of the current robot
                        healths[st.top()] = 0; // The robot in the stack is destroyed
                        st.pop(); // Remove the destroyed robot from the stack
                    }
                    else if(healths[id] < healths[st.top()]){
                        healths[id] = 0; // The current robot is destroyed
                        healths[st.top()]--; // Decrease health of the robot in the stack
                    }
                    else {
                        healths[id] = 0; // Both robots destroy each other
                        healths[st.top()] = 0;
                        st.pop();
                    }
                }
            }
        }
        
        // Collect the healths of the robots that survived
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(healths[i] > 0){
                ans.push_back(healths[i]);
            }
        }
        
        return ans; // Return the list of healths of surviving robots
    }
};
