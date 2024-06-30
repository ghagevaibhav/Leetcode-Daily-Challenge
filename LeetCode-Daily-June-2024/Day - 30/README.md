# Algorithm Explanation and Complexity Analysis

## Algorithm Explanation

The algorithm aims to determine the maximum number of edges that can be removed while still allowing both Alice and Bob to traverse the entire graph. It uses the Union-Find data structure to manage the connectivity of the graph.

### Steps:

1. **Union-Find Initialization:**
   - Create two Union-Find structures, one for Alice and one for Bob.

2. **Processing Type 3 Edges:**
   - These edges can be used by both Alice and Bob. For each type 3 edge, attempt to unite the nodes in both Alice's and Bob's Union-Find structures.
   - If either structure performs a union, it indicates that this edge is necessary to keep the graph connected, so we increment the `edgesRequired` counter.

3. **Processing Type 1 and Type 2 Edges:**
   - Process type 1 edges (Alice only) and type 2 edges (Bob only) separately.
   - For each type 1 edge, attempt to unite the nodes in Alice's Union-Find structure. If successful, increment the `edgesRequired` counter.
   - Similarly, for each type 2 edge, attempt to unite the nodes in Bob's Union-Find structure. If successful, increment the `edgesRequired` counter.

4. **Connectivity Check:**
   - After processing all edges, check if both Alice's and Bob's graphs are fully connected using the `isConnected` method of the Union-Find structure.

5. **Result Calculation:**
   - If both graphs are fully connected, return the total number of edges minus the `edgesRequired` counter to get the number of removable edges.
   - If either graph is not fully connected, return `-1` indicating it is not possible to keep both graphs connected.

## Complexity Analysis

### Time Complexity:
- **Union-Find Operations:**
  - Each union and find operation is nearly constant time, O(α(N)), where α is the Inverse Ackermann function, which grows very slowly.
- **Edge Processing:**
  - We process each edge once, so the edge processing step is O(E), where E is the number of edges.

Combining these, the overall time complexity is O(E * α(N)), which is effectively linear for most practical purposes.

### Space Complexity:
- We use two Union-Find structures, each with space proportional to the number of nodes.
- Space complexity is O(N), where N is the number of nodes, due to the storage required for the parent and size arrays in each Union-Find structure.

In summary, the algorithm efficiently processes the edges to determine the maximum number of removable edges while ensuring both Alice and Bob can still traverse the entire graph.
