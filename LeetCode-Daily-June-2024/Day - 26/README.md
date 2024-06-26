# Balanced Binary Search Tree Algorithm and Complexity

## Algorithm Explanation

### Step 1: Inorder Traversal

1. **Inorder Traversal**:
   - Traverse the tree in an inorder fashion (left, root, right).
   - Store each node in a vector `sortedArr`.
   - This step ensures that the nodes are stored in sorted order.

2. **Function**: `inorderTraverse(TreeNode* root)`
   - Base case: If `root` is `NULL`, return.
   - Recursively traverse the left subtree: `inorderTraverse(root->left)`.
   - Add the current node to the vector: `sortedArr.push_back(root)`.
   - Recursively traverse the right subtree: `inorderTraverse(root->right)`.

### Step 2: Construct Balanced BST

1. **Convert Sorted Array to Balanced BST**:
   - Use the middle element of the current subarray as the root of the subtree.
   - Recursively construct the left subtree using the left half of the current subarray.
   - Recursively construct the right subtree using the right half of the current subarray.

2. **Function**: `sortedArrayToBST(int start, int end)`
   - Base case: If `start` is greater than `end`, return `NULL`.
   - Calculate the middle index: `int mid = (start + end) / 2`.
   - Create the root node with the middle element: `TreeNode* root = sortedArr[mid]`.
   - Recursively build the left subtree: `root->left = sortedArrayToBST(start, mid - 1)`.
   - Recursively build the right subtree: `root->right = sortedArrayToBST(mid + 1, end)`.
   - Return the root node.

### Step 3: Combine Steps

1. **Balance the BST**:
   - Perform inorder traversal to get the sorted array of nodes.
   - Convert the sorted array of nodes to a balanced BST.

2. **Function**: `balanceBST(TreeNode* root)`
   - Call `inorderTraverse(root)` to fill `sortedArr`.
   - Call `sortedArrayToBST(0, sortedArr.size() - 1)` to create the balanced BST.
   - Return the root of the balanced BST.

## Complexity Analysis

### Time Complexity

1. **Inorder Traversal**:
   - Each node is visited once.
   - Time complexity: `O(n)`, where `n` is the number of nodes in the tree.

2. **Sorted Array to Balanced BST**:
   - Each node is used once to create the balanced BST.
   - Time complexity: `O(n)`, where `n` is the number of nodes in the tree.

3. **Overall Time Complexity**:
   - Inorder traversal: `O(n)`.
   - Building balanced BST: `O(n)`.
   - Total time complexity: `O(n)`.

### Space Complexity

1. **Inorder Traversal**:
   - Extra space used for storing the nodes in the vector: `O(n)`.
   - Recursion stack space: `O(h)`, where `h` is the height of the tree (worst case `O(n)` for an unbalanced tree).

2. **Sorted Array to Balanced BST**:
   - Recursion stack space: `O(log n)` for a balanced tree (worst case `O(n)` for an unbalanced tree).

3. **Overall Space Complexity**:
   - Extra space for vector: `O(n)`.
   - Recursion stack space: `O(n)` (worst case).
   - Total space complexity: `O(n)`.

Overall, the algorithm efficiently balances a binary search tree with linear time and space complexity.
