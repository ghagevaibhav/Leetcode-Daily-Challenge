# Algorithm and Complexity Explanation

## Algorithm

1. **Initialization**:
   - Start by initializing a mask with all bits set to `1`. This can be done by using the bitwise NOT operator (`~`) on `0`. 
   - For example, `unsigned mask = ~0;` will result in `mask` being `0xFFFFFFFF` (for a 32-bit system).

2. **Adjusting the Mask**:
   - Use a while loop to shift the mask left until it is just larger than the number (`num`). The condition in the loop checks if the mask has a `1` in the same position as the most significant `1` bit in `num`.
   - During each iteration, the mask is shifted left by one bit using `mask = mask << 1;`.

3. **Finding the Complement**:
   - After adjusting the mask, the complement of `num` can be found by flipping all bits of `num` using the bitwise NOT operator (`~num`).
   - The mask is then used in an XOR operation with the complement of `num` to zero out any bits in the mask that extend beyond the length of `num`. The XOR operation effectively zeroes out those bits, leaving the true complement of `num`.

4. **Return the Result**:
   - The final result is returned, which is the complement of the given number `num` within the bounds of its significant bits.

## Time Complexity

- The time complexity of this algorithm is **O(1)** (constant time). 
- The reason is that the number of iterations in the loop is proportional to the number of bits in an integer, which is a fixed constant (e.g., 32 or 64 bits) for any modern processor. Hence, it does not scale with the size of the input number.

## Space Complexity

- The space complexity of this algorithm is **O(1)** (constant space).
- Only a few integer variables are used (such as `mask`), and the space required does not depend on the input size.
