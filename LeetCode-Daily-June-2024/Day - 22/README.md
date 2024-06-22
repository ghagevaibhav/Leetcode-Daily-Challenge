# Algorithm Explanation

The problem is to find the number of subarrays with exactly `k` odd numbers. Here's a detailed breakdown of the algorithm used in the `numberOfSubarrays` function:

## Steps

1. **Initialization**:
   - `n` is assigned the size of the input array `nums`.
   - A vector `cnt` of size `n + 1` is initialized to zero. This vector will count the number of times a certain count of odd numbers has been seen.
   - `cnt[0]` is set to 1 because there's one way to have zero odd numbers (by having no elements).
   - Two integers, `ans` and `t`, are initialized to 0. `ans` will store the number of valid subarrays, and `t` will keep track of the current count of odd numbers.

2. **Iterate Over Each Element**:
   - Loop through each element `v` in the input array `nums`:
     - Increment `t` by 1 if the current element is odd (`v & 1` checks if the last bit is 1, indicating an odd number).
     - If `t - k >= 0`, check if there are `(t - k)` counts of odd numbers previously seen:
       - If so, add the count of those to `ans`, as they form valid subarrays.
     - Increment the count for the current number of odd numbers seen in the `cnt` vector.

3. **Return the Result**:
   - Return `ans` which holds the total number of valid subarrays with exactly `k` odd numbers.

## Complexity Analysis

### Time Complexity

- The algorithm runs in O(n) time, where `n` is the size of the input array `nums`.
- This is because we iterate through the array once and perform constant-time operations for each element.

### Space Complexity

- The space complexity is O(n) due to the additional `cnt` vector used to store the count of occurrences of odd numbers.
- Although the `cnt` vector has a size of `n + 1`, this is still considered O(n) space complexity.
