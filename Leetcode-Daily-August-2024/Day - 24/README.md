# Nearest Palindromic Number Algorithm and Complexity Analysis

## Algorithm

1. **Initialization**:
   - Determine the length of the input string `n` and store it in `len`.
   - Initialize a vector `candidates` to store potential palindrome candidates.
   - Add two edge case candidates:
     - The largest number with `len - 1` digits (e.g., 999...999).
     - The smallest number with `len + 1` digits (e.g., 100...001).

2. **Generate Palindrome Candidates**:
   - Calculate the prefix of `n` by taking the first half (or slightly more if `len` is odd) of the string.
   - Generate three palindromes by modifying the prefix:
     - Subtract 1 from the prefix and create a palindrome by mirroring it.
     - Keep the prefix unchanged and create a palindrome.
     - Add 1 to the prefix and create a palindrome.
   - Append these palindromes to the `candidates` vector.

3. **Find the Nearest Palindrome**:
   - Convert the original string `n` to a long integer `num` for numerical comparison.
   - Initialize variables `closest` and `minDiff` to store the nearest palindrome and the smallest difference, respectively.
   - Iterate through all candidates:
     - Skip the candidate if it is equal to `num`.
     - Calculate the absolute difference between the candidate and `num`.
     - Update `closest` if the difference is smaller than `minDiff` or if the difference is the same but the candidate is numerically smaller.

4. **Return the Result**:
   - Convert the nearest palindrome `closest` back to a string and return it as the result.

## Complexity Analysis

### Time Complexity:
- **Generating Candidates**: The candidates are generated based on the prefix, which takes `O(1)` time since the prefix is a constant-length substring (half the length of `n`).
- **Checking Candidates**: The number of candidates generated is constant (five candidates in total). Comparing each candidate with the original number and calculating the difference takes `O(1)` time per candidate.
- **Overall Time Complexity**: The overall time complexity is `O(len)`, where `len` is the length of the input string `n`.

### Space Complexity:
- **Space for Candidates**: The `candidates` vector stores a constant number of long integers, resulting in `O(1)` space.
- **Overall Space Complexity**: The overall space complexity is `O(1)` since only a fixed amount of extra space is used.

The algorithm is efficient and operates linearly in relation to the length of the input.
