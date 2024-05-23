# Algorithm and Complexity Explanation

## Algorithm

### Function: `dfs`
1. **Parameters**: 
   - `nums`: The input array.
   - `idx`: The current index in the array.
   - `k`: The given difference value.
   - `mp`: A map to keep track of the count of elements included in the current subset.

2. **Base Case**: 
   - If `idx` equals the size of `nums`, return 1, indicating one valid subset.

3. **Decision to Include the Current Element**:
   - Check if adding `nums[idx]` would violate the condition by ensuring that neither `nums[idx] - k` nor `nums[idx] + k` are already in the subset (`mp`).
   - If not, include the current element in the subset (`mp[nums[idx]]++`).
   - Make a recursive call to process the next element.
   - Backtrack by removing the current element from the subset.

4. **Decision to Exclude the Current Element**:
   - Make a recursive call to process the next element without including the current element.

5. **Return Value**:
   - Return the sum of the results from including and excluding the current element.

### Function: `beautifulSubsets`
1. **Initialization**:
   - Initialize an empty map (`mp`).

2. **Recursive Call**:
   - Call the `dfs` function starting from the first element (`idx = 0`).

3. **Result Adjustment**:
   - Subtract 1 from the result to exclude the empty subset from the final count.

## Complexity Analysis

### Time Complexity
- The time complexity of this algorithm is `O(2^n)`, where `n` is the length of the input array `nums`.
  - This is because the algorithm explores all possible subsets of the array, and there are `2^n` possible subsets.
  - Each recursive call has two options: either to include the current element or to exclude it, leading to a total of `2^n` combinations.

### Space Complexity
- The space complexity is `O(n)`, where `n` is the length of the input array `nums`.
  - This space is used by the recursion stack, which can go as deep as the length of the array.
  - Additionally, the `unordered_map` `mp` can also store up to `n` elements in the worst case.

## Summary
- The algorithm uses a recursive approach with backtracking to explore all subsets of the input array and count the ones that meet the specified conditions.
- The time complexity is exponential due to the nature of subset generation, and the space complexity is linear in terms of the depth of the recursion stack and the size of the map used for tracking elements in the subset.
