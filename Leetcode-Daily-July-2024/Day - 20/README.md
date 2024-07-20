# Restore Matrix Algorithm

## Algorithm Explanation

1. **Initialization**:
   - Get the number of rows `n` from the size of `rowSum`.
   - Get the number of columns `m` from the size of `colSum`.
   - Initialize a matrix `matrix` with dimensions `n x m` filled with zeros.

2. **Filling the Matrix**:
   - Iterate over each cell in the matrix using two nested loops:
     - Outer loop iterates through rows with index `i` from `0` to `n-1`.
     - Inner loop iterates through columns with index `j` from `0` to `m-1`.
     - For each cell `(i, j)`:
       - Set `matrix[i][j]` to the minimum of `rowSum[i]` and `colSum[j]`.
       - Update `rowSum[i]` by subtracting `matrix[i][j]`.
       - Update `colSum[j]` by subtracting `matrix[i][j]`.

3. **Returning the Result**:
   - Return the filled `matrix`.

## Complexity Analysis

### Time Complexity
- The algorithm consists of two nested loops iterating over all cells in an `n x m` matrix.
- The operations inside the loops (finding the minimum, updating row and column sums) are constant time operations.
- Therefore, the overall time complexity is **O(n * m)**, where `n` is the number of rows and `m` is the number of columns.

### Space Complexity
- The primary space usage is for the output matrix, which requires **O(n * m)** space.
- Additional space is used for storing the `rowSum` and `colSum` arrays, but these are given as input and do not contribute to extra space complexity.
- Therefore, the overall space complexity is **O(n * m)**.
