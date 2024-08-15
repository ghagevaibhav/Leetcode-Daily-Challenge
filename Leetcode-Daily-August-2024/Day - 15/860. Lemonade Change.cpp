class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // Initialize counters for $5 and $10 bills
        int fives = 0, tens = 0;

        // Iterate through each bill in the input list
        for (int bill : bills) {
            if (bill == 5) {
                // If the customer pays with a $5 bill, simply increase the count of $5 bills
                fives++;
            } else if (bill == 10) {
                // If the customer pays with a $10 bill
                if (fives == 0) {
                    // If no $5 bill is available to give change, return false
                    return false;
                }
                // Give change with one $5 bill and increase the count of $10 bills
                fives--;
                tens++;
            } else {
                // If the customer pays with a $20 bill
                if (tens > 0 && fives > 0) {
                    // Prefer giving change using one $10 bill and one $5 bill
                    tens--;
                    fives--;
                } else if (fives >= 3) {
                    // Otherwise, give change using three $5 bills if possible
                    fives -= 3;
                } else {
                    // If neither option is possible, return false
                    return false;
                }
            }
        }
        // If all customers were able to receive the correct change, return true
        return true;
    }
};
