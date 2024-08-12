# `KthLargest` Class Algorithm and Complexity

## Algorithm

### Initialization (`KthLargest` Constructor):
1. **Input**: An integer `k` and a vector of integers `nums`.
2. **Create a Min-Heap**: 
   - Use a min-heap (priority queue) to store the `k` largest elements seen so far.
3. **Iterate through `nums`**:
   - For each element `ele` in `nums`, push it into the min-heap.
   - If the size of the min-heap exceeds `k`, pop the smallest element.
   - This process ensures that only the `k` largest elements are kept in the min-heap.

### Adding a New Element (`add` Method):
1. **Input**: An integer `val` to be added.
2. **Push `val` into the Min-Heap**:
   - Add the new value `val` to the min-heap.
   - If the size of the min-heap exceeds `k`, remove the smallest element (top of the heap).
3. **Return the `k-th` Largest Element**:
   - The top element of the min-heap is the `k-th` largest element among all elements seen so far.

## Complexity Analysis

### Time Complexity:
- **Constructor (`KthLargest`)**: 
  - The time complexity of inserting each element into the min-heap is `O(log k)`.
  - For `n` elements in `nums`, the total time complexity is `O(n log k)`.

- **Add Method (`add`)**:
  - Each insertion into the min-heap takes `O(log k)` time.
  - Thus, the time complexity for each call to `add` is `O(log k)`.

### Space Complexity:
- The space complexity is `O(k)` since the min-heap stores at most `k` elements.

### Summary:
- **Initialization**: `O(n log k)`
- **Adding an Element**: `O(log k)`
- **Space Complexity**: `O(k)`
