# Algorithm Explanation and Complexity

## Algorithm

1. **Initialization**:
   - Create an unordered map `mp` to store node values and their corresponding `TreeNode` pointers.
   - Create an unordered set `children` to store child node values.

2. **Process Descriptions**:
   - Iterate over each `arr` in `descriptions`:
     - Extract `parent`, `child`, and `isLeft` from `arr`.
     - Insert `child` into the `children` set.
     - If `parent` is not in `mp`, create a new `TreeNode` for `parent` and add it to `mp`.
     - If `child` is not in `mp`, create a new `TreeNode` for `child` and add it to `mp`.
     - Attach the `child` node to the `left` or `right` of the `parent` node based on the value of `isLeft`.

3. **Identify the Root**:
   - Initialize `root` to `-1`.
   - Iterate over `descriptions` again to find a node that is not present in the `children` set, which will be the root node.
   - Set `root` to this node's value.

4. **Return the Root**:
   - Return the `TreeNode` corresponding to the root node from the `mp` map.

## Complexity Analysis

### Time Complexity
- **Initialization**: Creating the map and set takes constant time, \(O(1)\).
- **Processing Descriptions**:
  - Iterating over `descriptions` takes \(O(n)\), where `n` is the number of elements in `descriptions`.
  - Each insertion and lookup operation in `mp` and `children` takes \(O(1)\) on average due to the properties of hash maps and sets.
  - Thus, the total time complexity for processing descriptions is \(O(n)\).
- **Identifying the Root**:
  - Iterating over `descriptions` again to find the root takes \(O(n)\).
- **Overall Time Complexity**: The overall time complexity is \(O(n)\).

### Space Complexity
- **Map and Set**: Storing `mp` and `children` requires space proportional to the number of unique nodes.
  - In the worst case, each node and its child are unique, so the space complexity is \(O(m)\), where `m` is the number of unique nodes.
- **Tree Nodes**: Creating `TreeNode` objects also requires \(O(m)\) space.
- **Overall Space Complexity**: The overall space complexity is \(O(m)\).

Therefore, the algorithm efficiently constructs the binary tree with a time complexity of \(O(n)\) and a space complexity of \(O(m)\).
