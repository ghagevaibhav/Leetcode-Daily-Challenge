# Maximum Minimum Distance Algorithm

## Algorithm Explanation

### Purpose
The goal is to find the maximum possible minimum distance between any two balls when placing `m` balls in given positions.

### Steps
1. **Sort Positions**: First, sort the positions array to facilitate the binary search and placement logic.
2. **Binary Search Initialization**: Initialize two pointers:
    - `left` to 1 (minimum possible gap).
    - `right` to the difference between the maximum and minimum positions (maximum possible gap).
3. **Binary Search**:
    - While `left` is less than or equal to `right`:
        - Calculate the middle point `mid`.
        - Use a helper function `canPlaceBalls(mid, positions, m)` to check if it's possible to place `m` balls with at least `mid` distance apart.
        - If possible, update `maxMinDistance` to `mid` and move `left` to `mid + 1` to try for a larger gap.
        - If not possible, move `right` to `mid - 1` to try for a smaller gap.
4. **Result**: The value of `maxMinDistance` after the binary search loop is the maximum possible minimum distance.

### Helper Function `canPlaceBalls(gap, positions, m)`
- Place the first ball at the first position.
- Iterate through the remaining positions and place a ball only if the current position is at least `gap` distance away from the last placed ball.
- If all `m` balls are placed successfully, return `true`; otherwise, return `false`.

## Complexity Analysis

### Time Complexity
- **Sorting**: `O(n log n)` where `n` is the number of positions.
- **Binary Search**: The search space is the distance range, which is `O(log(max - min))`.
- **Ball Placement Check**: For each binary search step, the placement check takes `O(n)` time.
- **Overall**: The total time complexity is `O(n log n + n log d)`, where `d` is the difference between the maximum and minimum positions.

### Space Complexity
- The space complexity is `O(1)` (ignoring the input space) as we are using a constant amount of additional space.
