# Algorithm Explanation: Maximum Stone Removal

## Problem Overview
The goal is to determine the maximum number of stones that can be removed from a 2D plane, where each stone is placed on distinct coordinates. A stone can only be removed if it shares the same row or column with another stone. The challenge is to identify connected components of stones that can be removed together, ensuring that at least one stone remains in each component.

## Algorithm

1. **Define a Valid Connection**: 
   - Create a function `isValid` that checks if two stones share the same row or column. If they do, they are considered connected.

2. **Depth First Search (DFS)**:
   - Implement a `dfs` function that recursively visits all stones connected to a given stone. Mark each visited stone to avoid revisiting it.

3. **Component Count**:
   - Traverse through all stones using a loop. For each stone, if it has not been visited, initiate a DFS starting from that stone. This DFS will mark all stones in the same connected component.
   - Count the number of connected components found during the traversal.

4. **Calculate Removable Stones**:
   - The number of stones that can be removed is the total number of stones minus the number of connected components, as each component must leave at least one stone unremoved.

## Complexity Analysis

### Time Complexity
- **DFS Traversal**: Each stone is visited once during the DFS, and for each stone, we potentially check against all other stones to see if they are connected. Thus, the time complexity of the DFS is \(O(n^2)\), where \(n\) is the number of stones.
- **Overall Time Complexity**: Since the DFS is invoked for each stone, the overall time complexity is \(O(n^2)\).

### Space Complexity
- **Visited Array**: We use an array of size \(n\) to keep track of visited stones, leading to a space complexity of \(O(n)\).
- **Call Stack for DFS**: In the worst case, the DFS call stack may reach a depth of \(n\), leading to an additional space complexity of \(O(n)\).
- **Overall Space Complexity**: The total space complexity is \(O(n)\).

In summary, the algorithm efficiently determines the maximum number of stones that can be removed by exploring connected components through DFS, with a time complexity of \(O(n^2)\) and a space complexity of \(O(n)\).
