## Algorithm Explanation

### Function: `insert`

1. **Input:** 
    - A reference to a vector `nums` of integers.
    - An integer `temp` to be inserted into the vector.
2. **Base Case:**
    - If the vector `nums` is empty or the last element of `nums` is less than or equal to `temp`, append `temp` to `nums` and return.
3. **Recursive Case:**
    - Remove the last element from `nums` and store it in `val`.
    - Recursively call `insert(nums, temp)` to insert `temp` into the reduced vector.
    - After returning from the recursive call, push `val` back into `nums`.

### Function: `sort`

1. **Input:** 
    - A reference to a vector `nums` of integers.
2. **Base Case:**
    - If the size of the vector `nums` is 1, return as the vector is already sorted.
3. **Recursive Case:**
    - Remove the last element from `nums` and store it in `temp`.
    - Recursively call `sort(nums)` to sort the remaining elements.
    - After returning from the recursive call, use `insert(nums, temp)` to insert `temp` back into its correct position in the sorted vector.

### Function: `sortArray`

1. **Input:**
    - A vector `nums` of integers.
2. **Process:**
    - Call the built-in `sort` function from the C++ Standard Library to sort the vector.
3. **Output:**
    - Return the sorted vector `nums`.

## Complexity Analysis

### Time Complexity

- **`insert` Function:** 
  - In the worst case, `insert` might need to shift all elements of the vector, resulting in a time complexity of \(O(n)\), where \(n\) is the number of elements in `nums`.

- **`sort` Function:**
  - `sort` makes \(n-1\) recursive calls, and each call to `insert` takes \(O(n)\) time in the worst case.
  - Therefore, the time complexity of the `sort` function is \(O(n^2)\).

- **`sortArray` Function:**
  - The built-in `sort` function from the C++ Standard Library uses Introsort, which has a time complexity of \(O(n \log n)\) on average.
  - Hence, the overall time complexity for `sortArray` is \(O(n \log n)\).

### Space Complexity

- **`insert` Function:**
  - The space complexity is \(O(1)\) for auxiliary space, but each recursive call adds to the call stack, resulting in a space complexity of \(O(n)\) due to recursion.

- **`sort` Function:**
  - Similarly, `sort` uses recursion, leading to a space complexity of \(O(n)\) for the call stack.

- **`sortArray` Function:**
  - The built-in `sort` function uses \(O(1)\) auxiliary space.
  - Thus, the overall space complexity for `sortArray` is \(O(1)\) for auxiliary space, but the call stack depth for the recursive implementation results in \(O(n)\) space complexity due to recursion.
