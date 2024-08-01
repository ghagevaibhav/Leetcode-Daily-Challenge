#include <vector>
#include <string>

class Solution {
public:
    // Function to count the number of seniors (age > 60) in the given details
    int countSeniors(std::vector<std::string>& details) {
        int ans = 0; // Initialize the counter for seniors
        
        // Loop through each detail string in the vector
        for (auto& x : details) {
            // Extract the substring representing the age (characters at positions 11 and 12)
            int age = std::stoi(x.substr(11, 2));
            
            // Increment the counter if the age is greater than 60
            ans += age > 60;
        }
        
        // Return the total count of seniors
        return ans;
    }
};
