# Algorithm and Complexity Explanation

## Algorithm Explanation

1. **Initialize a counter**: Start by initializing a variable `count` to 0. This variable will be used to keep track of the number of consecutive odd numbers encountered in the array.

2. **Iterate through the array**: Loop through each element in the input array `arr` using a for-each loop.

3. **Check if the number is odd**: For each number in the array, check if it is odd by using the modulus operator (`num % 2 != 0`).

4. **Increment the counter if odd**:
   - If the number is odd, increment the `count` by 1.
   - Check if the `count` has reached 3. If yes, return `true` immediately, as we have found three consecutive odd numbers.

5. **Reset the counter if even**:
   - If the number is even, reset the `count` to 0, as the sequence of consecutive odd numbers has been broken.

6. **Return the result**: If the loop completes without finding three consecutive odd numbers, return `false`.

## Complexity Explanation

- **Time Complexity**: The time complexity of this function is \(O(n)\), where \(n\) is the number of elements in the input array `arr`. This is because the function iterates through each element of the array exactly once.

- **Space Complexity**: The space complexity of this function is \(O(1)\). This is because the function uses a constant amount of additional space (the `count` variable) regardless of the size of the input array.
