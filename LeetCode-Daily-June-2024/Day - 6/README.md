# Algorithm Explanation

## Overview
The algorithm aims to determine if a given vector of integers `hand` can be partitioned into groups of size `groupSize`, such that each group forms a sequence of consecutive numbers.

## Detailed Steps
1. Check if the size of `hand` is divisible by `groupSize`. If not, return false, as it's impossible to form groups.
2. Sort the `hand` vector to ensure that elements are in ascending order.
3. Iterate through each element of the sorted `hand`.
4. For each element `hand[i]`:
    - If `hand[i]` is not already marked as used (`hand[i] != -1`):
        - Invoke the `check` function to verify if a group of size `groupSize` can be formed starting from `hand[i]`.
        - If `check` returns false, it means it's not possible to form a group starting from `hand[i]`. Hence, return false.
5. If all groups can be formed successfully, return true.

## Time Complexity
- Sorting the `hand` vector takes O(nlogn) time.
- Iterating through each element of the vector takes O(n) time.
- Inside the loop, invoking the `check` function might take O(n) in the worst case (if `groupSize` is close to `n`).
- Therefore, the overall time complexity of the algorithm is O(nlogn + n^2) which simplifies to O(n^2) in the worst case.

## Space Complexity
- The space complexity is O(1) as the algorithm only uses a constant amount of extra space for variables regardless of the input size.
