# BST to GST Conversion Algorithm

## Algorithm Explanation

The goal is to convert a Binary Search Tree (BST) into a Greater Sum Tree (GST), where each node contains the sum of all nodes with values greater than or equal to its original value.

### Steps:

1. **Initialization**: 
   - Initialize a variable `sum` to store the cumulative sum of node values.

2. **Traversal Function**:
   - Define a helper function `traverse(TreeNode* root)` to perform a reverse in-order traversal (right -> root -> left) of the tree.
   - **Base Case**: If the current node is `nullptr`, return.
   - **Right Subtree**: Recursively traverse the right subtree.
   - **Update Sum**: Add the current node's value to `sum`.
   - **Update Node Value**: Set the current node's value to `sum`.
   - **Left Subtree**: Recursively traverse the left subtree.

3. **Main Function**:
   - Define the function `bstToGst(TreeNode* root)` to initiate the traversal from the root of the BST.
   - Call the `traverse` function with the root node.
   - Return the root of the modified tree.
