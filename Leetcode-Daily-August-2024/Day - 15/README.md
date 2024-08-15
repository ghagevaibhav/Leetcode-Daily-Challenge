# Algorithm: Lemonade Change

## Problem Statement
You are given an array `bills` where `bills[i]` represents the bill the `i`-th customer gives you at a lemonade stand. Each customer will buy one lemonade, which costs $5. You need to provide change to each customer. Initially, you have no money. Return `true` if you can provide every customer with the correct change; otherwise, return `false`.

### Steps to Solve:

1. **Initialize Counters**:
   - Use two counters: `fives` to count the number of $5 bills and `tens` to count the number of $10 bills.

2. **Process Each Bill**:
   - Iterate through each bill in the `bills` array:
     - **$5 Bill**:
       - Simply increase the `fives` counter since no change is required.
     - **$10 Bill**:
       - If a $5 bill is available, decrement the `fives` counter and increment the `tens` counter because $5 change is required.
       - If no $5 bill is available, return `false` since change cannot be given.
     - **$20 Bill**:
       - Prioritize giving change with one $10 bill and one $5 bill (decrement both `tens` and `fives` counters) if possible.
       - If not possible, attempt to give change with three $5 bills (decrement `fives` by 3).
       - If neither option is possible, return `false` as change cannot be given.

3. **Final Return**:
   - If the loop completes without returning `false`, all customers were given the correct change, so return `true`.

### Complexity Analysis

- **Time Complexity**: 
  - The algorithm processes each bill in the `bills` array exactly once.
  - The time complexity is `O(n)`, where `n` is the number of elements in the `bills` array.

- **Space Complexity**:
  - The algorithm uses a constant amount of extra space for the two counters (`fives` and `tens`).
  - Therefore, the space complexity is `O(1)`.

This algorithm efficiently determines whether the correct change can be provided to each customer at the lemonade stand.

