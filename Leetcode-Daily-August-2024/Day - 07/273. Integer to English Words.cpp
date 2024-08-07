class Solution {
public:
    // Converts a number to its English words representation
    string numberToWords(int num) {
        // Edge case: if the number is zero
        if (num == 0) return "Zero";
        
        // Array to store the big units of thousands, millions, billions
        string bigString[] = {"Thousand", "Million", "Billion"};
        
        // Convert the first (rightmost) three digits
        string result = numberToWordsHelper(num % 1000);
        num /= 1000;  // Reduce the number by removing the last three digits

        // Process the next three digits (thousands, millions, billions)
        for (int i = 0; i < 3; ++i) {
            if (num > 0 && num % 1000 > 0) {
                result = numberToWordsHelper(num % 1000) + bigString[i] + " " + result;
            }
            num /= 1000;  // Move to the next set of three digits
        }

        // Remove the trailing space if any
        return result.empty() ? result : result.substr(0, result.size() - 1); 
    }

    // Helper function to convert numbers less than 1000 to words
    string numberToWordsHelper(int num) {
        // Arrays for single digits, teens, and tens
        string digitString[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string teenString[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string tenString[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string result = "";
        
        // Process hundreds place
        if (num > 99) {
            result += digitString[num / 100] + " Hundred ";
        }
        
        num %= 100;  // Reduce the number by removing the hundreds place
        
        // Process tens and units place
        if (num < 20 && num > 9) {  // For numbers between 10 and 19
            result += teenString[num - 10] + " ";
        } else {  // For numbers 20 and above
            if (num >= 20) {
                result += tenString[num / 10] + " ";
            }
            num %= 10;  // Reduce the number by removing the tens place
            if (num > 0) {  // For single digit numbers
                result += digitString[num] + " ";
            }
        }
        
        return result;
    }
};
