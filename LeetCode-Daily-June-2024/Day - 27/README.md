## Algorithm Explanation

The function `findCenter` aims to find the center vertex of a graph represented by its edges. In this case, the graph is represented using an adjacency list format where `e` is a vector of vectors, each containing two integers representing an edge between two vertices.

### Steps in the Algorithm:
1. **Access Edge Information**: The function assumes the input vector `e` contains exactly two edges (since it directly accesses `e[0]` and `e[1]`).
   
2. **Check Common Vertex**: 
   - It checks if the first vertex (`e[0][0]`) of the first edge (`e[0]`) matches either the first vertex (`e[1][0]`) or the second vertex (`e[1][1]`) of the second edge (`e[1]`).
   - If `e[0][0]` matches `e[1][0]`, it means `e[0][0]` is the common vertex at the center.
   - If `e[0][0]` matches `e[1][1]`, then `e[0][0]` is again the common vertex and hence the center.
   
3. **Return Center Vertex**: 
   - The function returns `e[0][0]` if it is the common vertex, otherwise, it returns `e[0][1]`.

### Complexity Analysis:
- **Time Complexity**: O(1)
  - The function operates in constant time because it performs a fixed number of operations (mostly comparisons and array accesses), independent of the size of the input vector `e`.
  
- **Space Complexity**: O(1)
  - The function uses a constant amount of extra space.
