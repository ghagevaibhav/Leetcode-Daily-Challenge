### Algorithm Steps

1. **Input-Output Optimization**:
   - Define a lambda expression `ZERO` to optimize input-output operations by disabling synchronization with C standard streams and untying `cin` from `cout`.

2. **`numRescueBoats` Function**:
   - **Initialization**:
     - Get the number of people `n` from the input vector.
     - Initialize the variable `ans` to store the number of rescue boats needed.
     - Sort the vector `people` in non-decreasing order of weights.

3. **Two Pointers Approach**:
   - Initialize two pointers `i` and `j` to 0 and `n - 1`, respectively.
   - **Iterate Until Pointers Meet**:
     - While `i` is less than or equal to `j`, perform the following steps:
       - **Check Weight Limit**:
         - If the sum of weights of people at positions `i` and `j` is less than or equal to the given limit:
           - Increment `i` (move to the next lightest person).
           - Decrement `j` (move to the next heaviest person).
           - Increment `ans` (both people can fit in the same boat).
         - Else (sum exceeds limit):
           - Decrement `j` (move to the next heaviest person).
           - Increment `ans` (heaviest person needs their own boat).
   - **Return Answer**:
     - After the iteration, return the total number of rescue boats needed (`ans`).

## Time Complexity

- Sorting the `people` vector: O(n log n)
- Iterating through the vector: O(n)
- Overall time complexity: O(n log n)

## Space Complexity

- Additional space used for sorting: O(log n) to O(n)
- Overall space complexity: O(n)

