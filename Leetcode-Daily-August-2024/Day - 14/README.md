# Algorithm: Smallest Distance Pair

## Problem Statement
Given an integer array `nums` and an integer `k`, return the `k`-th smallest distance among all the pairs `(nums[i], nums[j])` where `i < j`.

### Steps to Solve:

1. **Sort the Array**:
   - Sort the input array `nums` in non-decreasing order. This helps in calculating pairwise distances efficiently.

2. **Binary Search on Distance**:
   - Define a search range `low` and `high`, where `low` is 0 (minimum possible distance) and `high` is the difference between the maximum and minimum elements in `nums`.
   - The goal is to find the smallest distance `d` such that there are at least `k` pairs with a distance of `d` or less.

3. **Counting Pairs with Distance ≤ mid**:
   - Define a helper function `count_pairs(max_distance)` that counts how many pairs `(i, j)` satisfy `nums[j] - nums[i] <= max_distance`.
   - Use a two-pointer technique:
     - Iterate through each element `nums[i]`.
     - For each `nums[i]`, move a pointer `j` to find the first `nums[j]` such that the distance exceeds `max_distance`.
     - The number of valid pairs for `nums[i]` is `j - i - 1`.

4. **Adjust Search Range**:
   - In each step of the binary search:
     - Calculate `mid` as the average of `low` and `high`.
     - If the number of pairs with distance ≤ `mid` is less than `k`, update `low` to `mid + 1`.
     - Otherwise, update `high` to `mid`.
   - The search continues until `low` equals `high`, which will be the `k`-th smallest distance.

5. **Return Result**:
   - After the binary search completes, `low` will be the desired `k`-th smallest distance.

### Complexity Analysis

- **Time Complexity**: 
  - Sorting the array takes `O(n log n)`.
  - The binary search runs in `O(log(max_distance))`, where `max_distance` is the difference between the maximum and minimum elements in the array.
  - For each step of the binary search, counting pairs takes `O(n)`.
  - Therefore, the overall time complexity is `O(n log n + n log(max_distance))`.

- **Space Complexity**: 
  - The algorithm uses `O(1)` extra space, making it space-efficient.

Thus, the `smallestDistancePair` function efficiently computes the `k`-th smallest pairwise distance using sorting, binary search, and a two-pointer technique for counting valid pairs.
