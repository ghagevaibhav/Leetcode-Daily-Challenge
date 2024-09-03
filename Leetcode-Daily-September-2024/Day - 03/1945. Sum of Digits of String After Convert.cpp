class Solution {
public:
    int getLucky(string s, int k) {
        // Convert each character in the string to its corresponding numeric value
        // The character 'a' is mapped to 1, 'b' to 2, ..., 'z' to 26.
        string number = "";
        for (char x : s) {
            // Calculate the numeric value of the character and append it to the number string
            number += to_string(x - 'a' + 1);
        }
        
        // Perform the transformation `k` times
        while (k > 0) {
            int temp = 0;
            // Sum the digits of the current number string
            for (char x : number) {
                temp += x - '0';  // Convert character to integer and add to the sum
            }
            // Convert the sum back to a string for the next iteration (if any)
            number = to_string(temp);
            k--;  // Decrement the number of remaining transformations
        }
        // Return the final transformed number as an integer
        return stoi(number);
    }
};
