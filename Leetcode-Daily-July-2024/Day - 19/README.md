# Lucky Numbers in a Matrix Algorithm

## Algorithm Explanation

The algorithm aims to find all the "lucky numbers" in a given matrix. A "lucky number" is defined as an element that is the minimum in its row and the maximum in its column.

### Steps:

1. **Initialization**:
   - Determine the number of rows (`n`) and columns (`m`) in the matrix `mat`.
   - Create an empty vector `ans` to store the lucky numbers.

2. **Iterate Through Each Element**:
   - Use two nested loops to iterate through each element of the matrix:
     - Outer loop (`i`) iterates over the rows.
     - Inner loop (`j`) iterates over the columns.

3. **Find the Minimum in the Current Row**:
   - For the current element `mat[i][j]`, find the minimum element in the row `i` using the `min_element` function and store it in `mini`.

4. **Check If the Current Element is the Minimum in its Row**:
   - If `mat[i][j]` is equal to `mini`, set a flag `a` to true.

5. **Find the Maximum in the Current Column**:
   - Initialize `maxi` to the smallest possible integer value (`INT_MIN`).
   - Use another loop to iterate through all elements in the current column `j` to find the maximum element and store it in `maxi`.

6. **Check If the Current Element is the Maximum in its Column**:
   - If `mat[i][j]` is equal to `maxi`, set a flag `b` to true.

7. **Identify Lucky Number**:
   - If both flags `a` and `b` are true, add `mat[i][j]` to the `ans` vector.

8. **Reset Flags**:
   - Reset flags `a` and `b` to false before moving to the next element.

9. **Return Result**:
   - After completing the iteration, return the `ans` vector containing all the lucky numbers.

## Complexity Analysis

### Time Complexity:

- **Outer Loop**:
  - Runs `n` times, where `n` is the number of rows in the matrix.
  
- **Inner Loop**:
  - Runs `m` times, where `m` is the number of columns in the matrix.
  
- **Finding Minimum in the Row**:
  - For each element, finding the minimum element in the row takes `O(m)` time.
  
- **Finding Maximum in the Column**:
  - For each element, finding the maximum element in the column takes `O(n)` time.
  
- **Total Time Complexity**:
  - The combined complexity for each element is `O(m) + O(n) = O(n + m)`.
  - Since we perform this operation for each of the `n * m` elements in the matrix, the overall time complexity is `O(n * m * (n + m))`.

### Space Complexity:

- **Auxiliary Space**:
  - The space complexity is `O(1)` for extra space used, excluding the space required to store the result.
  
- **Result Storage**:
  - The `ans` vector stores at most `min(n, m)` elements in the worst case.
  - Therefore, the space complexity for the result is `O(min(n, m))`.
  
- **Overall Space Complexity**:
  - Combining the above, the overall space complexity is `O(min(n, m))`.
