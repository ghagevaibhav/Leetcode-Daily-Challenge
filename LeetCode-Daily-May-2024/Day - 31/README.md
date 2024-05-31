# Algorithm Explanation: Two Buckets Approach for Finding Two Single Numbers

## Overview
The problem involves finding two unique numbers in an array where every other number appears exactly twice. The "Two Buckets" algorithm efficiently solves this problem in linear time and constant space.

## Algorithm Steps

### Step 1: XOR All Numbers Together
- Initialize a variable `xorr` to 0.
- Iterate over each number in the input array `nums` and compute the XOR of all the numbers.
- This operation will cancel out all numbers that appear twice, leaving the XOR of the two unique numbers (`a` and `b`).

### Step 2: Find the Rightmost Set Bit
- The result of the XOR operation (`xorr`) gives us `a ^ b`.
- To differentiate between `a` and `b`, find the rightmost set bit in `xorr`. This can be done using the expression `(xorr & (xorr - 1)) ^ xorr`.
- This step isolates the lowest set bit that differs between `a` and `b`.

### Step 3: Divide Numbers into Two Groups
- Initialize two variables, `b1` and `b2`, to 0.
- Iterate over each number in `nums` again. Use the rightmost set bit found in the previous step to partition the numbers into two groups:
  - One group where the bit is set.
  - Another group where the bit is not set.
- XOR the numbers in each group separately. This will cancel out the duplicate numbers within each group, leaving us with the two unique numbers.

### Step 4: Return the Result
- The two unique numbers are now stored in `b1` and `b2`.
- Return these two numbers as the result.

## Complexity Analysis

### Time Complexity
- **O(n)**: The algorithm involves two passes through the array.
  - The first pass computes the XOR of all numbers.
  - The second pass partitions the numbers into two groups and computes the XOR within each group.

### Space Complexity
- **O(1)**: The algorithm uses a constant amount of extra space.
  - Only a few integer variables are used to store intermediate results and the final output.

## Summary
The "Two Buckets" algorithm efficiently finds the two unique numbers in an array where every other number appears twice by leveraging the properties of the XOR operation. The key steps involve computing the overall XOR, identifying a distinguishing bit, partitioning the numbers into two groups based on this bit, and then finding the unique numbers through further XOR operations.
