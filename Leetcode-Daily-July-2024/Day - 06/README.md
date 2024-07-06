# PassThePillow Function Explanation

The `passThePillow` function simulates a game where a pillow is passed around in a circle of `n` people, and the goal is to determine who has the pillow after a certain amount of `time`.

## Algorithm Explanation

1. **Cycle Length**:
    - In a circle of `n` people, the pillow is passed to the last person and then back to the first person, creating a back-and-forth sequence.
    - Therefore, the total cycle length is `n * 2 - 2`.

2. **Effective Time Calculation**:
    - Using the modulo operation `time % (n * 2 - 2)`, we determine the effective time within one complete cycle. This simplifies the problem by reducing the total time to a manageable number within one cycle length.

3. **Direction Adjustment**:
    - The term `n - 1 - effective_time` adjusts for the change in direction after reaching the end of the circle. It handles the reverse direction when the effective time exceeds the forward pass.

4. **Final Calculation**:
    - The result is `n - abs(n - 1 - effective_time)`, which ensures the correct position by accounting for both forward and reverse passes.

### Example

Let's consider an example where `n = 4` and `time = 5`:
- Cycle length = `4 * 2 - 2 = 6`.
- Effective time = `5 % 6 = 5`.
- Calculating position: `4 - abs(4 - 1 - 5) = 4 - abs(3 - 5) = 4 - abs(-2) = 4 - 2 = 2`.

Therefore, after 5 units of time, the pillow is with person 2.

## Complexity Analysis

### Time Complexity
- The time complexity of this function is **O(1)** because the calculations involve only a few arithmetic operations and the modulo operation, all of which take constant time.

### Space Complexity
- The space complexity of this function is **O(1)** since no additional space is used that grows with the input size. The function only uses a fixed amount of extra space for variables like `effective_time`.
