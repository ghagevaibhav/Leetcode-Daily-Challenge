## Algorithm Steps

1. **Initialization**:
   - Get the size of the input array `nums`.
   - Sort the array `nums` in non-decreasing order.

2. **Two Pointers Approach**:
   - Initialize two pointers `l` and `r` at the two ends of the sorted array.
   - While `l` is less than `r`, do the following:
     - Check if the absolute value of the element at `l` is equal to the negative of the element at `r`.
       - If true, return the absolute value of the element at `r`.
       - If false, move `r` to the left if the absolute value of the element at `l` is less than the element at `r`, otherwise move `l` to the right.

3. **Handle No Solution**:
   - If no such element is found while traversing the array, return -1.

## Time Complexity

- Sorting the array: O(n log n)
- Traversing the array with two pointers: O(n)
- Overall time complexity: O(n log n)

## Space Complexity

- Sorting the array in-place: O(1)
- Additional space used for variables: O(1)
- Overall space complexity: O(1)
