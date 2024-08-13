# `combinationSum2` Algorithm and Complexity

## Problem Statement
Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`. Each number in `candidates` may only be used once in the combination.

## Algorithm Explanation

1. **Sort the Candidates**:
   - First, sort the `candidates` array. Sorting helps to easily skip duplicates and handle the combinations in a systematic way.
   - Sorting also allows us to break early from the loop when a candidate exceeds the current target.

2. **Backtracking Approach**:
   - Use a helper function that will explore all possible combinations.
   - The helper function is recursive and takes the following parameters:
     - `index`: The current position in the `candidates` array.
     - `target`: The remaining target sum.
     - `candidates`: The original list of candidate numbers.
     - `ans`: The list to store all valid combinations.
     - `ds`: A temporary list that stores the current combination.

3. **Base Case**:
   - If the `target` becomes 0, it means the current combination (`ds`) sums up to the original target. This combination is added to the `ans` list.

4. **Iterating Through Candidates**:
   - Loop through the `candidates` starting from `index`.
   - **Early Termination**: If a candidate exceeds the current `target`, break the loop as no further candidates will fit.
   - **Skipping Duplicates**: If the current candidate is the same as the previous one (and it's not the first candidate in the current call), skip it to avoid duplicate combinations.
   - Add the current candidate to the temporary combination list (`ds`), then recursively call the helper function with the next index and the updated target.

5. **Backtracking**:
   - After the recursive call, remove the last added candidate from `ds` to explore other combinations.

6. **Return the Result**:
   - The main function `combinationSum2` initializes the process by calling the helper function and returns the list of all valid combinations.

## Time Complexity

The time complexity of this algorithm is **O(2^n \* n)**, where `n` is the number of candidates.

- **O(2^n)**: The number of combinations can be 2^n in the worst case because for each element, you have two choices: include it or exclude it.
- **O(n)**: For each valid combination, it takes O(n) time to copy it into the result list.

## Space Complexity

The space complexity is **O(n)** for the recursion stack, where `n` is the depth of the recursion. Additionally, the space required for storing the results depends on the number of valid combinations and the size of each combination.
