# Algorithm Explanation and Complexity Analysis

## Algorithm Explanation

1. **Initial Check**:
   - If the list is empty (`head == NULL`) or has only one node (`head->next == NULL`), return the head as it is. 
   - This handles edge cases where no merging is needed.

2. **Initialization**:
   - Two pointers `prev` and `curr` are initialized. 
   - `prev` points to the head, and `curr` points to the second node.

3. **Traversal**:
   - The list is traversed using a while loop until `curr` reaches the last node.
   - **If `curr->val` is not zero**:
     - Add `curr->val` to `prev->val`.
     - Move `curr` to the next node.
   - **If `curr->val` is zero**:
     - Set `prev->next` to `curr`.
     - Move `prev` to `curr`.
     - Move `curr` to the next node.

4. **Termination**:
   - After the loop, set `prev->next` to `nullptr` to mark the end of the modified list.

5. **Return**:
   - Return the modified head of the list.

This algorithm effectively merges nodes of the linked list by summing the values of nodes between zero-valued nodes.

## Complexity Analysis

### Time Complexity
- The algorithm traverses each node of the linked list exactly once.
- Therefore, the time complexity is **O(n)**, where `n` is the number of nodes in the linked list.

### Space Complexity
- The algorithm uses a constant amount of extra space for pointers `prev` and `curr`.
- Therefore, the space complexity is **O(1)**.

In summary, the algorithm runs in linear time and constant space.
