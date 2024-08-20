# Stone Game II Algorithm and Complexity

## Algorithm Explanation

### Problem Overview:
The Stone Game II is a dynamic programming problem where two players take turns picking stones from a series of piles. The goal is to maximize the number of stones collected. The players can pick between 1 to `2*M` piles during their turn, where `M` starts as 1 and can change based on the number of piles taken in the previous move.

### Steps:

1. **Suffix Sum Calculation**:
   - We first compute the suffix sums of the piles. The suffix sum at index `i` represents the total number of stones from pile `i` to the last pile. This allows us to quickly calculate the remaining stones when a player picks some piles.

2. **Recursive Function with Memoization (`helper`)**:
   - The `helper` function is used to determine the maximum number of stones the first player can get starting from a specific index `i` with a given `M`.
   - **Base Cases**:
     - If all piles have been considered (`i == piles.size()`), the result is 0 because no more stones can be picked.
     - If the remaining piles can all be taken (`i + 2 * M >= piles.size()`), return the total stones from index `i` onward.
   - **Recursive Case**:
     - For each possible move (picking `x` piles where `1 <= x <= 2 * M`), calculate the result of taking `x` piles and then letting the opponent play optimally. The optimal play for the opponent is represented by calling the `helper` function recursively with updated parameters.
     - Memoize the result in the `dp` table to avoid recalculating for the same state.

3. **Main Function (`stoneGameII`)**:
   - Initializes the `dp` table and the suffix sum array.
   - Starts the game from the first pile with `M = 1` by calling the `helper` function.

### Dynamic Programming State:
- `dp[i][M]`: Represents the maximum stones the current player can get starting from index `i` with the current value of `M`.

## Time Complexity:
- The time complexity is `O(N^3)`, where `N` is the number of piles.
  - **Explanation**: There are `N` possible starting indices `i`. For each index, we have up to `N` possible values of `M`. For each state, we iterate over up to `2 * M` possible moves, which in the worst case is `O(N)`.

## Space Complexity:
- The space complexity is `O(N^2)` due to the `dp` table and the `suffixSum` array.
  - **Explanation**: The `dp` table has dimensions `N x N`, where `N` is the number of piles, and the `suffixSum` array has size `N`.
