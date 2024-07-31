## Algorithm Explanation

The task is to find the minimum number of deletions required to make a string `s` balanced, where a string is considered balanced if there are no 'a' characters after any 'b' characters.

### Steps:
1. Initialize two variables:
   - `ans` to store the minimum number of deletions needed, set to 0.
   - `count_b` to store the count of 'b' characters encountered so far, set to 0.
2. Iterate through each character in the string `s`:
   - If the character is 'b', increment `count_b`.
   - If the character is 'a':
     - Calculate the minimum deletions needed by considering two options:
       - Increment `ans` by 1 (deleting this 'a').
       - Use `count_b` (deleting all 'b's seen so far).
     - Update `ans` to the minimum of these two options.
3. Return the value of `ans` after the loop completes.

## Complexity Analysis

### Time Complexity
- The time complexity of this solution is **O(n)**, where `n` is the length of the string `s`.
- This is because the algorithm iterates through each character in the string exactly once.

### Space Complexity
- The space complexity of this solution is **O(1)**.
- This is because the algorithm uses a constant amount of extra space, regardless of the input size.
