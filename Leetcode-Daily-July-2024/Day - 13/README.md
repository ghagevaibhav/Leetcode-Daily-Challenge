# Survived Robots Healths Algorithm

## Algorithm Explanation

1. **Initialization**:
   - Create a vector `ids` to store the original indices of the robots.
   - Populate `ids` with indices from 0 to `n-1`.

2. **Sorting**:
   - Sort the `ids` vector based on the positions of the robots using a custom lambda function.

3. **Processing Directions**:
   - Initialize an empty stack `st` to keep track of robots moving to the right ('R').
   - Iterate over each robot in the sorted `ids`:
     - If the robot is moving to the right ('R'), push its index onto the stack.
     - If the robot is moving to the left ('L'), process collisions with robots moving to the right:
       - While the stack is not empty and the current robot's health is greater than zero:
         - Compare the health of the current robot with the health of the robot at the top of the stack.
         - Depending on the comparison, update the healths and manage the stack accordingly:
           - If the current robot's health is greater, decrement its health, set the health of the robot in the stack to zero, and pop the stack.
           - If the current robot's health is less, set its health to zero and decrement the health of the robot in the stack.
           - If the healths are equal, set both healths to zero and pop the stack.

4. **Collecting Surviving Robots**:
   - Create a vector `ans` to store the healths of robots that survived.
   - Iterate over the original healths vector and collect the healths of robots that are greater than zero.

5. **Return Result**:
   - Return the vector `ans` containing the healths of the surviving robots.

## Complexity Analysis

### Time Complexity
- **Sorting**: The sorting step takes \(O(n \log n)\) time, where \(n\) is the number of robots.
- **Processing Directions**: Each robot is pushed and popped from the stack at most once, leading to a linear time complexity, \(O(n)\).
- **Collecting Surviving Robots**: Iterating over the healths vector to collect surviving robots also takes \(O(n)\) time.

Overall, the time complexity of the algorithm is dominated by the sorting step, resulting in **\(O(n \log n)\)**.

### Space Complexity
- The additional space used includes:
  - The `ids` vector of size \(n\).
  - The stack `st`, which in the worst case can store all \(n\) robots.
  - The result vector `ans`, which in the worst case can store all \(n\) robots.

Thus, the space complexity is **\(O(n)\)**.
