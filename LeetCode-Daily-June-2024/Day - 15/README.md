# Algorithm Explanation and Complexity Analysis

## Algorithm Explanation

The function `findMaximizedCapital` aims to maximize the capital after completing up to `k` projects, given initial capital `w`, and two vectors `profits` and `capital` representing the profit and the capital required for each project respectively.

### Steps:
1. **Initialization**:
    - Create a vector of pairs `projects` where each pair consists of (capital required, profit).
    - Populate this vector by iterating through the `profits` and `capital` vectors.
    
2. **Sorting**:
    - Sort the `projects` vector in ascending order based on the capital required for each project.

3. **Max-Heap for Profits**:
    - Initialize a priority queue (max-heap) `maximizeCapital` to keep track of the profits of projects that can be afforded with the current capital `w`.
    
4. **Select Projects**:
    - Iterate up to `k` times:
        - Push all projects that can be started with the current capital `w` into the max-heap.
        - If the max-heap is empty (i.e., no projects can be afforded), break out of the loop.
        - Otherwise, select the project with the maximum profit from the max-heap, add its profit to the current capital `w`, and remove it from the heap.

5. **Return the Result**:
    - Return the final capital `w` after completing up to `k` projects.

## Complexity Analysis

### Time Complexity:
- **Sorting**: Sorting the `projects` vector takes \(O(n \log n)\) time, where \(n\) is the number of projects.
- **Heap Operations**: In the worst case, every project could be pushed and popped from the heap exactly once. Each `push` and `pop` operation on a heap takes \(O(\log n)\) time.
    - Pushing projects into the heap takes \(O(n \log n)\) time in total.
    - Popping from the heap up to `k` times takes \(O(k \log n)\) time.

Therefore, the overall time complexity is \(O(n \log n + k \log n)\).

### Space Complexity:
- The space complexity is dominated by the storage of the `projects` vector and the max-heap `maximizeCapital`.
    - The `projects` vector requires \(O(n)\) space.
    - The max-heap requires \(O(n)\) space in the worst case.
  
Thus, the overall space complexity is \(O(n)\).
