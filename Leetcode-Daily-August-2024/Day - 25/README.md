# Postorder Traversal Algorithm

## Algorithm

Postorder traversal of a binary tree visits nodes in the following order: left subtree, right subtree, and then the root node. The traversal can be described as follows:

1. **Base Case:**
   - If the current node is `nullptr`, return immediately. This signifies the end of a branch or an empty tree.

2. **Recursive Traversal:**
   - Recursively traverse the left subtree of the current node.
   - Recursively traverse the right subtree of the current node.

3. **Process Current Node:**
   - After traversing both the left and right subtrees, process the current node by recording its value.

## Complexity

### Time Complexity

- **O(n):** The time complexity is linear, where `n` is the number of nodes in the binary tree. Each node is visited exactly once during the traversal.

### Space Complexity

- **O(h):** The space complexity is determined by the height of the binary tree (`h`). This is the maximum depth of the recursion stack. In the worst case of a skewed tree, this could be `O(n)`, but for a balanced tree, it is `O(log n)`.

The space required for storing the results in a separate data structure (e.g., a list) is `O(n)`, but this is typically not considered part of the recursive space complexity.

## Summary

The algorithm performs a postorder traversal of a binary tree using a depth-first search strategy. It processes each node once, making the time complexity proportional to the number of nodes. The space complexity is based on the height of the tree and is influenced by the depth of the recursion stack.
