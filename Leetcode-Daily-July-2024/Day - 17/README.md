# Algorithm and Complexity Explanation

## Algorithm

The algorithm to delete specified nodes from a binary tree and return the remaining forest is as follows:

1. **Initialization:**
   - Create a map (`res`) to store the roots of the resulting forest.
   - Convert the list of nodes to be deleted (`to_delete`) into a set (`to_delete_set`) for quick lookup.
   - Add the root of the tree to the `res` map.

2. **Recursive Function (`recursion`):**
   - The function takes three parameters: the parent node (`parent`), the current node (`cur_node`), and a boolean (`isleft`) indicating if the current node is a left child.
   - **Base Case:** If the current node is `nullptr`, return.
   - **Recursive Calls:** Recursively traverse the left and right subtrees.
   - **Deletion Check:** If the current node is in the `to_delete_set`, handle its deletion:
     - Remove it from the `res` map if present.
     - Disconnect it from its parent.
     - If the current node has left or right children, add them to the `res` map.

3. **Start Recursion:**
   - Initiate the recursion with the root node and `nullptr` as the parent.

4. **Prepare Final Result:**
   - Convert the `res` map into a vector of `TreeNode*` to form the final result.

## Complexity Analysis

### Time Complexity

- **Building the `to_delete_set`:** This takes O(d) time, where d is the number of nodes to be deleted.
- **Recursion:** Each node in the tree is visited once. The operations within each visit (checking for deletion, updating the parent’s pointers, adding children to the result map) are O(1) operations.
  - Therefore, the time complexity for the recursion is O(n), where n is the number of nodes in the tree.
- **Final Conversion:** Converting the result map to a vector takes O(n) time in the worst case.

Overall, the time complexity of the algorithm is O(n + d), where n is the number of nodes in the tree and d is the number of nodes to be deleted.

### Space Complexity

- **`to_delete_set`:** Storing the set of nodes to be deleted takes O(d) space.
- **`res` map:** In the worst case, every node could become a root in the resulting forest, requiring O(n) space.
- **Recursive Call Stack:** The depth of the recursive call stack is bounded by the height of the tree. In the worst case (unbalanced tree), this can be O(n). In the best case (balanced tree), this is O(log n).

Overall, the space complexity is O(n + d) due to the result map, set, and recursive call stack.
