# Algorithm and Complexity Explanation

## Algorithm

1. **Initialization**:
   - Create an unordered map `counter` to store the frequency of each string in the input vector `arr`.

2. **First Pass**:
   - Iterate over each string `v` in the vector `arr`.
   - Increment the count of `v` in the `counter` map.

3. **Second Pass**:
   - Iterate over each string `v` in the vector `arr` again.
   - Check if the count of `v` in the `counter` map is 1 (i.e., the string is distinct).
   - If the string is distinct, decrement `k`.
   - If `k` becomes 0, return the current string `v`.

4. **Return**:
   - If the loop completes without finding the k-th distinct string, return an empty string.

## Complexity Analysis

### Time Complexity

- **First Pass**: The first for loop iterates over all the strings in `arr` to count their frequencies. This takes O(n) time, where `n` is the number of strings in `arr`.
- **Second Pass**: The second for loop iterates over all the strings in `arr` to find the k-th distinct string. This also takes O(n) time.
- Therefore, the total time complexity is O(n) + O(n) = O(n).

### Space Complexity

- The `counter` map stores the frequency of each unique string in `arr`. In the worst case, all strings in `arr` are unique, so the map will store `n` entries.
- Therefore, the space complexity is O(n).

## Summary

- The algorithm efficiently finds the k-th distinct string in an array of strings using two passes.
- The overall time complexity is O(n), and the space complexity is O(n), making it suitable for large input sizes.
