# Josephus Problem: Algorithm Explanation and Complexity Analysis

## Problem Overview
The problem is to find the winner of a game where people are arranged in a circle and every k-th person is eliminated until only one person remains. This is known as the Josephus problem.

## Algorithm Explanation

### Steps

1. **Initialization**:
   - Initialize the answer `ans` to `-1` and the starting index `ind` to `0`.
   - Adjust `k` to be zero-based by subtracting `1`.
   - Populate a vector `v` with people numbered from `1` to `n`.

2. **Recursive Elimination**:
   - Use a recursive function `solve` to eliminate people:
     - **Base Case**: If only one person is left in the vector `v`, store this person in `ans` as the winner.
     - **Index Calculation**: Update the index `ind` to the position of the next person to be eliminated using the formula `(ind + k) % v.size()`.
     - **Elimination**: Remove the person at the current index `ind` from the vector `v`.
     - **Recursive Call**: Call the `solve` function with the updated index and the reduced vector until only one person is left.

3. **Result**:
   - The recursive calls continue until the base case is reached, and the winner is determined.
   - Return the winner stored in `ans`.

## Complexity Analysis

### Time Complexity
- The time complexity of the algorithm is **O(n^2)**. 
  - In each call to the `solve` function, an element is removed from the vector, which takes **O(n)** time due to the need to shift elements.
  - There are **n** recursive calls, one for each person being eliminated.
  - Therefore, the total time complexity is **O(n) * O(n) = O(n^2)**.

### Space Complexity
- The space complexity of the algorithm is **O(n)**.
  - The space required for the vector `v` is **O(n)**.
  - The recursion depth can go up to **n**, resulting in an additional **O(n)** space for the call stack.
  - Therefore, the total space complexity is **O(n)**.
