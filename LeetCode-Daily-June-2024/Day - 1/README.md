### Algorithm and Complexity Explanation

#### Algorithm

1. **Initialize Score**:
   - Start with a score variable (`ans`) initialized to 0.

2. **Get String Length**:
   - Determine the length (`n`) of the input string `s`.

3. **Iterate Through the String**:
   - Loop through the string from the first character to the second-to-last character.
   - For each character, compute the absolute difference between it and the next character.
   - Accumulate this difference in the score variable (`ans`).

4. **Return the Final Score**:
   - After the loop completes, return the accumulated score.

#### Complexity Analysis

**Time Complexity**:
- The algorithm iterates through the string once, performing a constant-time operation (computing the absolute difference and adding it to the score) for each pair of consecutive characters.
- Therefore, the time complexity is **O(n)**, where `n` is the length of the string.

**Space Complexity**:
- The algorithm uses a fixed amount of additional space regardless of the input size.
- Therefore, the space complexity is **O(1)**.
