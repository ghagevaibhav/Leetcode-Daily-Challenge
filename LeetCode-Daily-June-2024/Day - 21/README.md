# Algorithm Explanation

## Algorithm

1. **Initialization**:
   - `n`: Size of the `grumpy` array.
   - `l`: Left pointer for the sliding window.
   - `window`: Sum of customers in the current sliding window where the owner is grumpy.
   - `max_window`: Maximum sum of grumpy customers in any sliding window of size `m`.
   - `satisfied`: Base number of satisfied customers when the owner is not grumpy.

2. **Main Loop**:
   - Iterate over each minute (from `i = 0` to `i = n - 1`):
     - If `grumpy[i] == 1`, add `customers[i]` to the `window` (since the owner is grumpy and the technique can make them satisfied).
     - Otherwise, add `customers[i]` to `satisfied` (since these customers are always satisfied).

3. **Window Adjustment**:
   - If the current window size exceeds `m` (i.e., `i - l + 1 > m`):
     - Check if the leftmost customer in the window was grumpy. If so, subtract their value from `window`.
     - Move the left pointer `l` to the right by 1.

4. **Update Maximum Window**:
   - Update `max_window` to be the maximum of its current value and `window`.

5. **Return Result**:
   - Return the sum of `satisfied` and `max_window`.

## Complexity Explanation

- **Time Complexity**: O(n)
  - The algorithm makes a single pass through the `customers` and `grumpy` arrays, each of length `n`.
  - Sliding window adjustments and sum updates are done in constant time.

- **Space Complexity**: O(1)
  - The algorithm uses a fixed amount of extra space for variables (`l`, `window`, `max_window`, `satisfied`).
