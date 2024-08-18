class Solution {
public:
    // Function to find the nth ugly number
    int nthUglyNumber(int n) {
        // Declare a set to store unique ugly numbers
        set<long> set;
        
        // Initialize the first ugly number to 1
        long nthNumber = 1;
        
        // Insert the first ugly number into the set
        set.insert(nthNumber);
        
        // Loop n times to find the nth ugly number
        for(int i = 0; i < n; i++) {
            // Get the smallest number from the set, which is the next ugly number
            nthNumber = *set.begin();
            
            // Remove the smallest number from the set as it is now considered
            set.erase(nthNumber);
            
            // Insert the next possible ugly numbers by multiplying the current ugly number by 2, 3, and 5
            set.insert(nthNumber * 2);
            set.insert(nthNumber * 3);
            set.insert(nthNumber * 5);
        }
        
        // Return the nth ugly number
        return nthNumber;
    }
};
