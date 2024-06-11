# Relative Sort Array Algorithm

## Algorithm Explanation

1. **Initialize a Map for Counting Elements:**
   - Create a `map<int, int> mp` to count the occurrences of each element in `arr1`.

2. **Count Elements in `arr1`:**
   - Iterate over each element `x` in `arr1` and increment its count in the map `mp`.

3. **Initialize Result Vector:**
   - Create a vector `vector<int> ans` to store the result.

4. **Process Elements in `arr2`:**
   - For each element `x` in `arr2`, append it to `ans` as many times as it appears in `arr1`.
   - Decrement the count of `x` in `mp` each time it is added to `ans`.

5. **Collect Remaining Elements:**
   - Create a vector `vector<int> remaining` to store the elements of `arr1` that are not in `arr2`.
   - Iterate over each pair in `mp` and append the key (element) to `remaining` as many times as its value (count).

6. **Sort Remaining Elements:**
   - Sort the `remaining` vector.

7. **Merge Results:**
   - Append the sorted `remaining` vector to `ans`.

8. **Return the Result:**
   - Return the `ans` vector as the final sorted array.

## Complexity Analysis

### Time Complexity
1. **Counting Elements in `arr1`:** O(n)
   - Iterating over `arr1` to count elements takes O(n) time, where `n` is the length of `arr1`.

2. **Processing Elements in `arr2`:** O(m * k)
   - For each of the `m` elements in `arr2`, we append it `k` times to `ans` (where `k` is its count in `arr1`). In total, this operation is bounded by O(n) because the total number of operations is proportional to the length of `arr1`.

3. **Collecting Remaining Elements:** O(n)
   - Iterating over the map to collect remaining elements takes O(n) time.

4. **Sorting Remaining Elements:** O(r log r)
   - Sorting the `remaining` vector takes O(r log r) time, where `r` is the number of remaining elements (which is at most `n`).

5. **Merging Results:** O(r)
   - Appending the sorted `remaining` vector to `ans` takes O(r) time.

**Total Time Complexity:** O(n log n)
   - The dominant term is the sorting step, making the total time complexity O(n log n).

### Space Complexity
1. **Map Storage:** O(n)
   - The map `mp` stores counts of elements in `arr1`.

2. **Result Vector:** O(n)
   - The result vector `ans` stores the final sorted array.

3. **Remaining Vector:** O(n)
   - The remaining vector stores elements not in `arr2`.

**Total Space Complexity:** O(n)
   - The additional space used is proportional to the length of `arr1`.

Overall, the algorithm efficiently sorts `arr1` relative to `arr2` with a time complexity of O(n log n) and a space complexity of O(n).
