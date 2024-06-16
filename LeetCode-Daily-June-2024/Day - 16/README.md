# Algorithm Explanation and Complexity

## Algorithm

1. **Initialization**:
   - `missing` is set to 1, which represents the smallest sum that cannot currently be formed.
   - `patches` is initialized to 0, counting the number of patches needed.
   - `i` is the index to traverse the `nums` array.

2. **Main Loop**:
   - Continue looping while `missing` is less than or equal to `n`.
   - Inside the loop:
     - If `i` is within the bounds of `nums` and `nums[i]` is less than or equal to `missing`:
       - Add `nums[i]` to `missing` (extend the range of sums we can form).
       - Increment `i` to move to the next element.
     - Else:
       - Add `missing` itself to `missing` (doubling `missing`).
       - Increment the `patches` count.

3. **Termination**:
   - The loop terminates when `missing` exceeds `n`.
   - Return the `patches` count.

## Complexity

- **Time Complexity**: `O(m)`, where `m` is the length of the `nums` array. In each iteration, we either process an element of `nums` or add a patch.
- **Space Complexity**: `O(1)`, since we only use a few extra variables regardless of the input size.
