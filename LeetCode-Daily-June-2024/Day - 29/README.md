# Algorithm Explanation

## Problem Description
Given a directed graph with `n` nodes and a list of edges, we need to compute the ancestors for each node in the graph.

## Approach
1. **Data Structures**:
   - Use a 2D vector `ans` where `ans[i]` will store the ancestors of node `i`.
   - Construct an adjacency list `directChild` where `directChild[i]` holds the children of node `i` based on the provided edges.

2. **DFS Function**:
   - Implement a depth-first search (DFS) function (`dfs`) that recursively traverses each node's children (`directChild[curr]`).
   - For each child `ch` of the current node `curr`:
     - Check if `x` (current ancestor) is already in `ans[ch]`.
     - If not, add `x` to `ans[ch]` and recursively call `dfs` for node `ch`.

3. **Initialization**:
   - Initialize `ans` and `directChild` based on the number of nodes `n` and the given `edges`.
   - Iterate through each node and start DFS to populate `ans` with ancestors.

4. **Execution**:
   - Invoke DFS from each node to compute ancestors, ensuring each ancestor is added only once per node.

5. **Output**:
   - Return the computed `ans`, where `ans[i]` contains the ancestors of node `i`.

## Complexity Analysis
- **Time Complexity**: 
  - Building the `directChild` adjacency list takes O(E), where E is the number of edges.
  - Performing DFS for each node takes O(V + E), where V is the number of vertices and E is the number of edges. In worst case, each edge and vertex is visited once.
  - Therefore, the overall time complexity is O(V + E).

- **Space Complexity**:
  - Additional space used by `ans` and `directChild` is O(V + E).
  - Recursive stack space in DFS can go up to O(V) in worst case.
  - Thus, the overall space complexity is O(V + E).

