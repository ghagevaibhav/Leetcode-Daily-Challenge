class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();  // Get the number of log operations
        int steps = 0;  // Initialize the step counter

        // Iterate through each log operation
        for(auto &log: logs){
            if(log == "../"){  // If the operation is to move up a directory
                if(steps == 0){
                    steps = 0;  // If already at root, stay at root
                }
                else if(steps > 0)
                    steps--;  // Move up one level if not at root
            }
            else if(log == "./"){  // If the operation is to stay in the current directory
                steps += 0;  // No change in steps (this line can be omitted)
            }
            else steps += 1;  // If it's a named directory, move down one level
        }   
        return steps;  // Return the final number of steps from the root
    }   
};
