class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int initialChalkPieces) {
        // Calculate the total chalk required to complete one full round of the chalk usage
        long long totalChalkNeeded = 0;
        for (int studentChalkUse : chalk) {
            totalChalkNeeded += studentChalkUse;
        }
        
        // Find the remaining chalk after several complete rounds
        // using modulo operation, as chalk consumption repeats cyclically
        int remainingChalk = initialChalkPieces % totalChalkNeeded;
        
        // Determine which student will use the last piece of chalk
        for (int studentIndex = 0; studentIndex < chalk.size(); studentIndex++) {
            // If the remaining chalk is less than the chalk needed by the current student
            // return the index of this student
            if (remainingChalk < chalk[studentIndex]) {
                return studentIndex;
            }
            // Subtract the chalk used by the current student from the remaining chalk
            remainingChalk -= chalk[studentIndex];
        }
        
        // Default return value, though logically the loop should always return within it
        return 0;
    }
};

// Static code block to optimize input/output operations in competitive programming
static const int kds = []() {
    ios::sync_with_stdio(false);  // Disable synchronization with C-style I/O
    cin.tie(nullptr);             // Untie cin from cout, reducing I/O overhead
    cout.tie(nullptr);            // Untie cout from cin, further optimizing output operations
    return 0;                     // Return 0 to complete the static block
}();
