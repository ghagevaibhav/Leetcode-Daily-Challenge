"""
# Algorithm and Complexity Explanation

## Algorithm

1. **Initialize Graph for Row Conditions:**
   - Create an adjacency list for the row conditions using an unordered map.
   - Iterate through each pair in `rowConditions` and populate the adjacency list.

2. **Topological Sort for Row Conditions:**
   - Perform a topological sort on the graph constructed from row conditions.
   - If a cycle is detected during the sort, return an empty matrix.

3. **Initialize Graph for Column Conditions:**
   - Clear the previous graph and create a new adjacency list for column conditions.
   - Iterate through each pair in `colConditions` and populate the adjacency list.

4. **Topological Sort for Column Conditions:**
   - Perform a topological sort on the graph constructed from column conditions.
   - If a cycle is detected during the sort, return an empty matrix.

5. **Map Positions:**
   - Create a map to store the positions of each value based on the results of the topological sorts.
   - Iterate through the results of the row and column sorts and map the positions.

6. **Construct Result Matrix:**
   - Initialize a `k x k` matrix filled with zeros.
   - Populate the matrix using the mapped positions for each value.

7. **Return the Result:**
   - Return the constructed matrix.

### Topological Sort (DFS-based)

1. **Depth-First Search (DFS):**
   - For each node, perform a DFS to detect cycles and generate a topological order.
   - Use a set to track visited nodes and another set to track the current path to detect cycles.
   - If a cycle is detected, return an empty list.

2. **Result Construction:**
   - After visiting all nodes, reverse the order of the nodes to get the correct topological order.

## Complexity Analysis

### Time Complexity

1. **Graph Construction:**
   - Constructing the graph for row conditions takes \(O(E_r)\) time, where \(E_r\) is the number of edges in `rowConditions`.
   - Constructing the graph for column conditions takes \(O(E_c)\) time, where \(E_c\) is the number of edges in `colConditions`.

2. **Topological Sort:**
   - Performing the topological sort involves visiting each node and edge once.
   - The time complexity for the topological sort is \(O(V + E)\), where \(V\) is the number of vertices (up to \(k\)) and \(E\) is the number of edges.

3. **Position Mapping and Matrix Construction:**
   - Mapping positions takes \(O(k)\) time.
   - Constructing the result matrix takes \(O(k^2)\) time.

Overall, the total time complexity is:
\[ O(E_r + E_c + k + k^2) \]

### Space Complexity

1. **Graph Storage:**
   - Storing the graphs requires \(O(V + E)\) space.
   - The space complexity for each graph is \(O(k + \max(E_r, E_c))\).

2. **Topological Sort:**
   - The topological sort uses additional space for visited nodes, current path, and result.
   - The space complexity for the sort is \(O(k)\).

3. **Result Matrix:**
   - Storing the result matrix requires \(O(k^2)\) space.

Overall, the total space complexity is:
\[ O(k + \max(E_r, E_c) + k^2) \]
