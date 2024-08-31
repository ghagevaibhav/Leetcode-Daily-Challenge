# Algorithm and Complexity Explanation

## Algorithm

The problem involves finding the maximum probability of reaching the `end_node` from the `start_node` in a directed graph, where each edge has a certain success probability. The algorithm used to solve this problem is a modified version of the **Bellman-Ford algorithm**.

### Steps:
1. **Initialization**:
   - Create a vector `maxProb` of size `n` (the number of nodes), initialized to `0.0`, to store the maximum probability of reaching each node from the `start_node`.
   - Set `maxProb[start_node]` to `1.0` because the probability of being at the start node is `100%`.

2. **Relaxation (Bellman-Ford Algorithm)**:
   - Iterate `n-1` times over all the edges to ensure the maximum probability path is found.
   - For each edge `(u, v)` with a success probability `p`:
     - If `maxProb[u] * p > maxProb[v]`, update `maxProb[v]` to `maxProb[u] * p`.
     - Similarly, if `maxProb[v] * p > maxProb[u]`, update `maxProb[u]` to `maxProb[v] * p`.
   - If in any iteration no updates are made, break the loop early to save computation.

3. **Return the Result**:
   - The algorithm returns `maxProb[end_node]`, which represents the maximum probability of reaching the `end_node` from the `start_node`.

## Complexity Analysis

### Time Complexity:
- **Initialization**: O(n), where `n` is the number of nodes.
- **Relaxation (Bellman-Ford Algorithm)**: 
  - The outer loop runs `n-1` times.
  - The inner loop iterates over all edges, which takes `O(E)` time, where `E` is the number of edges.
  - Therefore, the overall time complexity is **O(n * E)**.

### Space Complexity:
- The primary data structure used is the `maxProb` vector, which requires `O(n)` space.
- No additional space-intensive structures are used, so the space complexity is **O(n)**.

This algorithm efficiently finds the path with the maximum probability, leveraging the Bellman-Ford technique adapted for probabilistic graphs.
