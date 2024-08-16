# Algorithm: Maximum Distance Between Arrays

## Problem Statement
Given a list of arrays, the goal is to find the maximum distance between any two elements from different arrays. The distance between two elements `a` from array `A` and `b` from array `B` is defined as `|a - b|`, where `A` and `B` are different arrays.

## Approach
1. **Initialization**:
   - Begin by setting the global minimum (`globalMin`) and global maximum (`globalMax`) using the first array's minimum and maximum elements.
   - Initialize a variable `result` to `0` to store the maximum distance found during the process.

2. **Iterate Through Arrays**:
   - For each subsequent array:
     - Identify the local minimum (`localMin`) and local maximum (`localMax`).
     - Calculate the potential maximum distance by considering:
       - The difference between `localMax` and `globalMin`.
       - The difference between `globalMax` and `localMin`.
     - Update `result` with the maximum of the current `result` and the newly calculated distances.

3. **Update Global Min and Max**:
   - After evaluating each array, update `globalMin` and `globalMax` to account for the current array’s extreme values. This ensures that the comparisons in the next iteration consider the most extreme values encountered so far.

4. **Return Result**:
   - After processing all arrays, `result` will contain the maximum distance between any two elements from different arrays.

## Complexity Analysis

### Time Complexity
- **Initialization**: Setting `globalMin` and `globalMax` is performed in constant time, `O(1)`.
- **Iteration**: We loop through each of the `n` arrays (starting from the second one), and each operation within the loop (like finding `localMin`, `localMax`, updating `result`, `globalMin`, and `globalMax`) is done in constant time. Therefore, the total time complexity is `O(n)`.

### Space Complexity
- **Space Used**: The algorithm uses `O(1)` extra space because it only requires a constant amount of memory to store variables such as `globalMin`, `globalMax`, and `result`.

The algorithm is efficient, with a time complexity of `O(n)` and a space complexity of `O(1)`.
