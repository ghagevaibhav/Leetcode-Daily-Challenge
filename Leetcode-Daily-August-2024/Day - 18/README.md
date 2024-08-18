# Algorithm Explanation: Finding the nth Ugly Number

## Problem Statement
The problem is to find the nth ugly number. Ugly numbers are positive numbers whose only prime factors are 2, 3, or 5. The sequence of ugly numbers starts with 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, and so on.

## Approach
1. **Initialization**:
   - Use a `set` data structure to store the ugly numbers. The set is chosen because it automatically maintains the order of the elements and ensures all elements are unique.
   - Initialize the first ugly number as `1` and insert it into the set.

2. **Iterative Process**:
   - Loop `n` times to find the nth ugly number:
     1. Extract the smallest element from the set, which will be the next ugly number in the sequence.
     2. Remove this smallest element from the set.
     3. Generate the next potential ugly numbers by multiplying the current ugly number by 2, 3, and 5.
     4. Insert these new ugly numbers into the set.
   - The nth extracted element is the nth ugly number.

3. **Return the nth Ugly Number**:
   - After completing the loop, the variable holding the smallest element at the end of the loop will be the nth ugly number, which is returned.

## Complexity Analysis

### Time Complexity
- The time complexity is `O(n log n)`. Here's why:
  - The loop runs `n` times, and in each iteration, the smallest element is extracted from the set and three new elements are added.
  - Inserting and deleting elements from a set (which is typically implemented as a balanced binary search tree) takes `O(log n)` time.
  - Therefore, the overall time complexity is `O(n log n)`.

### Space Complexity
- The space complexity is `O(n)`.
  - The set can hold up to `n` elements at any given time, leading to a space complexity of `O(n)`.

## Conclusion
This approach efficiently finds the nth ugly number by using a set to maintain the smallest current ugly number and generating new candidates through multiplication by 2, 3, and 5. The use of a set ensures that the elements remain unique and are ordered, facilitating the extraction of the smallest element in `O(log n)` time.
