# Max Points Algorithm Explanation

## Problem Description

Given a 2D grid `points` where `points[i][j]` represents the points obtainable at cell `(i, j)`, the task is to determine the maximum points you can collect starting from any cell in the first row to any cell in the last row. Moving from one row to the next incurs a linear cost proportional to the column distance traveled.

## Algorithm

### Step 1: Initialization
- **DP Array**: Initialize a `dp` array where `dp[j]` represents the maximum points obtainable up to the previous row when ending at column `j`.
- **First Row Initialization**: Set the first row of the `dp` array to the values of the first row of the `points` matrix, as there is no prior row to consider.

### Step 2: Iterate Through Rows
For each row `r` from the second row to the last row:
1. **Calculate Left Maximum Array (`leftMax`)**:
   - Traverse the row from left to right.
   - For each column `j`, set `leftMax[j]` to the maximum value of `dp[j] + j` from the left up to column `j`.
   
2. **Calculate Right Maximum Array (`rightMax`)**:
   - Traverse the row from right to left.
   - For each column `j`, set `rightMax[j]` to the maximum value of `dp[j] - j` from the right up to column `j`.

3. **Update DP Array for Current Row**:
   - For each column `j`, the new `dp[j]` is computed as the maximum of:
     - `leftMax[j] - j` (adjusted value moving left to right)
     - `rightMax[j] + j` (adjusted value moving right to left)
   - Add the points from the current cell `points[r][j]` to this maximum value.

4. **Set `dp` to `newDp`**: The `dp` array is updated to reflect the maximum points obtainable for the current row.

### Step 3: Result
- After processing all rows, the maximum value in the `dp` array represents the maximum points that can be collected by reaching the last row.

## Complexity Analysis

### Time Complexity
- **Initialization**: The `dp` array initialization and first row setup take `O(col)` time.
- **Row Iteration**: For each of the `row - 1` remaining rows:
  - The `leftMax` and `rightMax` arrays are computed in `O(col)` time each.
  - The `newDp` array is updated in `O(col)` time.
- **Overall**: The time complexity is `O(row * col)`.

### Space Complexity
- **DP Array**: Requires `O(col)` space.
- **LeftMax and RightMax Arrays**: Each requires `O(col)` space.
- **Overall**: The space complexity is `O(col)`.

Thus, the algorithm efficiently computes the maximum points in `O(row * col)` time and `O(col)` space.
