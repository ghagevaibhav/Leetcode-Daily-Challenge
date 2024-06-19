# Algorithm Explanation and Complexity

## Algorithm Explanation

1. **Initial Checks**:
    - First, check if it is even possible to make `m` bouquets with `k` flowers each given the number of flowers available (`n`). If `m * k > n`, return `-1` as it is impossible.

2. **Binary Search Setup**:
    - Set the initial search bounds for binary search: `l` (minimum possible day) to `r` (maximum possible day from the `bloomDay` array).

3. **Binary Search Process**:
    - While `l` is less than or equal to `r`:
        - Calculate `mid`, the middle point of the current bounds.
        - Use the helper function `isOkay(mid, bloomDay, m, k)` to check if it is possible to make `m` bouquets with `k` consecutive flowers all blooming on or before `mid` days.
        - If `isOkay` returns `true`, it means we can potentially reduce the number of days, so update `ans` to `mid` and adjust the search range by setting `r = mid - 1`.
        - If `isOkay` returns `false`, it means `mid` days is too early, so adjust the search range by setting `l = mid + 1`.

4. **Helper Function (`isOkay`)**:
    - This function iterates through the `bloomDay` array and counts consecutive flowers that are ready to bloom on or before `mid` day.
    - Each time it finds `k` consecutive flowers, it counts one bouquet and resets the counter for consecutive flowers.
    - Finally, it returns `true` if it can make at least `m` bouquets, otherwise `false`.

## Complexity Explanation

- **Time Complexity**:
    - The binary search runs in \(O(\log(\text{max bloom day}))\) where max bloom day is the largest value in `bloomDay`.
    - For each iteration of binary search, the `isOkay` function runs in \(O(n)\), where \(n\) is the size of the `bloomDay` array.
    - Therefore, the overall time complexity is \(O(n \log(\text{max bloom day}))\).

- **Space Complexity**:
    - The space complexity is \(O(1)\) as we are using a constant amount of extra space.

## Step-by-Step Example

Let's walk through an example to understand the algorithm better.

### Example
- **Input**: `bloomDay = [1, 10, 3, 10, 2]`, `m = 3`, `k = 1`
- **Output**: `3`

### Steps:

1. **Initial Check**:
    - \( m \times k = 3 \times 1 = 3 \)
    - \( n = 5 \)
    - Since \( 3 \leq 5 \), it is possible to proceed.

2. **Binary Search Setup**:
    - \( l = 1 \) (minimum possible day)
    - \( r = 10 \) (maximum possible day)
    - \( ans = -1 \) (to store the result)

3. **Binary Search Process**:
    - **First Iteration**:
        - \( mid = (1 + 10) / 2 = 5 \)
        - Call `isOkay(5, bloomDay, m, k)`:
            - Iterating through `bloomDay`:
                - 1 <= 5: `consec = 1` → `num = 1` (reset `consec`)
                - 10 > 5: `consec = 0`
                - 3 <= 5: `consec = 1` → `num = 2` (reset `consec`)
                - 10 > 5: `consec = 0`
                - 2 <= 5: `consec = 1` → `num = 3` (reset `consec`)
            - `num = 3`, which is >= `m`, so return `true`
        - Update `ans = 5`, set \( r = 4 \)

    - **Second Iteration**:
        - \( mid = (1 + 4) / 2 = 2 \)
        - Call `isOkay(2, bloomDay, m, k)`:
            - Iterating through `bloomDay`:
                - 1 <= 2: `consec = 1` → `num = 1` (reset `consec`)
                - 10 > 2: `consec = 0`
                - 3 > 2: `consec = 0`
                - 10 > 2: `consec = 0`
                - 2 <= 2: `consec = 1` → `num = 2` (reset `consec`)
            - `num = 2`, which is < `m`, so return `false`
        - Set \( l = 3 \)

    - **Third Iteration**:
        - \( mid = (3 + 4) / 2 = 3 \)
        - Call `isOkay(3, bloomDay, m, k)`:
            - Iterating through `bloomDay`:
                - 1 <= 3: `consec = 1` → `num = 1` (reset `consec`)
                - 10 > 3: `consec = 0`
                - 3 <= 3: `consec = 1` → `num = 2` (reset `consec`)
                - 10 > 3: `consec = 0`
                - 2 <= 3: `consec = 1` → `num = 3` (reset `consec`)
            - `num = 3`, which is >= `m`, so return `true`
        - Update `ans = 3`, set \( r = 2 \)

4. **End of Binary Search**:
    - Binary search ends when \( l > r \)
    - The result is `ans = 3`, which is the minimum number of days needed to make 3 bouquets each with 1 flower.
