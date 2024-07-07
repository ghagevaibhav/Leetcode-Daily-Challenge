class Solution {
public:
    // Function to calculate the maximum number of water bottles that can be drunk
    int numWaterBottles(int numBottles, int numExchange) {
        // Initialize totalBottles with the initial number of bottles
        int totalBottles = numBottles;

        // Loop while there are enough bottles to exchange for a new one
        while (numBottles >= numExchange) {
            // Add the number of new bottles obtained from the exchange to the total count
            totalBottles += numBottles / numExchange;
            
            // Update numBottles to be the sum of new bottles obtained from the exchange
            // and the remaining unexchangeable bottles
            numBottles = (numBottles / numExchange) + (numBottles % numExchange);
        }

        // Return the total number of bottles that can be drunk
        return totalBottles;
    }
};
