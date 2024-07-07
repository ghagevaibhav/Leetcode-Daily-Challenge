# Algorithm Explanation for `numWaterBottles`

## Algorithm
1. **Initialize Total Bottles**: 
   - Start with the initial number of bottles (`numBottles`).
   - Initialize `totalBottles` to `numBottles`.

2. **Exchange Loop**:
   - While the number of empty bottles (`numBottles`) is greater than or equal to the number required for an exchange (`numExchange`):
     - Calculate the number of new bottles obtained by dividing `numBottles` by `numExchange`.
     - Add the number of new bottles to `totalBottles`.
     - Update `numBottles` to be the sum of new bottles obtained and the remainder bottles that couldn't be exchanged.

3. **Return Total Bottles**:
   - Return the `totalBottles` as the result, which is the total number of bottles that can be drunk.

## Complexity Analysis
### Time Complexity
- **O(log(numBottles))**:
  - In each iteration of the loop, `numBottles` is reduced approximately by a factor of `numExchange` due to the integer division.
  - The number of iterations required for `numBottles` to become less than `numExchange` is proportional to the logarithm of the initial number of bottles.
  - Therefore, the time complexity is `O(log(numBottles))`.

### Space Complexity
- **O(1)**:
  - The algorithm uses a constant amount of extra space, regardless of the input size.
  - Variables `totalBottles`, `newBottles`, and `numBottles` take up constant space.
  - Therefore, the space complexity is `O(1)`.
