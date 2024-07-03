# Algorithm Explanation and Complexity

## Algorithm Explanation

The goal of the algorithm is to find the minimum difference between the largest and smallest elements in the array after performing at most three changes (removals) to the array. Here are the steps the algorithm follows:

1. **Initial Check**:
   - If the size of the array `n` is 4 or less, return 0 immediately. This is because we can remove all elements, making the difference zero.

2. **Sorting**:
   - Sort the array. This step is essential because it allows us to consider removing the largest and smallest elements systematically.

3. **Calculate Possible Minimum Differences**:
   - After sorting, calculate the possible minimum differences by considering removing up to three elements from either end of the array. The four possible scenarios are:
     1. Removing the three smallest elements.
     2. Removing the two smallest and one largest element.
     3. Removing one smallest and two largest elements.
     4. Removing the three largest elements.

4. **Return the Minimum Difference**:
   - Compute the minimum difference for each of the above scenarios and return the smallest one.

## Complexity Analysis

### Time Complexity

1. **Sorting**:
   - The time complexity of sorting the array is `O(n log n)`, where `n` is the size of the array.

2. **Calculating Minimum Differences**:
   - After sorting, calculating the four possible differences and finding the minimum among them is done in constant time, `O(1)`.

Therefore, the overall time complexity of the algorithm is dominated by the sorting step, which is `O(n log n)`.

### Space Complexity

The space complexity of the algorithm is `O(1)` if the sorting operation is done in-place. No additional space is required apart from the input array and a few extra variables for storing the results.
