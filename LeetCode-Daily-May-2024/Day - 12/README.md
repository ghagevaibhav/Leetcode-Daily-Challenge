## Algorithm Steps

1. **Initialize**:
   - Get the size of the grid `n`. (Time Complexity: O(1))
   - Create a 2D vector `ans` to store the result, with dimensions `(n-2) x (n-2)`. (Time Complexity: O((n-2) * (n-2)), which simplifies to O(n^2) in terms of the size of the grid.)

2. **Iterate Over the Grid**:
   - Start iterating over the grid, excluding the last two rows and columns.
   - Use nested loops:
     - Outer loop iterates over rows, ranging from `0` to `n-2`.
     - Inner loop iterates over columns, ranging from `0` to `n-2`. (Time Complexity: O(n^2))

3. **Calculate Maximum Value for Each Subgrid**:
   - For each cell in the grid:
     - Find the maximum value in the 3x3 subgrid centered around it:
       - For the first row of the subgrid:
         - Calculate the maximum of the three elements in the first row.
       - For the second row of the subgrid:
         - Calculate the maximum of the three elements in the second row.
       - For the third row of the subgrid:
         - Calculate the maximum of the three elements in the third row.
     - Find the maximum value among the maximum values of each row. (Time Complexity: O(1) per cell)

4. **Store Maximum Value in Result Grid**:
   - Store the maximum value found in step 3 in the result grid `ans` at the corresponding position. (Time Complexity: O(1) per cell)

5. **Return Result**:
   - After iterating through the entire grid, return the result grid `ans`.
   
## Time Complexity :
  - O((n-2) * (n-2)), which simplifies to O(n^2) in terms of the size of the grid.
