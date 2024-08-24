# Fraction Addition Algorithm and Complexity Analysis

## Algorithm

1. **Initialization**:
   - Start with `num = 0` and `den = 1`, representing the cumulative fraction (`num/den`).
   - Initialize an index `i = 0` to traverse through the input string `expression`.
   - Calculate the size of the string `n = expression.size()`.

2. **Processing Each Fraction**:
   - While `i < n`, iterate through the string to process each fraction:
     - Initialize `currentnum = 0` and `currentden = 0` to store the numerator and denominator of the current fraction.
     - Check if the current fraction is negative by examining `expression[i]`.
     - Skip any leading '+' or '-' symbols.
     - Extract the numerator by iterating over digits and converting the characters to integers.
     - Skip the '/' character.
     - Extract the denominator by iterating over digits and converting the characters to integers.
     - Adjust the numerator if the fraction is negative.

3. **Updating the Cumulative Fraction**:
   - Use the formula to add fractions: `num/den + currentnum/currentden`.
   - Update the cumulative numerator and denominator accordingly.

4. **Simplification**:
   - Calculate the greatest common divisor (GCD) of the cumulative numerator and denominator.
   - Divide both the numerator and denominator by the GCD to simplify the fraction.

5. **Return the Result**:
   - Convert the simplified numerator and denominator to a string and return the result in the format `num/den`.

## Complexity Analysis

### Time Complexity:
- **Extracting Numerators and Denominators**: Each digit in the string is processed once, resulting in an `O(n)` time complexity where `n` is the length of the input string.
- **GCD Calculation**: The GCD of two numbers can be calculated in `O(log(min(num, den)))` time using the Euclidean algorithm. However, since this step occurs only once at the end, it does not significantly impact the overall complexity.
- **Overall Time Complexity**: The overall time complexity is `O(n)` due to the single pass required to parse the input string.

### Space Complexity:
- **Space for Variables**: The space complexity is `O(1)` since only a fixed amount of extra space is used for storing the numerator, denominator, and a few other variables.
- **Overall Space Complexity**: The overall space complexity is `O(1)`.

The algorithm is efficient and operates within linear time relative to the size of the input.
