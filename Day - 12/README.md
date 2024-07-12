# Algorithm and Complexity Explanation

## Algorithm

1. Initialize variables:
   - `n` to the size of the input string `s`.
   - `aCount` and `bCount` to 0 for counting occurrences of 'a' and 'b' respectively.
   - `lesser` to the minimum of `x` and `y` to determine the lesser value.
   - `result` to 0 for storing the maximum gain.

2. Traverse each character `c` in the string `s`:
   - If `c` is greater than 'b':
     - Add `lesser` multiplied by the minimum of `aCount` and `bCount` to `result`.
     - Reset `aCount` and `bCount` to 0.
   - Else if `c` is 'a':
     - If `y` is greater than `x` and `bCount` is greater than 0:
       - Decrement `bCount`.
       - Add `y` to `result`.
     - Else:
       - Increment `aCount`.
   - Else if `c` is 'b':
     - If `x` is greater than `y` and `aCount` is greater than 0:
       - Decrement `aCount`.
       - Add `x` to `result`.
     - Else:
       - Increment `bCount`.

3. After the loop, add `lesser` multiplied by the minimum of `aCount` and `bCount` to `result`.

4. Return `result` as the final maximum gain.

## Complexity Analysis

- **Time Complexity**: O(n)
  - The algorithm traverses the string `s` once, resulting in a linear time complexity.

- **Space Complexity**: O(1)
  - The algorithm uses a constant amount of extra space for the counters and result variable, leading to a constant space complexity.
