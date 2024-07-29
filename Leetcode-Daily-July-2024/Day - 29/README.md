# Algorithm and Complexity Explanation

## Algorithm: Counting Valid Teams

The task is to count the number of valid teams that can be formed from the given array `arr`, where a valid team consists of three elements \( arr[i], arr[j], arr[k] \) such that:

1. \( arr[i] < arr[j] < arr[k] \) or
2. \( arr[i] > arr[j] > arr[k] \).

To solve this, we can use a brute force approach with nested loops to count the number of valid teams with each element as the middle element.

### Steps:

1. **Initialization**:
   - Initialize `result` to 0 to store the total number of valid teams.

2. **Main Loop**:
   - Iterate through the array with an index `i` starting from the second element (i = 1) to the second-to-last element (i = n-2).

3. **Counting Elements**:
   - For each element `arr[i]`, count how many elements to its left (`j < i`) are smaller (`leftSmall`) and larger (`leftLarge`) than `arr[i]`.
   - Similarly, count how many elements to its right (`j > i`) are smaller (`rightSmall`) and larger (`rightLarge`) than `arr[i]`.

4. **Calculating Teams**:
   - The number of valid teams with `arr[i]` as the middle element can be formed by:
     - Combining smaller elements on the left with larger elements on the right (`leftSmall * rightLarge`).
     - Combining larger elements on the left with smaller elements on the right (`leftLarge * rightSmall`).

5. **Result**:
   - Sum up all the valid teams for each `arr[i]` and return the total count.

## Complexity Analysis

### Time Complexity: O(n^2)
- **Outer Loop**: The outer loop runs from `i = 1` to `i = n-2`, resulting in O(n) iterations.
- **Inner Loops**: For each `i`, there are two inner loops. The first inner loop runs from `j = 0` to `j = i-1` (average O(n/2) iterations) and the second inner loop runs from `j = i+1` to `j = n-1` (average O(n/2) iterations).
- Combining these, the time complexity is O(n) * O(n) = O(n^2).

### Space Complexity: O(1)
- The algorithm uses a constant amount of extra space for variables such as `result`, `leftSmall`, `leftLarge`, `rightSmall`, and `rightLarge`.
- Therefore, the space complexity is O(1).
