# Explanation of C++ Solution

## Step-by-Step Explanation

1. **Initialization**:
   - Initialize the result (`res`) as positive infinity.
   - Create a vector `pairs` to store pairs of `(wage/quality, quality)`.

2. **Create Pairs**:
   - Iterate through the `quality` and `wage` vectors.
   - For each index `i`, calculate the ratio of `wage[i] / quality[i]` and store the pair `(ratio, quality[i])` in the `pairs` vector.

3. **Sort Pairs**:
   - Sort the `pairs` vector based on the first element of each pair (the wage/quality ratio).

4. **Max Heap and Total Quality**:
   - Create a max heap (`maxHeap`) to store qualities.
   - Initialize the total quality (`total_quality`) to 0.

5. **Iterate Through Pairs**:
   - Iterate through each pair in the sorted `pairs` vector.
   - For each pair:
     - Push the quality onto the max heap.
     - Add the quality to the `total_quality`.
     - If the size of the max heap exceeds `k`, pop the top element.
     - If the size of the max heap reaches `k`, calculate the cost (`total_quality * ratio`) and update `res` with the minimum of the current `res` and the calculated cost.

6. **Return Result**:
   - Return the minimum cost (`res`).

## Complexity Analysis

- **Time Complexity**:
  - Constructing the `pairs` vector: O(n)
  - Sorting the `pairs` vector: O(n log n)
  - Iterating through the `pairs` vector: O(n)
  - Pushing/popping elements to/from the max heap: O(n log k) (Since there are 'n' elements and each operation takes log k time)
  - Overall Time Complexity: O(n log n)
- **Space Complexity**:
  - Space required for the `pairs` vector: O(n)
  - Space required for the max heap: O(k)
  - Overall Space Complexity: O(n + k)
