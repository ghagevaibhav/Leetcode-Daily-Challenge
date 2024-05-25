## Algorithm Explanation

The solution to the word break problem involves recursively breaking down the string into valid words as defined in the word dictionary. Here's a step-by-step explanation:

1. **Initialization**: The `wordBreak` function initializes by converting the `wordDict` vector into an unordered set (`dict`) for O(1) average-time complexity lookups. It then calls the helper function `wordBreakHelper` starting from index 0 of the string `s`.

2. **Helper Function**: The `wordBreakHelper` function is a recursive function designed to find all valid ways to break the string starting from a given `start` index.

3. **Base Case**: If the `start` index reaches the end of the string `s`, an empty string is added to `validSubstr` to indicate a valid decomposition path.

4. **Recursive Case**:
   - The function iterates through all possible end positions for the substring starting from `start`.
   - For each `end` position, it extracts the substring `prefix` from `start` to `end`.
   - If `prefix` is found in the dictionary (`dict`), it means this substring is a valid word.
   - It then recursively calls `wordBreakHelper` with the new starting position (`end`) to find all valid decompositions of the remaining part of the string.
   - For each valid decomposition of the suffix, it concatenates the current prefix with each suffix (adding a space if the suffix is not empty) and adds it to `validSubstr`.

5. **Return**: The function returns the vector `validSubstr`, which contains all valid ways to break the string `s` starting from the given `start` index.

This approach ensures that all possible combinations of valid words are explored, leveraging recursion to build up complete solutions from valid substrings.

## Complexity Analysis

### Time Complexity
The time complexity of this approach can be quite high due to the nature of the recursion and the need to explore all possible substrings. In the worst case:
- Each character in the string can start a new word, leading to a branching factor of up to `O(2^n)`, where `n` is the length of the string.
- This results in an exponential time complexity in the worst case, making the algorithm `O(2^n)`.

### Space Complexity
The space complexity is determined by:
- The recursion call stack, which can go up to a depth of `O(n)` in the worst case.
- The space required to store the results of valid decompositions.
- The auxiliary space used for the dictionary and storing intermediate results.

Thus, the space complexity is `O(n^2 * k)`, where `k` is the number of valid decompositions. This accounts for storing each valid decomposition and the recursion depth.

Overall, the algorithm is efficient for smaller inputs but can become impractical for very large strings due to its exponential time complexity.
