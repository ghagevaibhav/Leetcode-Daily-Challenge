## Algorithm Explanation

The algorithm determines if there exist two non-negative integers `a` and `b` such that \(a^2 + b^2 = c\). Here's a step-by-step explanation of the approach:

1. **Initialization**:
    - Calculate the integer square root of `c` and store it in `maxSquareRoot`. This represents the largest possible value for `a` and `b`.
    - Initialize two pointers, `left` and `right`, to 0 and `maxSquareRoot` respectively.

2. **Two-pointer Approach**:
    - Use a while loop to iterate as long as `left` is less than or equal to `right`.
    - In each iteration:
        - Calculate the sum of squares of the two pointers: \( \text{sumOfSquares} = \text{left}^2 + \text{right}^2 \).
        - Compare `sumOfSquares` with `c`:
            - If `sumOfSquares` equals `c`, return `true` as we have found the integers `a` and `b`.
            - If `sumOfSquares` is greater than `c`, decrement the `right` pointer to reduce the sum.
            - If `sumOfSquares` is less than `c`, increment the `left` pointer to increase the sum.
    - If the loop completes without finding a pair, return `false`.

## Complexity Analysis

### Time Complexity
The time complexity of this algorithm is \( O(\sqrt{c}) \). This is because the two-pointer approach will perform at most \( \sqrt{c} \) iterations, as each pointer (`left` and `right`) moves towards the middle.

### Space Complexity
The space complexity of this algorithm is \( O(1) \). This is because the algorithm uses only a constant amount of extra space, regardless of the input size `c`.
