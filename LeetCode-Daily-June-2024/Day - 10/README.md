# Algorithm Explanation for `heightChecker`

## Algorithm
1. **Copy the Original Heights**: Create a copy of the input vector `heights` and store it in `copyOfHeights`.
2. **Sort the Heights**: Sort the original `heights` vector.
3. **Count Mismatches**: Initialize a counter `cnt` to 0. Iterate through the indices of the `heights` vector and compare each element with the corresponding element in `copyOfHeights`. If they are not equal, increment the counter.
4. **Return the Count**: Return the value of the counter `cnt`, which represents the number of students standing in the wrong positions.

### Step-by-Step Example
Given `heights = [1, 1, 4, 2, 1, 3]`:

1. **Copy the Original Heights**:
   - `copyOfHeights = [1, 1, 4, 2, 1, 3]`

2. **Sort the Heights**:
   - `heights = [1, 1, 1, 2, 3, 4]`

3. **Count Mismatches**:
   - Compare each index:
     - Index 0: `copyOfHeights[0]` (1) == `heights[0]` (1) ➞ No mismatch
     - Index 1: `copyOfHeights[1]` (1) == `heights[1]` (1) ➞ No mismatch
     - Index 2: `copyOfHeights[2]` (4) != `heights[2]` (1) ➞ Mismatch ➞ `cnt++`
     - Index 3: `copyOfHeights[3]` (2) == `heights[3]` (2) ➞ No mismatch
     - Index 4: `copyOfHeights[4]` (1) != `heights[4]` (3) ➞ Mismatch ➞ `cnt++`
     - Index 5: `copyOfHeights[5]` (3) != `heights[5]` (4) ➞ Mismatch ➞ `cnt++`
   - Total mismatches: `cnt = 3`

4. **Return the Count**:
   - Return `cnt`, which is `3`.

## Complexity Analysis

### Time Complexity
- **Copy the Original Heights**: O(n), where `n` is the number of elements in `heights`.
- **Sort the Heights**: O(n log n), as sorting is the most time-consuming operation.
- **Count Mismatches**: O(n), as we iterate through the list once to count mismatches.

Thus, the overall time complexity is dominated by the sorting step, resulting in **O(n log n)**.

### Space Complexity
- **Copy the Original Heights**: Requires O(n) extra space for the copy.
- **Sorting**: The in-place sorting operation does not require additional space beyond the original input and the copy.
- Therefore, the overall space complexity is **O(n)**.

In conclusion, the algorithm efficiently determines the number of students standing in the wrong positions with a time complexity of O(n log n) and a space complexity of O(n).
