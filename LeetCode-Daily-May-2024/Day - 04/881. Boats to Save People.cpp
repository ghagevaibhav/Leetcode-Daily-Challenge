// This is a lambda expression to optimize input-output operations
const int ZERO = []()
{
    // Disable synchronization with C standard streams
    std::ios_base::sync_with_stdio(false);
    
    // Untie cin from cout for performance improvement
    std::cin.tie(nullptr);
    
    // Return 0
    return 0;
}();

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size(); // Get the number of people
        int ans = 0; // Initialize the answer variable
        sort(people.begin(), people.end()); // Sort the people's weights
        
        // Use two pointers approach
        int i = 0, j = n - 1; // i points to the lightest person, j points to the heaviest person
        while (i <= j) { // Iterate until both pointers meet
            if (people[i] + people[j] <= limit) { // If both can fit in the same boat
                i++; // Move to the next lightest person
                j--; // Move to the next heaviest person
                ans++; // Increment the number of boats needed
            } else {
                ans++; // Increment the number of boats needed, as the heaviest person needs their own boat
                j--; // Move to the next heaviest person
            }
        }
        return ans; // Return the total number of boats needed
    }
};
