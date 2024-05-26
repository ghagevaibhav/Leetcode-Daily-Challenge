### Algorithm Explanation

The problem requires us to determine the number of valid attendance records of length `n` where:
- No more than one 'A' (absent) is present.
- No more than two consecutive 'L' (late) are present.

We use a dynamic programming approach to solve this problem efficiently. The algorithm can be explained as follows:

1. **Initialization**:
   - Define a constant `MOD = 1000000007` to handle large numbers.
   - Create two 2D vectors, `dp_last` and `dp_current`, to store the number of valid sequences for each state. 
     - The first dimension represents whether 'A' has been used (0 or 1).
     - The second dimension represents the count of consecutive 'L's (0 to 2).

2. **Base Case**:
   - Initialize `dp_last[0][0] = 1` to represent the single valid way to have an empty string.

3. **Dynamic Programming Transition**:
   - Iterate over each position from `0` to `n-1`.
   - For each position, iterate over possible counts of 'A' (0 or 1) and 'L' (0 to 2).
   - For each state `(count_a, count_l)`, update `dp_current` based on the following transitions:
     - Adding a 'P': Increment the state with the same `count_a` and reset `count_l` to 0.
     - Adding an 'A': If `count_a` is 0, increment the state with `count_a + 1` and reset `count_l` to 0.
     - Adding an 'L': If `count_l` is less than 2, increment the state with the same `count_a` and `count_l + 1`.

4. **Update States**:
   - After processing all transitions for the current length, set `dp_last` to `dp_current` and reset `dp_current` for the next iteration.

5. **Result Calculation**:
   - Sum up the values in `dp_last` for all combinations of `count_a` and `count_l` to get the total number of valid sequences of length `n`.

### Complexity Analysis

- **Time Complexity**: The time complexity of this algorithm is \(O(n \times 2 \times 3)\), which simplifies to \(O(n)\). This is because:
  - We iterate over each position in the sequence (n iterations).
  - For each position, we consider 2 possible values for `count_a` (0 or 1).
  - For each value of `count_a`, we consider 3 possible values for `count_l` (0 to 2).

- **Space Complexity**: The space complexity is \(O(1)\), as we use a constant amount of space irrespective of the input size:
  - The `dp_last` and `dp_current` arrays each have a fixed size of 2x3.
  - No other data structures grow with the input size `n`.

Thus, the algorithm is efficient and well-suited for large values of `n`.
