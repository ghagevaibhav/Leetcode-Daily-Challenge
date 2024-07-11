# Reverse Parentheses Algorithm Explanation

## Algorithm

The algorithm uses a recursive approach to reverse substrings enclosed in parentheses. Here's how it works:

1. The main function `reverseParentheses` initializes the process by calling the helper function `solve`.

2. The `solve` function iterates through the string character by character:
   - If a closing parenthesis `)` is encountered, it reverses the current substring and returns it.
   - If an opening parenthesis `(` is encountered, it recursively calls `solve` to process the nested substring.
   - For any other character, it adds it to the current substring.

3. The recursion handles nested parentheses by processing inner pairs first, then outer pairs.

4. The final result is a string with all substrings within parentheses reversed, and the parentheses themselves removed.

## Time Complexity

- The time complexity of this algorithm is O(n^2), where n is the length of the input string.
- This is because in the worst case (deeply nested parentheses), we might need to reverse each substring multiple times.
- The `reverse` operation itself takes linear time, and in the worst case, we might need to do this for each character.

## Space Complexity

- The space complexity is O(n), where n is the length of the input string.
- This is due to the recursive calls on the call stack, which in the worst case (deeply nested parentheses) could be as deep as the length of the string.
- Additionally, we're creating new strings at each recursive call, which also contributes to the space complexity.

## Optimization Possibilities

1. To improve time complexity, we could use a stack-based approach instead of recursion.
2. To reduce space usage, we could modify the string in-place instead of creating new strings at each step.

## Edge Cases to Consider

- Empty string
- String with no parentheses
- Unbalanced parentheses
- Nested parentheses of varying depths

This algorithm handles these cases well, but proper input validation might be necessary depending on the specific requirements.
