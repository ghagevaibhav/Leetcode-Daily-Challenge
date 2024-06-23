# Longest Subarray with Limit Constraint

## Algorithm

1. **Initialization**:
    - Create variables `i` and `j` for the sliding window's start and end, respectively. Both are initially set to 0.
    - Initialize `ans` to 0 to store the length of the longest valid subarray.
    - Use two deques, `minq` and `maxq`, to maintain indices of elements in non-decreasing and non-increasing order, respectively.

2. **Sliding Window Expansion**:
    - Iterate over the array with the right pointer `j` from 0 to `n-1`:
        1. For the current element `nums[j]`:
            - **Update `minq`**:
                - Remove elements from the back of `minq` while `nums[minq.back()]` is greater than or equal to `nums[j]`.
                - Add the current index `j` to the back of `minq`.
            - **Update `maxq`**:
                - Remove elements from the back of `maxq` while `nums[maxq.back()]` is less than or equal to `nums[j]`.
                - Add the current index `j` to the back of `maxq`.

        2. **Check Window Validity**:
            - Calculate the minimum and maximum values in the current window using `nums[minq.front()]` and `nums[maxq.front()]`.
            - If the difference (`maxi - mini`) exceeds the given `limit`, increment the left pointer `i` to reduce the window size:
                - Remove the front element of `minq` if `minq.front()` is less than `i`.
                - Remove the front element of `maxq` if `maxq.front()` is less than `i`.

        3. **Update Answer**:
            - If the window is valid, update `ans` with the maximum length of the valid subarray found so far (`j - i + 1`).

3. **Return the Result**:
    - After processing all elements, return `ans`.

## Complexity Analysis

### Time Complexity
- The algorithm processes each element of the array once with the right pointer `j` and adjusts the window size with the left pointer `i`.
- Each element is added and removed from the deques at most once.
- Thus, the overall time complexity is **O(n)**, where `n` is the length of the input array.

### Space Complexity
- The space complexity is determined by the space used for the deques.
- In the worst case, each deque can contain up to `n` elements.
- Therefore, the space complexity is **O(n)**.
