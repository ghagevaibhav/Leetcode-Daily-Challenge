# Algorithm Explanation

## Steps

1. **Initialization**:
   - Determine the size of the input array `n`.
   - Find the maximum value `maxi` in the input array.
   - Create a frequency array `freq` of size `maxi + n + 1`, initialized to 0. This ensures enough space for all possible increments.

2. **Frequency Count**:
   - Iterate over each element in the input array and update the frequency array `freq` to count the occurrences of each element.

3. **Making Elements Unique**:
   - Traverse the frequency array `freq`.
   - For each number that has more than one occurrence (`freq[i] > 1`), calculate the excess count (`extra = freq[i] - 1`).
   - Move these excess counts to the next number (`freq[i+1] += extra`).
   - Accumulate the total number of increments required (`ans += extra`).

4. **Result**:
   - Return the total number of increments `ans` needed to make all elements in the array unique.

## Complexity Analysis

- **Time Complexity**:
  - Finding the maximum element: \(O(n)\)
  - Initializing the frequency array: \(O(m)\), where \(m = maxi + n + 1\)
  - Counting frequencies: \(O(n)\)
  - Traversing the frequency array: \(O(m)\)

  Overall, the time complexity is \(O(n + m)\). Since \(m = maxi + n + 1\), in the worst case, it can be approximated to \(O(n + maxi)\).

- **Space Complexity**:
  - The frequency array `freq` requires \(O(m)\) space.
  - Other variables use \(O(1)\) space.

  Overall, the space complexity is \(O(m)\), which simplifies to \(O(n + maxi)\) in the worst case.

## Summary

The algorithm efficiently ensures all elements in the array are unique by incrementing duplicate elements. The use of a frequency array helps track and adjust occurrences, ensuring the solution is both time and space efficient given the constraints.
