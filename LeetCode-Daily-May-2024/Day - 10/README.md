# Step-by-Step Explanation

1. **Initialization**:
   - Get the size of the input array (`n`).
   - Create a max heap to store fractions along with their corresponding pairs (`pq`).

2. **Iterate Through Pairs**:
   - Iterate through all pairs of elements in the array using two nested loops.
   - For each pair `(a[i], a[j])` where `i < j`:
     - Calculate the fraction `a[i] / a[j]`.
     - Push the fraction and the corresponding pair onto the max heap.

3. **Keep Heap Size at 'k'**:
   - After pushing each pair onto the heap, if the size of the max heap exceeds 'k', pop the top element to maintain the heap size of 'k'.

4. **Get Kth Smallest Fraction**:
   - After processing all pairs, the top element of the max heap will contain the kth smallest fraction.

5. **Return Result**:
   - Get the pair corresponding to the top element of the max heap.
   - Return the pair containing the numerator and denominator of the kth smallest fraction.

## Complexity Analysis

- **Time Complexity**:
  - Iterating through all pairs: O(n^2)
  - Pushing/popping elements to/from the max heap: O(n^2 log k)
  - Overall Time Complexity: O(n^2 log k)
- **Space Complexity**:
  - Space required for the max heap: O(k)
  - Overall Space Complexity: O(k)
