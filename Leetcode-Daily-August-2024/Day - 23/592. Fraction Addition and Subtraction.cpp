class Solution {
public:
    string fractionAddition(string expression) {
        // Initialize numerator (num) as 0 and denominator (den) as 1
        int num = 0;
        int den = 1;
        // Start index i for traversing the expression and store the size of expression
        int i = 0;
        int n = expression.size();

        // Loop through the entire expression
        while (i < n) {
            // Initialize current numerator and denominator for each fraction
            int currentnum = 0;
            int currentden = 0;
            // Check if the current fraction is negative
            bool negative = (expression[i] == '-');

            // Skip any '+' or '-' signs
            while (i < n && (expression[i] == '-' || expression[i] == '+')) {
                i++;
            }

            // Extract the numerator of the current fraction
            while (i < n && isdigit(expression[i])) {
                int a = expression[i] - '0';  // Convert character to integer
                currentnum = (currentnum * 10) + a;  // Construct the numerator
                i++;
            }
            i++;  // Skip the '/' character

            // Extract the denominator of the current fraction
            while (i < n && isdigit(expression[i])) {
                int a = expression[i] - '0';  // Convert character to integer
                currentden = (currentden * 10) + a;  // Construct the denominator
                i++;
            }

            // If the fraction is negative, multiply the numerator by -1
            if (negative) {
                currentnum *= -1;
            }

            // Update the result's numerator and denominator using the current fraction
            num = num * currentden + den * currentnum;
            den = den * currentden;
        }

        // Reduce the final fraction by dividing both numerator and denominator by their GCD
        int Gcd = abs(__gcd(num, den));
        num /= Gcd;
        den /= Gcd;

        // Return the reduced fraction as a string
        return to_string(num) + "/" + to_string(den);
    }
};
