# Algorithm and Complexity Explanation

## Problem Statement
The problem is to find the minimum number of steps required to get exactly `n` 'A's on the screen starting with only one 'A'. You can only perform two operations:
1. Copy All: You can copy all the characters present on the screen.
2. Paste: You can paste the characters you copied.

## Algorithm

1. **Base Case**:
   - If `n` is 1, return 0 because no operations are needed (you already have one 'A').

2. **Initialize Variables**:
   - `steps` to keep track of the total number of steps required.
   - `factor` starting from 2 to find the smallest factor of `n`.

3. **Loop Until `n` Reduces to 1**:
   - While `n` is greater than 1:
     - Check if the current `factor` is a divisor of `n`.
     - If it is, divide `n` by `factor` and add `factor` to the `steps`.
     - Repeat this process until `n` is no longer divisible by the current `factor`.
     - Increment `factor` to check the next potential divisor.

4. **Return `steps`**:
   - After the loop ends, return the total `steps`, which gives the minimum steps required.

## Example Walkthrough
- Suppose `n = 18`.
- The smallest prime factors of 18 are 2 and 3.
- 18 = 2 × 3 × 3, so the minimum steps = 2 + 3 + 3 = 8.

## Complexity Analysis

### Time Complexity
- The time complexity is **O(√n)**.
- This is because, in the worst case, the factorization loop runs for all numbers up to √n.

### Space Complexity
- The space complexity is **O(1)**.
- The algorithm only uses a constant amount of extra space for the variables `steps` and `factor`.
