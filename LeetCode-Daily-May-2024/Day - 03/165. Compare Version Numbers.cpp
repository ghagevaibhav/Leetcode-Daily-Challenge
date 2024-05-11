#include <string>

class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        int i = 0, j = 0; // Initialize pointers for both versions
        
        // Iterate until both versions have been fully traversed
        while (i < version1.length() || j < version2.length()) {
            int num1 = 0, num2 = 0; // Initialize variables to store the numeric values
            
            // Extract numeric value from version1
            while (i < version1.length() && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i++] - '0'); // Convert character to integer
            }
            
            // Extract numeric value from version2
            while (j < version2.length() && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j++] - '0'); // Convert character to integer
            }
            
            // Compare numeric values
            if (num1 < num2) {
                return -1;
            }
            if (num1 > num2) {
                return 1;
            }
            
            // Move to the next part of the version numbers
            i++;
            j++;
        }
        
        // If both versions are equal, return 0
        return 0;
    }
};
