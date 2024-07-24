# Algorithm Explanation

The algorithm for sorting a list of integers based on a custom digit mapping involves the following steps:

1. **Initialize Variables**:
    - `numsSize`: Stores the size of the `nums` vector.
    - `mappedAndIndexPairs`: A vector of pairs where each pair contains a mapped number and its original index from the `nums` vector.

2. **Map Each Number**:
    - Iterate through each number in the `nums` vector.
    - For each number, initialize `mappedNum` to store its mapped value. If the number is `0`, set `mappedNum` to `mapping[0]`.
    - Use a `placeValue` variable to keep track of the place value (units, tens, hundreds, etc.).
    - Decompose the number into its individual digits, map each digit using the `mapping` vector, and construct the mapped number.

3. **Store Mapped Numbers and Indices**:
    - Store each mapped number along with its original index in the `mappedAndIndexPairs` vector.

4. **Sort the Pairs**:
    - Sort the `mappedAndIndexPairs` vector first by the mapped number and then by the original index.

5. **Extract Sorted Numbers**:
    - Create a new vector `sortedNums` to store the numbers from the `nums` vector in the order determined by the sorted pairs.
    - Iterate through the sorted pairs and append the corresponding numbers from the `nums` vector to `sortedNums`.

6. **Return Result**:
    - Return the `sortedNums` vector as the result.

# Complexity Analysis

1. **Time Complexity**:
    - Mapping Numbers: Each number is decomposed into its digits and mapped. This operation takes \(O(d)\) time per number, where \(d\) is the number of digits. Since there are \(n\) numbers, the total time for mapping is \(O(n \cdot d)\).
    - Sorting: The sorting step involves sorting \(n\) pairs, which takes \(O(n \log n)\) time.
    - Combining both steps, the overall time complexity is \(O(n \cdot d + n \log n)\). Since \(d\) is typically a small constant (for instance, at most 10 for 32-bit integers), the time complexity simplifies to \(O(n \log n)\).

2. **Space Complexity**:
    - The algorithm uses additional space for the `mappedAndIndexPairs` vector, which stores \(n\) pairs. This requires \(O(n)\) space.
    - The `sortedNums` vector also requires \(O(n)\) space to store the sorted numbers.
    - Therefore, the overall space complexity is \(O(n)\).
