# Algorithm and Complexity Explanation

## Algorithm

1. **Initialization**:
    - Determine the size `n` of the input vector `nums`.
    - Initialize `flipped` to 0 to keep track of the current flip state.
    - Initialize `res` to 0 to count the total number of flips.
    - Create a vector `isFlipped` of size `n`, initialized to 0, to track the positions where flips have been applied.

2. **Main Loop**:
    - Iterate through each bit in the input vector `nums` from index `0` to `n-1`:
        - If the current index `i` is greater than or equal to `k`, update the flip state by removing the effect of flips that are out of the current window. This is done by XOR-ing `flipped` with `isFlipped[i-k]`.
        - Check if the current bit (`nums[i]`) is equal to the current flip state (`flipped`):
            - If true, it means the current bit needs to be flipped to make it `1`.
            - Check if flipping the next `k` bits would exceed the bounds of the array (`i + k > n`):
                - If yes, return `-1` because it's not possible to flip them.
            - Otherwise, mark the current index `i` as flipped by setting `isFlipped[i]` to `1`.
            - Toggle the flip state by XOR-ing `flipped` with `1`.
            - Increment the flip count `res`.

3. **Return Result**:
    - After completing the loop, return the total number of flips required (`res`).

## Complexity Analysis

### Time Complexity

- The algorithm iterates through the input vector `nums` exactly once.
- Each operation inside the loop (checking and updating `flipped`, marking flips, toggling the flip state) takes constant time `O(1)`.
- Therefore, the overall time complexity is **O(n)**, where `n` is the size of the input vector `nums`.

### Space Complexity

- The algorithm uses an auxiliary vector `isFlipped` of size `n`.
- Other than the input vector `nums`, it uses a few additional variables (`flipped`, `res`), which take constant space.
- Therefore, the overall space complexity is **O(n)**.

### Summary

- **Time Complexity**: `O(n)`
- **Space Complexity**: `O(n)`
