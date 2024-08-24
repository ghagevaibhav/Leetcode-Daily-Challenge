class Solution {
public:
    string nearestPalindromic(string n) {
        // Get the length of the input string n
        int len = n.size();
        
        // Create a vector to store possible palindrome candidates
        vector<long> candidates;

        // Add two edge case candidates:
        // 1. The largest number with (len - 1) digits, i.e., 999...999 (one less digit)
        candidates.push_back(pow(10, len - 1) - 1);  

        // 2. The smallest number with (len + 1) digits, i.e., 100...001 (one more digit)
        candidates.push_back(pow(10, len) + 1);     

        // Calculate the prefix of n (first half of the number)
        long prefix = stol(n.substr(0, (len + 1) / 2));

        // Generate palindromes by modifying the prefix by -1, 0, and +1
        for (int i = -1; i <= 1; ++i) {
            // Create a new prefix by adding i to the original prefix
            string newPrefix = to_string(prefix + i);

            // Form the candidate palindrome by mirroring the new prefix
            string candidate = newPrefix + string(newPrefix.rbegin() + (len % 2), newPrefix.rend());

            // Add the candidate to the list
            candidates.push_back(stol(candidate));
        }

        // Convert the original string n to a long integer for comparison
        long num = stol(n), closest = -1;

        // Initialize minDiff with a large value
        long minDiff = LONG_MAX;

        // Iterate through all candidate palindromes to find the nearest one
        for (long candidate : candidates) {
            // Skip the candidate if it is equal to the original number
            if (candidate == num) continue; 

            // Calculate the difference between the candidate and the original number
            long diff = abs(candidate - num);

            // Update the closest palindrome if the current candidate has a smaller difference
            // or if the difference is the same but the candidate is numerically smaller
            if (diff < minDiff || (diff == minDiff && candidate < closest)) {
                minDiff = diff;
                closest = candidate;
            }
        }

        // Return the closest palindrome as a string
        return to_string(closest);
    }
};
