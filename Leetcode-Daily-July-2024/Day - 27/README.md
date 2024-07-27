# Algorithm and Complexity Explanation

## Algorithm

1. **Initialization**:
   - Define `inf` as a large number representing infinity (`1 << 29`).
   - Create a 2D array `g` of size 26x26 to store the minimum conversion costs between characters.
   - Initialize the diagonal elements of `g` to 0 (no cost to convert a character to itself) and other elements to `inf`.

2. **Graph Population**:
   - For each conversion from `original[i]` to `changed[i]` with a cost `cost[i]`, update `g[original[i] - 'a'][changed[i] - 'a']` to the minimum of the current value and `cost[i]`.

3. **Floyd-Warshall Algorithm**:
   - Apply the Floyd-Warshall algorithm to find the shortest paths between all pairs of characters:
     ```cpp
     for (int k = 0; k < 26; ++k) {
         for (int i = 0; i < 26; ++i) {
             for (int j = 0; j < 26; ++j) {
                 g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
             }
         }
     }
     ```

4. **Cost Calculation**:
   - Initialize `ans` to 0.
   - For each character in the `source` string, check if it differs from the corresponding character in the `target` string.
   - If characters differ, add the conversion cost from `g`. If the conversion cost is `inf` (no valid path), return -1.

5. **Return Result**:
   - Return the total minimum cost stored in `ans`.

## Complexity

### Time Complexity

1. **Initialization**: O(1) - Constant time to initialize `inf` and the `g` array.
2. **Graph Population**: O(M) - Where `M` is the size of the `original` vector. Each conversion cost is processed once.
3. **Floyd-Warshall Algorithm**: O(26^3) - The algorithm runs three nested loops, each iterating 26 times (number of characters in the alphabet).
4. **Cost Calculation**: O(N) - Where `N` is the length of the `source` string. Each character in the `source` is processed once.

Overall Time Complexity: O(26^3 + N + M), which simplifies to O(1) + O(N) + O(M) since 26^3 is a constant.

### Space Complexity

1. **Graph Storage**: O(26^2) - The `g` array stores conversion costs between all pairs of 26 characters.
2. **Other Storage**: O(1) - Variables `inf`, `ans`, and loop indices consume constant space.

Overall Space Complexity: O(1) + O(26^2), which simplifies to O(1) as 26^2 is a constant.

Therefore, the algorithm is efficient for practical purposes given the constraints on character set size.
