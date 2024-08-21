# Strange Printer Algorithm

## Problem Description
Given a string `s`, you are tasked with finding the minimum number of turns the printer needs to print the entire string. The printer can only print a sequence of the same character at once.

## Algorithm

### 1. Dynamic Programming with Memoization
The problem can be solved using a dynamic programming approach with memoization. The idea is to minimize the number of turns required to print the substring `s[start...end]`.

### Steps:
1. **Base Case:** 
    - If the `start` index is greater than the `end` index, return `0` since no characters need to be printed.
    
2. **Memoization Check:**
    - Before computing the result for a substring `s[start...end]`, check if it has already been computed and stored in the memoization map. If so, return the stored result to avoid redundant calculations.

3. **Recursive Case:**
    - Assume the worst case where all characters in the current substring need to be printed independently. This is done by considering the result of printing `s[start...end-1]` and adding `1` turn for the `end` character.
    - To optimize, loop through possible partitions of the substring. For each partition, check if `s[middle] == s[end]`. If they are equal, it means you can potentially reduce the number of turns by printing the substring `s[start...middle]` first, and then the remaining part `s[middle+1...end-1]`.

4. **Store the Result:**
    - Once the minimum number of turns is calculated for the substring, store it in the memoization map for future reference.

5. **Return the Result:**
    - The final result for the entire string is obtained by applying the above steps recursively from the start to the end of the string.

## Complexity Analysis

### Time Complexity
- The time complexity is `O(n^3)` where `n` is the length of the string `s`.
  - The dynamic programming approach involves filling up a memoization table where each entry is computed by considering all possible partitions. For each partition, the comparison and recursive calls take `O(n)` time, and there are `O(n^2)` subproblems.

### Space Complexity
- The space complexity is `O(n^2)` for storing the results of all possible substrings in the memoization map.

## Summary
The algorithm efficiently reduces the problem's complexity by avoiding redundant calculations through memoization. It leverages the structure of the problem to find an optimal solution by considering possible partitions and minimizing the number of turns required to print the string.
