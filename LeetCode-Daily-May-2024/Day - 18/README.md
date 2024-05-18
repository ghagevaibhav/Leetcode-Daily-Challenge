# Distribute Coins in Binary Tree Algorithm and Complexity Analysis

## Algorithm Explanation

### Problem Statement
Given a binary tree where each node has a certain number of coins, the goal is to move the coins such that each node has exactly one coin. The task is to calculate the minimum number of moves required to achieve this. A move is defined as transferring a coin from one node to an adjacent node (parent or child).

### Approach
We use a recursive approach to solve this problem. The key idea is to perform a post-order traversal of the tree and calculate the number of excess or deficit coins for each subtree.

### Detailed Steps

#### Define the Class and Variables
1. Create a class `Solution` with a public integer variable `ans` to store the total number of moves required.

#### Recursive Function to Count Steps (`countsteps`)
1. If the current node (`root`) is `null`, return 0.
2. Recursively call `countsteps` for the left and right subtrees to get the number of excess or deficit coins in the left and right subtrees.
3. Calculate the number of moves required to balance the current node by adding the absolute values of the excess/deficit coins from the left and right subtrees to `ans`.
4. Return the total excess or deficit coins for the current node. This is calculated as `(root->val - 1) + leftcoins + rightcoins` where `root->val - 1` represents the coins needed or excess at the current node.

#### Function to Distribute Coins (`distributeCoins`)
1. Initialize the answer `ans` to 0.
2. Call the `countsteps` function starting from the root node.
3. Return the final value of `ans`, which represents the minimum number of moves required to distribute the coins.

# Complexity Analysis

## Time Complexity

**O(N)**: The algorithm traverses each node exactly once in a post-order traversal. Here, N is the number of nodes in the binary tree.

## Space Complexity

**O(H)**: The space complexity is determined by the maximum depth of the recursion stack, which is equal to the height of the tree (H). In the worst case, the height of the tree can be N (for a skewed tree), making the space complexity O(N). For a balanced tree, the space complexity would be O(log N).
