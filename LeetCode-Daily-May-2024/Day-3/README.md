## Algorithm Steps

1. **Initialization**:
   - Initialize two pointers `i` and `j` to 0 to traverse `version1` and `version2` strings, respectively.

2. **Iterate Through Versions**:
   - While either `version1` or `version2` has characters left:
     - Extract numeric values from the current part of `version1` and `version2`.
     - Compare the extracted numeric values:
       - If `num1` is less than `num2`, return -1 (indicating `version1` is older).
       - If `num1` is greater than `num2`, return 1 (indicating `version2` is older).
     - Move to the next part of the version numbers by incrementing both pointers.

3. **Handle Equal Versions**:
   - If both versions are equal, return 0 (indicating they are the same version).

## Time Complexity

- Traversing through the versions: O(max(n, m)), where n is the length of `version1` and m is the length of `version2`.
- Overall time complexity: O(max(n, m))

## Space Complexity

- Constant space used for variables: O(1)
