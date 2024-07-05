# Algorithm and Complexity Analysis: Nodes Between Critical Points

## Algorithm

1. Initialize a vector `critical` to store indices of critical points.
2. Use three pointers (`prev`, `curr`, `next`) to traverse the linked list.
3. Iterate through the list, checking each node for local minima or maxima conditions:
   - Local minima: `prev->val > curr->val < next->val`
   - Local maxima: `prev->val < curr->val > next->val`
4. If a critical point is found, add its index to the `critical` vector.
5. After traversal, if less than 2 critical points are found, return {-1, -1}.
6. Calculate the maximum distance between critical points (last - first).
7. Find the minimum distance between adjacent critical points.
8. Return the minimum and maximum distances.

## Time Complexity

- O(n), where n is the number of nodes in the linked list.
  - The main loop iterates through each node once.
  - The final loop to find the minimum distance is at most n-1 iterations.

## Space Complexity

- O(n) in the worst case, where n is the number of nodes in the linked list.
  - The `critical` vector could potentially store indices for all nodes (except first and last) if every node is a critical point.
- O(1) in the best case, if there are 2 or fewer critical points.

## Key Points

1. The algorithm uses a three-pointer approach to compare adjacent nodes efficiently.
2. It handles edge cases, such as when there are fewer than 2 critical points.
3. The solution avoids using extra space for storing the entire list's values, instead only storing indices of critical points.

## Potential Optimizations

1. Early exit: If only the minimum distance is needed, the algorithm could potentially stop after finding the first pair of adjacent critical points with distance 1.
2. Space optimization: If only the min and max distances are needed (not the actual indices), we could avoid storing all critical point indices and instead update min and max on-the-fly.
